/**********************************************
* File: stringRem.cpp
* Author: Nolan Downey
* Email: ndowney@nd.edu 
*
* This program is a simple test of a function to
* see if it can accurately remove duplicates
* from a string
**********************************************/

#include <iostream>
#include <string>

/********************************************
* Function Name  : removeDupes
* Pre-conditions : std::string& s
* Post-conditions: std::string
*
* This is the function that removes duplicates
* from a string  
********************************************/
void removeDupes (std::string& s) {
	for (unsigned int i = 0; i < s.size()-1; i++){
		for (unsigned int j = i+1; j < s.size(); j++ ) {
			if (s.at(i) == s.at(j)) {
				s.erase(s.begin()+j);
			}
		}
	}
}

/********************************************
* Function Name  : removeDupes
* Pre-conditions : std::string& str
* Post-conditions: none
* 
* This is the function proposed by Prof. Morrison
* His function runs on O(n) time while my solution
* runs on O(n^2) time
* However, I kept my function because my solution 
* allocates less memory, and I am not sure whether
* run time or memory is more important at this point
********************************************/
void removeDuplicates(std::string& str) {

	//Allocate a bool array for all 128
	bool* allASCII = new bool[128];

	//Set all values in the array equal to false
	for(unsigned int iter = 0; iter < 128; iter++) {

		allASCII[iter] = false;
	}

	//Used a while loop, since a for loop will continue to increment iter
	//Will skip letters. Only increment the position if NOT found
	unsigned int iter = 0;
	while (iter < str.length()) {

		//If the ASCII value is false, char has not been found
		if ( !allASCII[ (int)str.at(iter) ] ) {

			//Set it to true, and continue. Case to int for array index
			allASCII[ (int)str.at(iter) ] = true;

			//Increment since we found a unique char that stays in the array
			iter++;
		}

		//If it's true, we must remove the character
		else {
			
			//Erase a character from a string
			str.erase(str.begin() + iter);

			//Do NOT increment here
		}
	}
}



/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
*  
* Main driver for the program
********************************************/
int main(){

	std::string strTest1("adagahljASDj67SAl7");
	std::string strNoDupes("abcdABCD1234");

	// Print initial values
	std::cout << "Before Removing Duplicates\n";
	std::cout << strTest1 << char(0x0A);
	std::cout << strNoDupes << "\n\n";

	removeDupes(strTest1);
	removeDupes(strNoDupes);

	// Print final values
	std::cout << "After Removing Duplicates:" << (char)10;
	std::cout << strTest1 << std::endl;
	std::cout << strNoDupes << std::endl;

	return 0;
}
