#ifndef LINEARPROBE_H
#define LINEARPROBE_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "HashFunc.h"
#include "Primes.h"

enum EntryState { ACTIVE, EMPTY, DELETED };

const int STEPSIZE = 1;
const int COLLISION_RATE = 2;

template<class Key, class Value>
class HashTable{

	private:

		struct HashEntry{

			Key key;
			Value element;
			EntryState state;

			HashEntry() : key(), element(), state( EMPTY ) {}

			HashEntry( std::pair<const Key, Value> thePair, EntryState i = EMPTY )
				: key(thePair.first), element(thePair.second), state(i) {}

		};

		unsigned int numHash;			// # of Elements Hashed
		std::vector<HashEntry> array;	// Dynamic Array containing Hash Entries

		bool isActive( unsigned int currentPos ) const {

			return array[ currentPos ].state == ACTIVE;

		}


		long unsigned int capacity() const{

			return array.capacity();
		}


		unsigned int findPos(const Key theKey) const{

			unsigned int currentPos;
			unsigned int iter = 0;

			do{
				// Hash Function determines current position
				currentPos = (HashFunc(theKey) + iter*STEPSIZE) % (unsigned int)capacity();
				++iter;
			}
			while(
				array.at( currentPos ).state != EMPTY
				&& array.at( currentPos ).state != DELETED
				&& array.at( currentPos ).key != theKey
				&& iter < capacity()
			);

			// Return capacity if the current value isn't the key. For safety
			if(array.at( currentPos ).state == ACTIVE
				&& array.at( currentPos ).key != theKey ){

					return (unsigned int)capacity();

				}

			return currentPos;

		}


		void rehash(){

			// Copy the element
			std::vector<HashEntry> oldArray = array;

			// Clear the original array
			array.clear();

			// Resize the array
			array.resize( nextPrime( COLLISION_RATE *oldArray.size() ) );

			// Rehash the old elements
			numHash = 0;
			for( HashEntry & entry : oldArray ){

				if(entry.state == ACTIVE){
					insert( { entry.key, entry.element } );
				}
			}
		}


	public:

		HashTable(const unsigned int size = 0) : numHash(0), array(){

			array.resize( nextPrime(size) );

		}


		bool insert( const std::pair<const Key, Value> insertPair ){

			// Student Code Goes Here
			unsigned int currentPos = findPos( insertPair.first );

			if ( isActive(currentPos) ) {
					return false;
			}

			++numHash;

			if( numHash > capacity() / 2 ) {

					rehash();

					currentPos = findPos( insertPair.first );

			}

			HashEntry theEntry( insertPair, ACTIVE );
			array.at( currentPos ) = theEntry;

			return true;

		}


		bool remove( const Key& theKey ){

			// Student Code Goes Here
			unsigned int currentPos = findPos( theKey );

			if( !isActive( currentPos ) ) {
				return false;
			}

			//Lazy Deletion
			array.at( currentPos ).state = DELETED;

			numHash--;

			return true;
		}


		bool contains(const Key theKey){

			// Student Code Goes Here
			unsigned int currentPos = findPos( theKey );

			if( currentPos == capacity() ) {
				return false;
			}

			HashEntry temp = array.at( currentPos );

			return temp.key == theKey && temp.state == ACTIVE;

		}


		Value& operator[](const Key theKey){

			// Student Code Goes Here
			HashEntry temp = array.at( findPos(theKey) );

			if(temp.key != theKey || temp.state != ACTIVE) {

					throw std::out_of_range("Hash does not contain requested key.");

			}

			return array.at(findPos(theKey)).element;

		}


		const Value& operator[](const Key theKey) const{

			HashEntry temp = array.at( findPos(theKey) );

			// Used to provide std::out_of_range of key does not exist
			if(temp.key != theKey || temp.state != ACTIVE){

				// Will go out of range here
				throw std::out_of_range("HashTable does not contain the requested key");

			}

			// Cannot use temp since it has local scope
			return array.at( findPos(theKey) ).element;

		}


		friend std::ostream& operator<<(std::ostream& output, const HashTable<Key,Value>& hash){

			output << "# of Hashed Elements: " << hash.numHash << " ";
			output << "Hash Capacity: " << hash.array.capacity() << std::endl;

			for(unsigned int iter = 0 ; iter < hash.array.capacity(); ++iter){

				output << "{"<< iter << ", ";

				if(hash.array[ iter ].state == ACTIVE){
					output << "ACTIVE, " << hash.array[iter].key << ", " << hash.array[iter].element;
				}
				else if(hash.array[ iter ].state == EMPTY){
					output << "EMPTY, ";
				}
				else{
					output << "DELETED, " << hash.array[iter].key << ", " << hash.array[iter].element;
				}

				output << "}";

				std::cout << std::endl;
			}

			return output;
		}

};

#endif
