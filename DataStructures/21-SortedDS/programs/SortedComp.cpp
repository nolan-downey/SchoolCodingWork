#include "../classes/SortedSLL.h"
#include "../classes/SorDynArr.h"
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <iostream>

int main(int argc, char** argv){
	
	if(argc != 2){
		std::cerr << "Wrong inputs" << std::endl;
		exit(-1);
	}
	
	long unsigned int arrayLen = atoi(argv[1]);
	
	
	srand ( (unsigned int)time(NULL) );
	
	double totSDATime = 0;
	double totSLLTime = 0;

	
	SorDynArr<int> valuesSDA;
	SortedSLL<int> valuesSLL;

	int* intArray = new int[arrayLen];

	for(unsigned int iter = 0; iter < arrayLen; iter++){
		
		intArray[iter] = rand() % (int)arrayLen;
		
	}

	// Start the timer
	auto startSDA = std::chrono::system_clock::now();

	for(unsigned int iter = 0; iter < arrayLen; iter++){
		
		valuesSDA.Insert( intArray[iter] );
		
	}

	// End the timer
	auto endSDA = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds_SDA = endSDA - startSDA;

	totSDATime += elapsed_seconds_SDA.count();



	// Start the timer
	auto startSLL = std::chrono::system_clock::now();

	for(unsigned int iter = 0; iter < arrayLen; iter++){
		
		valuesSLL.Insert( intArray[iter] );
		
	}
	
	// Truncated Test ensuring both structures are sorted
	/* for(unsigned int iter = 0; iter < arrayLen; iter++){
		
		std::cout << valuesSDA[iter] << " ";
		
	}
	std::cout << std::endl << valuesSLL << std::endl;*/

	// End the timer
	auto endSLL = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds_SLL = endSLL - startSLL;

	totSLLTime += elapsed_seconds_SLL.count();


	// Now, we do the random deletion
	// Remove elements one at a time 
	startSDA = std::chrono::system_clock::now();
	while( valuesSDA.length() > 0 ){
		
		valuesSDA.erase( rand() % valuesSDA.length() );
		
	}
	endSDA = std::chrono::system_clock::now();
	elapsed_seconds_SDA = endSDA - startSDA;
	totSDATime += elapsed_seconds_SDA.count();



	// Now, remove one element from Sorted Linked List
	startSLL = std::chrono::system_clock::now();
	for(unsigned int iter = 0; iter < arrayLen; iter++){
		
		valuesSLL.Delete( intArray[iter] );
		
	}
	
	endSLL = std::chrono::system_clock::now();
	elapsed_seconds_SDA = endSLL - startSLL;
	totSLLTime += elapsed_seconds_SLL.count();

	delete intArray;
	
	
	std::cout << "Sorted Dynamic Array for 100 runs Average Time     : " << totSDATime << std::endl;
	std::cout << "Sorted Singly Linked List for 100 runs Average Time: " << totSLLTime << std::endl;
	
	return 0;
}