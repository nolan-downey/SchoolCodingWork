#include <iostream>
#include <cstdlib> // Included for malloc

void swapValues(int& a, int& b) {

		b = a+b;
		a = b-a;
		b = b-a;

}
/********************************************
* Function Name  : printArray
* Pre-conditions : int* swapInt, long unsigned int numInts
* Post-conditions: none
*
* This function prints all the elements of an integer array
********************************************/
void printArray(int* swapInt, long unsigned int numInts){

	for(int i = 0; i < (int)numInts; i++){

		std::cout << *(swapInt + i) << " ";
	}

	std::cout << (char)0xA;

}

/********************************************
* Function Name  : main
* Pre-conditions : void
* Post-conditions: int
*
* This is the main driver function for the program
********************************************/
int main(void){

	/* Declare variables */
	long unsigned int numInts = 6;
	int* swapInt = new int[numInts];

	/* Store the values */
	int i;
	for(i = 0; i < (int)numInts; i++){

		*(swapInt + i) = i*2;	// Equivalent to swapInt[i] = i*2;

	}

	// Print Initial Array
	printArray(swapInt, numInts);

	// Solution for in-class to be coded here:
	for(i = 0; i < (int)numInts - 1; i += 2) {

			swapValues(swapInt[i], *(swapInt + i + 1));
	}

	// Print Final Array
	printArray(swapInt, numInts);

	/* Free Memory */
	delete swapInt;

	return 0;
}
