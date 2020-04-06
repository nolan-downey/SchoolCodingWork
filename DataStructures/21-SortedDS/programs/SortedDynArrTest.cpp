#include "../classes/SorDynArr.h"
#include <iostream>
#include <string>

int main(){
	
	
	SorDynArr<int> sortDynArr;
	
	// Insert 10 elements
	sortDynArr.Insert(214);
	sortDynArr.Insert(-27);
	sortDynArr.Insert(92);
	sortDynArr.Insert(404);
	sortDynArr.Insert(66);
	sortDynArr.Insert(1842);
	sortDynArr.Insert(-408);
	sortDynArr.Insert(0);
	sortDynArr.Insert(20312);
	sortDynArr.Insert(42);
	
	// Print all elements 
	for(unsigned int iter = 0; iter < sortDynArr.length(); ++iter){
		
		std::cout << sortDynArr[iter] << " ";
	}
	std::cout << std::endl << (char)10;
	
	SorDynArr<std::string> strSort;
	
	// Insert 10 elements 
	strSort.Insert("Cheer");
	strSort.Insert("Cheer");
	strSort.Insert("for");
	strSort.Insert("Old");
	strSort.Insert("Notre");
	strSort.Insert("Dame");
	strSort.Insert("Wake");
	strSort.Insert("up");
	strSort.Insert("the");
	strSort.Insert("echoes");
	strSort.Insert("cheering");
	strSort.Insert("her");
	strSort.Insert("name");
	
	// Print all elements 
	for(unsigned int iter = 0; iter < strSort.length(); ++iter){
		
		std::cout << strSort[iter] << " ";
	}
	std::cout << std::endl << (char)10;
	
	return 0;
}