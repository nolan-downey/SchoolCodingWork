#include "../classes/SortedSLL.h"
#include <iostream>
#include <string>

int main(){
	
	
	SortedSLL<int> sortSLLInt;
	
	// Insert 10 elements
	sortSLLInt.Insert(214);
	sortSLLInt.Insert(-27);
	sortSLLInt.Insert(92);
	sortSLLInt.Insert(404);
	sortSLLInt.Insert(66);
	sortSLLInt.Insert(1842);
	sortSLLInt.Insert(-408);
	sortSLLInt.Insert(0);
	sortSLLInt.Insert(20312);
	sortSLLInt.Insert(42);
	
	// Print all elements 
	std::cout << sortSLLInt << std::endl << std::endl;
	
	SortedSLL<std::string> sortSLLStr;
	
	// Insert 10 elements 
	sortSLLStr.Insert("Cheer");
	sortSLLStr.Insert("Cheer");
	sortSLLStr.Insert("for");
	sortSLLStr.Insert("Old");
	sortSLLStr.Insert("Notre");
	sortSLLStr.Insert("Dame");
	sortSLLStr.Insert("Wake");
	sortSLLStr.Insert("up");
	sortSLLStr.Insert("the");
	sortSLLStr.Insert("echoes");
	sortSLLStr.Insert("cheering");
	sortSLLStr.Insert("her");
	sortSLLStr.Insert("name");
	
	// Print all elements 
	std::cout << sortSLLStr << std::endl << std::endl;
	
	return 0;
}
