/**********************************************
* File: sepChain.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of STL C++ Hash Map
**********************************************/
#include <unordered_map>
#include <iterator>
#include <vector>
#include <string>
#include <iostream>

const int numBuckets = 7;

/********************************************
* Function Name  : HashFunc
* Pre-conditions : int value
* Post-conditions: int
* 
* Hash Function: value % numBuckets 
********************************************/
int HashFunc(int value){
	return value % numBuckets;
}


/********************************************
* Function Name  : HashFunc
* Pre-conditions : std::string value
* Post-conditions: int
* 
* Hash Function returns size of string % numBuckets 
********************************************/
int HashFunc(std::string value){
	return (int)value.size() % numBuckets;
}


/********************************************
* Function Name  : insertVal
* Pre-conditions : std::unordered_map<int, std::vector<T> >& sepChain, T value
* Post-conditions: none
* 
* Inserts the value into a Separate Chain Hash
********************************************/
template<class T>
void insertVal(std::unordered_map<int, std::vector<T> >& sepChain, T value){
	
	// sepChain[ HashFunc(value) ] returns the vector with a call by reference
	sepChain[ HashFunc(value) ].push_back(value);
	
}


/********************************************
* Function Name  : printHash
* Pre-conditions : const std::unordered_map<int, std::vector<T> >& sepChain
* Post-conditions: none
* 
* Prints all the elements in the Hash 
* CONTAINS DELIBERATE COMPILER ERROR AT LINE 69
* std::unordered_map does not have a const operator[], so this 
* will not compile. We made our own const operator[] so this could work
* LPTest.cpp has a function that calls a const HashTable by reference 
* and successfully compiles
********************************************/
template<class T>
void printHash(const std::unordered_map<int, std::vector<T> >& sepChain){

	// Iterating through all buckets
	for(int i = 0; i < numBuckets; i++){
	
		std::cout << i << ": ";
	
		/* sepChain[numBuckets] gives the vector to iterate through */
		for( T& curr : sepChain[i]){
			
			std::cout << curr << " ";
		}
		
		std::cout << std::endl;
	}
	
}

/********************************************
* Function Name  : main
* Pre-conditions :
* Post-conditions: int
*
* Main driver function. Solution  
********************************************/
int main(){

	std::unordered_map<int, std::vector<int> > sepChain;
	
	/* Initialize List */
	for(int i = 0; i < numBuckets; i++){
		std::vector<int> temp;
		sepChain.insert( {i, temp} );
	}
	
	/* Insert 4, 13, 8, 10, 5, 15 */
	insertVal(sepChain, 4);
	insertVal(sepChain, 13);
	insertVal(sepChain, 8);
	insertVal(sepChain, 10);
	insertVal(sepChain, 5);
	insertVal(sepChain, 15);

	/* Print the Hash */
	printHash(sepChain);
	
	std::cout << char(10);

	std::unordered_map<int, std::vector< std::string > > separStr;
	
	/* Initialize List */
	for(int i = 0; i < numBuckets; i++){
		std::vector< std::string > temp;
		separStr.insert( {i, temp} );
	}
	
	/* Insert words of length 4, 13, 8, 10, 5, 15 */
	insertVal(separStr, std::string("data"));
	insertVal(separStr, std::string("enlightenment"));
	insertVal(separStr, std::string("morrison"));
	insertVal(separStr, std::string("structures"));
	insertVal(separStr, std::string("pizza"));
	insertVal(separStr, std::string("rumpelstiltskin"));

	/* Print the Hash */
	printHash(separStr);

	return 0;
}
