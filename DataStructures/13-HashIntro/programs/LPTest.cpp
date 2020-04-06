#include "../classes/LinearProbe.h"

template<class Key, class Value>
void printValue(const HashTable<Key, Value>& printHash, Key theValue){
	
	std::cout << theValue << " is the key for " << printHash[theValue] << std::endl;
	
}

int main(){
	
	const unsigned int hashSize = 7;
	
	HashTable<int, std::string> theHash(hashSize);
	
	// From the slides from Lecture 12
	// 76, 93, 40, 47, 10, and 55
	// To get the same results, comment out rehash
	// in the insert method in LinearProbe.h
	theHash.insert( {76, "First"} );
	theHash.insert( {93, "Second"} );
	theHash.insert( {40, "Third"} );
	theHash.insert( {47, "Fourth"} );
	theHash.insert( {10, "Fifth"} );
	theHash.insert( {55, "Sixth"} );
	
	// Print the value at the location
	printValue(theHash, 76);
	
	// Print all the values and buckets in theHash 
	std::cout << theHash << std::endl;
	
	// Remove an element
	theHash.remove(47);
	
	// Print the Hash Again
	std::cout << theHash << std::endl;
	
	// Initialize the HashTable with flipped key and value
	HashTable<std::string, int> ageHash(5);
	ageHash.insert( {"Matthew", 38 } );
	ageHash.insert( {"James", 35 } );
	ageHash.insert( {"Grace", 14 } );
	ageHash.insert( {"Eirinn", 5 } );
	ageHash.insert( {"Maggie", 27 } );
	
	std::cout << "Matthew's age is " << ageHash["Matthew"] << std::endl;
	std::cout << "Eirinn's age is " << ageHash["Eirinn"] << std::endl;
	std::cout << "James's age is " << ageHash["James"] << std::endl;
	std::cout << "Grace's age is " << ageHash["Grace"] << std::endl;
	
	// Next, we print out using printValue to demonstrate successful const operator[]
	printValue(ageHash, std::string("Maggie"));
	
	// Print all the values and buckets in ageHash 
	std::cout << ageHash << std::endl;
	
	if(!ageHash.contains("BadValue")){
		
		std::cout << "The Hash does not contain 'BadValue'\n";
		std::cout << "We will call ageHash[\"BadValue\"] anyway to show we have protected the operator[].\n";
		std::cout << "The std::unordered_map does NOT have this protection\n\n";
		std::cout << ageHash["BadValue"] << std::endl;
	}
	
	return 0;
}
