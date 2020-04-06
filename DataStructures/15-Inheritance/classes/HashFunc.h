/**********************************************
* File: HashFunc.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Contains Hash Functions for different data types 
**********************************************/

#ifndef HASHFUNC_H
#define HASHFUNC_H

#include <string>

/********************************************
* Function Name  : HashFunc
* Pre-conditions : int Value 
* Post-conditions: int
* 
* Returns a Hash Value for integer 
********************************************/
int HashFunc( int Value ){
	
	return Value;
}


/********************************************
* Function Name  : HashFunc
* Pre-conditions : int Value 
* Post-conditions: int
* 
* Second Hash Function for Double Hashing 
********************************************/
int HashFunc2( int Value ){
	
	return 3 - (Value % 3);
	
}


/********************************************
* Function Name  : HashFunc
* Pre-conditions : const std::string Value 
* Post-conditions: int
* 
* Returns the size of the string
********************************************/
int HashFunc( const std::string Value ){
	
	return (int)Value.size();
}



/********************************************
* Function Name  : HashFunc
* Pre-conditions : int Value 
* Post-conditions: int
* 
* Second Hash Function for Double Hashing 
********************************************/
int HashFunc2( const std::string Value){
	
	return 5 - ((int)Value.size() % 5);
	
}


#endif

