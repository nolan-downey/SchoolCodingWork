#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
#include <cstdlib>		// exitr
#include <unordered_map>	// Hash Table

/********************************************
* Function Name  : getArgv1Num
* Pre-conditions : int argc, char** argv
* Post-conditions: int
* 
* Returns argv[1] as an int if valid 
********************************************/
int getArgv1Num(int argc, char** argv){
	
	if(argc != 2){
		std::cout << "Incorrect number of inputs" << std::endl;
		exit(-1);
	}
	
	// stringstream used for the conversion initialized with the contents of argv[1]
	int stepVal;
	std::stringstream convert(argv[1]);

	//give the value to factNum using the characters in the string
	if ( !(convert >> stepVal) ){
		std::cout << "Not a valid integer" << std::endl;
		exit(-1);
	}
	
	// Check if input is < 1
	if( stepVal < 1 ){
		
		std::cout << stepVal << " must be 1 or more " << std::endl;
		exit(-1);
	}
	
	return stepVal;
	
}

/********************************************
* Function Name  : recurCS
* Pre-conditions : int nSteps
* Post-conditions: double
* 
* Recursively determines the # of combinations of steps 
********************************************/
double recurCS(int nSteps, std::unordered_map<int, double>& stepVals){
	
	/* No contains in unordered_map until std=c++20 */
	/* User .count(nSteps) != 0 until std=c++20 installed on computing device */
	if(stepVals.count(nSteps) != 0)
		return stepVals[nSteps];
	
	// Base Cases
	if(nSteps == 1){
		stepVals.insert( {1, 1} );
		return 1;
	}
	
	else if(nSteps == 2){
		stepVals.insert( {2, 2} );
		return 2;
	}
	
	else if(nSteps == 3){
		stepVals.insert( {3, 4} );
		return 4;
	}
	
	// Insert Combinations into the Hash Table
	double comb = recurCS(nSteps-1, stepVals) + recurCS(nSteps-2, stepVals) + recurCS(nSteps-3, stepVals);
	stepVals.insert( {nSteps, comb} );
	
	return comb;
}


/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(int argc, char** argv){

	// Get the number of steps from the user
	int numSteps = getArgv1Num(argc, argv);
	
	std::cout << "The child is taking " << numSteps << " steps " << std::endl;
	
	// Create a Hash Table that stores the information
	std::unordered_map<int, double> stepVals;
	
	// Run the recursive algorithm
	std::cout << "There are " << recurCS(numSteps, stepVals) << " combinations\n";

	return 0;
}
