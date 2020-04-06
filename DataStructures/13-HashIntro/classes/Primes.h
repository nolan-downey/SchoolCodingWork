/**********************************************
* File: Primes.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Includes two functions to calculate Primes 
**********************************************/
#ifndef PRIMES_H
#define PRIMES_H


/********************************************
* Function Name  : isPrime
* Pre-conditions : long unsigned int n 
* Post-conditions: bool
* 
* Returns true if the number is a prime 
********************************************/
bool isPrime( long unsigned int n ){
	
	if( n == 2 || n == 3){
		return true;
	}
	
	if( n == 1 || n % 2 == 0 ){
		return false;
	}
	
	for( long unsigned int i = 3; i * i <= n; i += 2 ){
		if( n % i == 0 ){
			return false;
		}
	}
	
	return true;
}


/********************************************
* Function Name  : nextPrime
* Pre-conditions : long unsigned int n 
* Post-conditions: long unsigned int
* 
* Returns the next largest prime number 
********************************************/
long unsigned int nextPrime( long unsigned int n ){
	
	// If n is even, make it odd
	if( n % 2 == 0 ){
		++n;
	}
	
	for( ; !isPrime(n); n+=2 ){
		// Do Nothing
	}
	
	return n;
}


#endif
