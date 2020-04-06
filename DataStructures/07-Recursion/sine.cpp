#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
#include <cstdlib>		// exitr
#include <cmath>		// pow


/********************************************
* Function Name  : factorial
* Pre-conditions : unsigned int i
* Post-conditions: double
*
* The factorial function that we coded in
* Lecture 07 Preview
********************************************/
double factorial(unsigned int i){

	// Base case i = 0
	if(i == 0){
		return 1;
	}

	return (double)i * factorial(i-1);
}


// Student solution will be coded here
double sine(double x, unsigned int n) {
	if (n == 0)
		return x;
	return pow(-1,n)*pow(x, 2*n+1)/factorial(2*n+1) + sine(x,n-1);
}

/********************************************
* Function Name  : getArgv1Num
* Pre-conditions : int argc, char** argv
* Post-conditions: double
*
* Takes in argc and argv, and determines if argv[1]
* is a valid double
********************************************/
double getArgv1Num(int argc, char** argv){

	if(argc != 2){
		std::cout << "Incorrect number of inputs" << std::endl;
		exit(-1);
	}

	// stringstream used for the conversion initialized with the contents of argv[1]
	double factNum;
	std::stringstream convert(argv[1]);

	//give the value to factNum using the characters in the string
	if ( !(convert >> factNum) ){
		std::cout << "Not a valid double" << std::endl;
		exit(-1);
	}

	return factNum;

}


/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*
* This is the main driver function
********************************************/
int main(int argc, char** argv){

	// Main Function will be coded here

	std::cout << sine(getArgv1Num(argc, argv), 20) << std::endl;

	return 0;
}
