#include "../classes/BST.h"

#include <iostream>
#include <string>


void testChar(){
	
	BST< char > theTree;
	
	theTree.Insert('M');
	theTree.Insert('F');
	theTree.Insert('T');
	theTree.Insert('A');
	theTree.Insert('H');
	theTree.Insert('O');
	theTree.Insert('Z');
	
	DynArr< char > initHeight = theTree.heightPrint();
	std::cout << "The Height of the first tree after is " << initHeight.length(); 
	std::cout << ", and is " << initHeight << std::endl;
	
	DynArr< char > initDiameter = theTree.diameterPrint();	
	std::cout << "The Diameter of the first tree after is " << initDiameter.length(); 
	std::cout << ", and is " << initDiameter << std::endl;
	
	theTree.Insert('m');
	theTree.Insert('f');
	theTree.Insert('t');
	theTree.Insert('a');
	theTree.Insert('h');
	theTree.Insert('o');
	theTree.Insert('z');

	DynArr< char > finalHeight = theTree.heightPrint();
	std::cout << "The Height of the final tree after is " << finalHeight.length(); 
	std::cout << ", and is " << finalHeight << std::endl;
	
	
	DynArr< char > finalDiameter = theTree.diameterPrint();	
	std::cout << "The Diameter of the final tree after is " << finalDiameter.length(); 
	std::cout << ", and is " << finalDiameter << std::endl;
	
}


void testWorst(){
	
	BST< char > theTree;
	
	for(unsigned int ascii = 65; ascii <= 90; ascii++){
		
		theTree.Insert( (char)ascii );
		
	}
	
	DynArr< char > theHeight = theTree.heightPrint();

	std::cout << "The Height of the worst-case tree is " << theHeight.length(); 
	std::cout << ", and is " << theHeight << std::endl;

	DynArr< char > theDiameter = theTree.diameterPrint();	
	
	std::cout << "The Diameter of the worst-case tree is " << theDiameter.length(); 
	std::cout << ", and is " << theDiameter << std::endl;
}

int main(){
	
	testChar();
	
	testWorst();
	
	return 0;
}