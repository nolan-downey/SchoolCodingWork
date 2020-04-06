#include <iostream>			// std::cout
#include <cstdlib>			// Exit
#include <cstring>			// std::strcmp
#include <sstream>      	// std::stringstream
#include <typeinfo>			// typeid

const long unsigned int startVals = 3;	// Start Value Iteration

/********************************************
* Function Name  : checkInputs
* Pre-conditions : const long unsigned int argc, char** argv
* Post-conditions: long unsigned int
*
* Checks the inputs for the Determinant Problem
********************************************/
long unsigned int checkInputs(const long unsigned int argc, char** argv){

	// Need type, n, as well as n*n values
	if(argc < 3){

		std::cout << "Need 3 or more inputs" << (char)0x0A;
		exit(-1);

	}

	// Can be an int, float or double
	if( std::strcmp(argv[1], "int") != 0 &&
		std::strcmp(argv[1], "float") != 0 &&
		std::strcmp(argv[1], "double") != 0 ){

		std::cout << "Improper type definition" << std::endl;
		exit(-1);

	}

	// Get the number N for the matrix
	long unsigned int matrixSize;
	std::stringstream convert(argv[2]);

	// Determine the n value, which is argv[2]
	if ( !(convert >> matrixSize) ){
		std::cout << argv[2] << " is not a valid matrix size" << std::endl;
		exit(-1);
	}

	// Finally, check if the number of inputs is correct
	if(argc != matrixSize * matrixSize + startVals){

		std::cout << "The matrix requires n*n inputs." << std::endl;
		exit(-1);
	}

	return matrixSize;

}

/********************************************
* Function Name  : printMatrix
* Pre-conditions : T** theMatrix, const long unsigned int n
* Post-conditions: none
*
* This function printa an n-by-n matrix
********************************************/
template<class T> void printMatrix(T** theMatrix, const long unsigned int n){

	for(long unsigned int i = 0; i < n; i++){

		for(long unsigned int j = 0; j < n; j++){

			std::cout << theMatrix[i][j] << " ";

		}

		std::cout << std::endl;

	}
}


/********************************************
* Function Name  : allocateMatrix
* Pre-conditions : const long unsigned int n, char** argv
* Post-conditions: T**
*
* Allocates a n-by-n matrix and reads values from argv
********************************************/
template<class T> T** allocateMatrix(const long unsigned int n, char** argv){

	// Student Code Goes Here
	T** theMatrix = (T**)malloc( n * sizeof(T*) );

	for (long unsigned int i = 0; i < n; i++) {

		theMatrix[i] = (T*)malloc( n * sizeof(T) );
	}

	//Insert values from the command line
	for (long unsigned int i = 0; i < n; i++) {

		for(long unsigned int j = 0; j < n; j++) {

			T value;
			std::stringstream convert( argv[n*i + j + startVals] );

			if( !( convert >> value )) {

				std::cout << argv[n*i + j + startVals] << "is not valid\n";
				exit(-1);

			}

			//Set the value
			theMatrix[i][j] = (T)value;
		}
	}

	return theMatrix;

}


/********************************************
* Function Name  : allocateEmptyMatrix
* Pre-conditions : const long unsigned int n
* Post-conditions: T**
*
* Allocates an empty matrix for use in cofactors
********************************************/
template<class T> T** allocateEmptyMatrix(const long unsigned int n){

	// Allocate the pointers
	T** theMatrix = (T**)malloc( n * sizeof(T *) );

	// Allocate an array of length n for each pointer
	for(long unsigned int i = 0; i < n; i++){

		theMatrix[i] = (T*)malloc( sizeof(T) );
	}

	// Insert the values for
	for(long unsigned int i = 0; i < n; i++){

		for(long unsigned int j = 0; j < n; j++){

			// Set the value
			theMatrix[i][j] = (T)0;

		}
	}

	return theMatrix;
}


/********************************************
* Function Name  : getCofactor
* Pre-conditions : T** theMatrix, T** temp, long unsigned int p, long unsigned int q, long unsigned int n
* Post-conditions: none
*
* Returns the cofactor with a pass by reference
********************************************/
template<class T> void getCofactor(T** theMatrix, T** temp, long unsigned int p, long unsigned int q, long unsigned int n){

	long unsigned int i = 0, j = 0;

    // Looping for each element of the matrix
    for (long unsigned int row = 0; row < n; row++)
    {
        for (long unsigned int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = theMatrix[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }


}

/********************************************
* Function Name  : getDeterminant
* Pre-conditions : T** theMatrix, long unsigned int matrixSize
* Post-conditions: T
*
* Returns the value of the Determinant of the matrix
********************************************/
template<class T> T getDeterminant(T** theMatrix, long unsigned int matrixSize){

	// Student Code Goes Here
	T determinant = 0;

	//Base Case
	if(matrixSize == 1) {
			return theMatrix[0][0];
	}

	//Store co-factrs
	T** cofactors = allocateEmptyMatrix<T> (matrixSize);

	int sign = 1;

	for(long unsigned int f = 0; f < matrixSize; f++) {

		getCofactor(theMatrix, cofactors, 0, f, matrixSize);

		determinant += sign * theMatrix[0][f] * getDeterminant(cofactors, matrixSize-1);

		sign = -sign;
	}

	return determinant;
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
	long unsigned int matrixSize = checkInputs(argc, argv);

	std::cout << "Matrix is " << matrixSize << "x" << matrixSize << std::endl;

	// Create Templated AddElements
	if( std::strcmp(argv[1], "int") == 0 ){

		int** intMatrix = allocateMatrix<int>(matrixSize, argv);
		std::cout << "Initial Matrix:" << std::endl;
		printMatrix(intMatrix, matrixSize);

		// Find the Determinant
		std::cout << "The Determinant is: " << getDeterminant(intMatrix, matrixSize) << std::endl;

	}
	else if( std::strcmp(argv[1], "float") == 0 ){

		float** floatMatrix = allocateMatrix<float>(matrixSize, argv);
		std::cout << "Initial Matrix:" << std::endl;
		printMatrix(floatMatrix, matrixSize);

		// Find the Determinant
		std::cout << "The Determinant is: " << getDeterminant(floatMatrix, matrixSize) << std::endl;

	}
	else if( std::strcmp(argv[1], "double") == 0 ){

		double** dblMatrix = allocateMatrix<double>(matrixSize, argv);
		std::cout << "Initial Matrix:" << std::endl;
		printMatrix(dblMatrix, matrixSize);

		// Find the Determinant
		std::cout << "The Determinant is: " << getDeterminant(dblMatrix, matrixSize) << std::endl;

	}

	return 0;
}
