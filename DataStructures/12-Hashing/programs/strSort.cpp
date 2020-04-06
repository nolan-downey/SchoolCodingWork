/**********************************************
* File: strSort.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains using a Counting Sort algorithm
* to sort a std::string and return a call by reference
**********************************************/
#include <iostream>			// Output Stream
#include <string>			// String
#include <unordered_map>	// Hash Table
#include <cstdlib>			// malloc
#include <sstream>			// std::stringstream

const unsigned int ASCII = 128;

/********************************************
* Function Name  : getArgv1Val
* Pre-conditions : int argc, char** argv
* Post-conditions: std::string
* 
* Returns argv[1] as an std::string if valid inputs
********************************************/
std::string getArgv1Val(int argc, char** argv){
	
	if(argc != 2){
		std::cout << "Incorrect number of inputs" << std::endl;
		exit(-1);
	}
	
	// stringstream used for the conversion initialized with the contents of argv[1]
	std::string stringVal;
	std::stringstream convert(argv[1]);

	//give the value to factNum using the characters in the string
	convert >> stringVal;
	
	return stringVal;
	
}

/********************************************
* Function Name  : sortStr
* Pre-conditions : std::string& strSort
* Post-conditions: void
* 
* This function checks the char* to see if it contains any
* duplicate chars. If all are unique, returns true.
* Otherwise, returns false 
********************************************/
void sortStr(std::string& strSort){
	
	// Allocate an array for all 128 ASCII Values
	unsigned int* asciiVals = new unsigned int[ASCII];
	
	for(long unsigned int iter = 0; iter < strSort.size(); iter++){
		
			asciiVals[ (unsigned int)strSort[iter] ]++;
	}
	
	// Clear strSort
	strSort.clear();
	
	// Iterate through all 128 potential ASCII values 
	for(long unsigned int iter = 0; iter < ASCII; iter++){
		
			// Emit the values from the array 
			for(long unsigned int jter = 0; jter < asciiVals[iter]; jter++){
				
				// Use the += operator to add to the std::string 
				strSort += (char)iter;
			}
	}	
	
	
	
}


/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
int main(int argc, char** argv){
	
		std::string sortString = getArgv1Val(argc, argv);
		
		std::cout << "Initial String: " << sortString << (char)012;
		
		sortStr(sortString);
		
		std::cout << "Initial String: " << sortString << (char)0x0A;
		
		return 0;
}
