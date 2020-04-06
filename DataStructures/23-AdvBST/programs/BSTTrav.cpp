#include "../classes/BST.h"

#include <iostream>
#include <string>


void testChar(){
	
	std::cout << "Testing Traversals with Chars" << std::endl;
	
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

	theTree.printInOrder( std::cout );	
	theTree.printPreOrder( std::cout );
	theTree.printPostOrder( std::cout );
	
}

int main(){
	
	testChar();
	
	return 0;
}