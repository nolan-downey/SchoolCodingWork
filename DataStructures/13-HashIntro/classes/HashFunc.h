/**********************************************
* File: HashFunc.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Contains Hash Functions for different data types 
**********************************************/

#ifndef HASHFUNC_H
#define HASHFUNC_H

/********************************************
* Function Name  : HashFunc
* Pre-conditions : int Value 
* Post-conditions: int
* 
* Returns a Hash Value for integer 
********************************************/
int HashFunc( const int Value ){
	
	return Value;
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


#endif

