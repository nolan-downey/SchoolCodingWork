#include "../classes/BSTNode.h"



int main(){

	BSTNode<int>* node1 = new BSTNode<int>(10);
	BSTNode<int>* node2 = new BSTNode<int>(5);
	BSTNode<int>* node3 = new BSTNode<int>(20);
	BSTNode<int>* node4 = new BSTNode<int>(1);
	BSTNode<int>* node5 = new BSTNode<int>(7);
	BSTNode<int>* node6 = new BSTNode<int>(15);
	BSTNode<int>* node7 = new BSTNode<int>(25);

	// Test 1 - Valid Tree
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;

	// Run your tests for Test 1
	if (node1->checkOrder())
		std::cout << "Test 1 Passed!" << std::endl;
	else
		std::cout << "Test 1 Failed!" << std::endl;

	// Test 2 - 5 (node2) right and 20 (node3) left
	// both point to 15 (node 6)
	node2->right = node6;

	// Run your tests for Test 2
	node1->clearTraverse();
	if (node1->checkOrder())
		std::cout << "Test 2 Passed!" << std::endl;
	else
		std::cout << "Test 2 Failed!" << std::endl;


	// Test 3 - 10 (node1) left points to 7 (node5),
	// and 7 (node5) right points to 5 (node2)
	// Will not pass
	node1->left = node5;
	node1->right = node3;
	node5->left = node4;
	node5->right = node2;
	node3->left = node6;
	node3->right = node7;
	node2->left = NULL;
	node2->right = NULL;

	// Run your tests for Test 3
	node1->clearTraverse();
	if (node1->checkOrder())
		std::cout << "Test 3 Passed!" << std::endl;
	else
		std::cout << "Test 3 Failed!" << std::endl;



	// Test 4 - right child of 25 (node7) points at 5 (node2)
	// Will not pass
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	node7->right = node2;
	node5->left = NULL;
	node5->right = NULL;

	// Run your tests for Test 4
	node1->clearTraverse();
	if (node1->checkOrder())
		std::cout << "Test 4 Passed!" << std::endl;
	else
		std::cout << "Test 4 Failed!" << std::endl;


	node1->clearTraverse();

	// Test 5 - Node 7 points at node 7, creating a loop
	// Will not pass
	node7->right = node7;


	// Run your tests for Test 5
	if (node1->checkOrder())
		std::cout << "Test 5 Passed!" << std::endl;
	else
		std::cout << "Test 5 Failed!" << std::endl;
	return 0;

}
