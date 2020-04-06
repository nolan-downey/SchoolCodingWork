#include "../classes/BST.h"

#include <iostream>
#include <string>


void testExample(){
	
	BST<int> theTree;
	
	theTree.Insert(12);
	theTree.Insert(10);
	theTree.Insert(8);
	theTree.Insert(11);
	theTree.Insert(14);
	theTree.Insert(13);
	theTree.Insert(16);
	theTree.Insert(15);
	theTree.Insert(17);
	theTree.Insert(7);
	theTree.Insert(9);
	theTree.Insert(6);

	DynArr< int > intHeight = theTree.heightPrint();
	
	std::cout << "The height of the example tree is " << intHeight.length();
	std::cout << ", and is " << intHeight << std::endl;
	
	DynArr< int > intDiameter = theTree.diameterPrint();	
	std::cout << "The Diameter of the int tree is " << intDiameter.length(); 
	std::cout << ", and is " << intDiameter << std::endl;
	std::cout << "------------------------" << std::endl;
	
}


void testChar(){
	
	BST< char > theTree;
	
	theTree.Insert('M');
	theTree.Insert('F');
	theTree.Insert('T');
	theTree.Insert('A');
	theTree.Insert('H');
	theTree.Insert('O');
	theTree.Insert('Z');
	theTree.Insert('m');
	theTree.Insert('f');
	theTree.Insert('t');
	theTree.Insert('a');
	theTree.Insert('h');
	theTree.Insert('o');
	theTree.Insert('z');

	DynArr< char > charHeight = theTree.heightPrint();
	std::cout << "The Height of the char tree is " << charHeight.length(); 
	std::cout << ", and is " << charHeight << std::endl;
	
	
	DynArr< char > charDiameter = theTree.diameterPrint();	
	std::cout << "The Diameter of the char tree is " << charDiameter.length(); 
	std::cout << ", and is " << charDiameter << std::endl;
	
	std::cout << "------------------------" << std::endl;
	
	
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

	std::cout << "------------------------" << std::endl;
}

int main(){
	
	testExample();
	
	testChar();
	
	testWorst();
	
	return 0;
}