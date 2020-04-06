/**********************************************
* File: palindrome.cpp
* Author: Nolan Downey
* Email: ndowney@nd.edu
* 
* Program to check if an array is a palindrome
**********************************************/

#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
#include <cstdlib>		// exitr

/********************************************
* Function Name  : checkInputs
* Pre-conditions : const long unsigned int argc, char** argv
* Post-conditions: unsigned int
*
* Checks the inputs for a valid amount, and returns the length of argv[1]
********************************************/
unsigned int checkInputs(const unsigned int argc, char** argv){

	// Need exactly 2 inputs
	if(argc != 2){

		std::cout << "Need exactly 2 inputs" << (char)0x0A;
		exit(-1);

	}

	// Now, get the length of argv[1]
	unsigned int len = 0;
	for( ; argv[1][len] != '\0'; len++)
		;

	return len;

}

/********************************************
* Function Name  : palindrome
* Pre-conditions : char arr[], unsigned int len, unsigned int first, unsigned int last
* Post-conditions: unsigned int
* 
* Function to check if the array from the command line is a palindrome
* Returns true if yes, false if no
********************************************/
//Palindrome Checker (returns 1 if palindrome, 0 if not)
bool palindrome (char arr[], unsigned int first, unsigned int last) {

	//Base Case
	if(first >= last) {
		return true;
	}

	
	return( arr[first] == arr[last] ) and palindrome(arr, first + 1, last - 1);

}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*
* This is the main driver function
********************************************/
int main(int argc, char** argv){

	// Check the inputs, allocate array and length
	unsigned int arrLen = checkInputs(argc, argv);

	//Checks Palindrome
	//Prints "True" if paldindrome, and "False" if not
	if (palindrome(argv[1], 0, arrLen - 1))

		std::cout << "True" << std::endl;
	else

		std::cout << "False" << std::endl;

	// Print the array to the user
	std::cout << argv[1] << " has a length of " << arrLen << std::endl;

	return 0;
}
