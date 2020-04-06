#ifndef DOUBLEHASH_H
#define DOUBLEHASH_H

#include "LinearProbe.h"

// Students write inherited class declaration
template< class Key, class Value >
class DoubleHash : public HashTable<Key, Value>
{

	private:

		// Students write polymorphic findPos finctuon
		unsigned int findPos(const Key theKey) const{

			unsigned int currentPos;
			unsigned int iter = 1;

			do{
				// Hash Function determines current position
				unsigned int hash1 = HashFunc(theKey) % (unsigned int)this->capacity();
				unsigned int hash2 = iter*HashFunc2(theKey);
				currentPos = (hash1+hash2) % (unsigned int)this->capacity();
				++iter;
			}
			while(
				this->array.at( currentPos ).state != EMPTY
				&& this->array.at( currentPos ).state != DELETED
				&& this->array.at( currentPos ).key != theKey
				&& iter < this->capacity()
			);

			// Return capacity if the current value isn't the key. For safety
			if(this->array.at( currentPos ).state == ACTIVE
				&& this->array.at( currentPos ).key != theKey ){

					return (unsigned int)this->capacity();

				}

			return currentPos;

		}

	public:

		// Students write inherited class constructor
		DoubleHash(const unsigned int size = 0) : HashTable<Key, Value> (size) {}


		friend std::ostream& operator<<(std::ostream& output, const DoubleHash<Key,Value>& hash){

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
