#ifndef LINEARPROBE_H
#define LINEARPROBE_H

#include <vector>
#include <iostream>
#include "HashFunc.h"
#include "Primes.h"

enum EntryState{ ACTIVE, EMPTY, DELETED};

const int STEPSIZE = 1;
const int COLLISION_RATE = 2;

template<class Key, class Value>
class HashTable {

private:

  struct HashEntry{

    Key theKey;
    Value element;
    EntryState state;

    HashEntry() : key(), element(), state( EMPTY ) {}

    HashEntry( std::pair<const Key, Value> thePair, EntryState i = EMPTY )
      : key(thePair.first), element(thePair.second), state(i) {}
  };

  unsigned int numHash;
  std::vector<HashEntry> array;

  bool isActive( unsigned int currentPos ) const {

    return array[ currentPos].state == ACTIVE;

  }

  long unsigned int capacity() const {

    return array.capacity();

  }

  unsigned int findPos(const Key theKey) const {

    unsigned int currentPos;
    unsigned int iter = 0;

    do {

      currentPos = ( HashFunc(theKey) + iter*STEPSIZE ) % (unsigned int) capacity();
      iter++;

    }
    while(

      array.at( currentPos ).state != EMPTY
      && array.at( currentPos ).state != DELETED
      && array.at( currentPos ).state != theKey
      && iter < capacity()
    );

    if(array.at( currentPos ).state == ACTIVE
      && array.at( currentPos ).key != theKey ) {

          return (unsigned int)capacity();

      }

    return currentPos;

  }

  void rehash() {

    // Copy the element
    std::vector<HashEntry> oldArray = array;

    // Clear the original array
    array.clear()

    //Resize original array
    array.resize( nextPrime( COLLISION_RATE * oldArray.size() ) );

    //Rehash the old elements
    numHash = 0;
    for (HashEntry& entry : oldArray ) {

      if(entry.state == ACTIVE) {

        insert( ( entry.key, entry.element) );
        
      }
    }
  }

public:

  HashTable (const unsigned int i = 0) : numHash(0) : array() {

    array.resize( nextPrime(size) );
  }

}


#endif
