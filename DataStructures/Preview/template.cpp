/**********************************************
* File: template.cpp
* Author: Nolan Downey
* Email: ndowney@nd.edu
* 
* Implementation File for Template class T
**********************************************/

#include "template.h"

/********************************************
* Function Name  : larger
* Pre-conditions : T a, T b
* Post-conditions: T
* 
* Function that returns the larger of two values
********************************************/
template<class T>
T larger(T a, T b) {
	if (a > b)
		return a;

	return b;
}

/********************************************
* Function Name  : smaller
* Pre-conditions : T a, T b
* Post-conditions: T
* 
* Function that returns the smaller of two values
********************************************/
template<class T>
T smaller(T a, T b) {
	if (a > b)
		return b;

	return a;
}



