#include <iostream>
#include <cstdlib>
#include <cstring>			// std::strcmp
#include <sstream>
#include <typeinfo>    // std::stringstream
#include "AddElements.h"

const unsigned int startVals = 2;	// Start Value Iteration

/********************************************
* Function Name  : checkInputs
* Pre-conditions : const int& argc, char** argv
* Post-conditions: none
*
* Checks the argv inputs for validilty
********************************************/
void checkInputs(const int& argc, char** argv){

	if(argc <= 2){

		std::cout << "Need 3 or more inputs" << (char)0x0A;
		exit(-1);

	}

	if( std::strcmp(argv[1], "int") != 0 &&
		std::strcmp(argv[1], "float") != 0 &&
		std::strcmp(argv[1], "double") != 0 &&
		std::strcmp(argv[1], "std::string") != 0 ){

		std::cout << "Improper type definition\n" << std::endl;
		exit(-1);

	}

}

/********************************************
* Function Name  : addAndPrint
* Pre-conditions : AddElements<T>& ae, const int& argc, char** argv
* Post-conditions: none
*
* Adds the values and prints the result
********************************************/
template <class T> void addAndPrint(AddElements<T>& ae, const int& argc, char** argv){

	for(int iter = startVals; iter < argc; iter++){

		// Convert to type
		T addVal;
		std::stringstream convert(argv[iter]);

		//give the value to factNum using the characters in the string
		if ( !(convert >> addVal) ){
			std::cout << argv[iter] << " is not a valid type value" << std::endl;
			exit(-1);
		}

		// Student Code Goes Here
		if( std::strcmp(typeid(T).name(), "Ss") == 0 ){
			ae.concatenate(addVal);
		}
		else{
			ae.addElement(addVal);
		}

	}

	// Student Code Goes Here
	std::cout << ae << std::endl;
}


/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*
* This is the main driver function for the program
********************************************/
int main(int argc, char** argv){

	// Check for valid inputs
	checkInputs(argc, argv);

	// Create Templated AddElements
	if(std::strcmp(argv[1], "int") == 0){

		// Student Code Goes Here
		AddElements<int> theElement;
		addAndPrint(theElement, argc, argv);
	}
	else if(std::strcmp(argv[1], "float") == 0){

		// Student Code Goes Here
		AddElements<float> theElement;
		addAndPrint(theElement, argc, argv);
	}
	else if(std::strcmp(argv[1], "double") == 0){

		// Student Code Goes Here
		AddElements<double> theElement;
		addAndPrint(theElement, argc, argv);
	}
	else{
		// Student Code Goes Here
		AddElements<std::string> theElement;
		addAndPrint(theElement, argc, argv);
	}

	return 0;
}
