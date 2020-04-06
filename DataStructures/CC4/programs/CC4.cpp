#include <iostream>
#include "../classes/BST.h"

/*************************
 * Function Name: fillTree
 * Preconditions: int&, int&, char&
 * Postconditions: none
 * Gets input from the user and determines the length, rotations, and direction
 * **********************/
void fillTree(BST<int>& theTree){

	unsigned int numElements;

    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "First, enter the number of elements in the tree: ";
    std::cin >> numElements;

	std::cout << "\nNext, insert " << numElements << " into the tree: ";

	for(unsigned int i = 0; i < numElements; i++){

		int temp;
		std::cin >> temp;

		theTree.Insert(temp);
	}

	std::cout << "\nThe initial tree is: \n";

	theTree.printInOrder(std::cout);

	theTree.printPreOrder(std::cout);

	theTree.printPostOrder(std::cout);

}



/*************************
 * Function Name: main
 * Preconditions: none
 * Postconditions: int
 * This is the main driver function
 * **********************/
int main()
{

	// Create the Binary Search Tree
	BST<int> theTree;

	// Fill the Tree
	fillTree( theTree );
	unsigned n1, n2;

  // Rotation char loop
  char loopCont = 'y';

	while(loopCont == 'y'){

			// Student algorithm goes here
			std::cout << "\nInsert a pair to check - [First] [Second]: " ;
			std::cin >> n1 >> n2;

			std::cout << "\nFind LCA for " << n1 << " and " << n2 << "...\n" ;
			theTree.findLCA(n1, n2);

			std::cout << "\n\nContinue? y/n: " ;
			std::cin >> loopCont;

	}

    std::cout << "...Exiting Program ..." << std::endl;

    return 0;
}
