#ifndef BSTNODE_H
#define BSTNODE_H

#include <cstdlib>
#include <iostream>

template<class T>
class BSTNode{

	public:
		T     data;
		BSTNode<T>* left;
		BSTNode<T>* right;
		bool traverse;

		void checkMemory(){

			if (this == NULL)
			{
				std::cerr <<  "Out of Memory" << std::endl;
				exit (-1);
			}

		}

		BSTNode<T>() : data(), left(NULL), right(NULL), traverse(false) {

			// Check to ensure address properly allocated
			checkMemory();

		}

		BSTNode<T>(T dataIn) : data(dataIn), left(NULL), right(NULL), traverse(false) {

			// Check to ensure address properly allocated
			checkMemory();

		}

		~BSTNode<T>(){

			//delete left;
			//delete right;

		}

		/********************************************
		* Function Name  : node
		* Pre-conditions : const node& copy
		* Post-conditions: none
		*
		* Rule of 3: Copy Constructor
		* Required for -weffc++ flag
		********************************************/
		BSTNode<T>(const BSTNode<T>& copy){
			data = copy.data;
			left = copy.left;
			right = copy.right;
		}

		/********************************************
		* Function Name  : operator=
		* Pre-conditions : const node& assign
		* Post-conditions: node&
		*
		* Rule of 3: Assignment Operator
		* Required for -weffc++ flag
		********************************************/
		BSTNode<T>& operator=(const BSTNode<T>& assign){

			if(this != &assign){
				this->data = assign.data;
				this->left = assign.left;
				this->right = assign.right;
			}
			return *this;
		}

		BSTNode<T>* operator=(const BSTNode<T>* assign){

			if(this != (void *)&assign){
				this->data = assign->data;
				this->left = assign->left;
				this->right = assign->right;
			}

			return *this;
		}

		/********************************************
		* Function Name  : operator!=
		* Pre-conditions : const node* rhs
		* Post-conditions: bool
		*
		* != Operator for Pointer
		* Required for pointer comparison in SLList
		********************************************/
		bool operator!=(const BSTNode<T>* rhs){

			return this != (void *)&rhs;

		}

		bool checkOrder() {
				bool check = true;

				if (this == this->left || this == this->right) {
						check = false;
						std::cout << "Node containing " << this->data << " is already encountered in the tree.\n";
						return check;
				}

				if (this->traverse == true) {
						check = false;
						std::cout << "Node containing " << this->data << " is already encountered in the tree.\n";
						return check;
				}
				else
					this->traverse = true;

				if (this == NULL)
					check = true;

				if (this->left != NULL && this->right != NULL) {
					if (this->data < this->left->data){
						std::cout << "Invalid tree: " << this->left->data << " is a left child of " << this->data << std::endl;
						check = false;
						return check;
					}
					else if(this->data > this->right->data) {
						std::cout << "Invalid tree: " << this->right->data << " is a right child of " << this->data << std::endl;
						check = false;
						return check;
					}
					else
						return this->left->checkOrder() && this->right->checkOrder();
				}
				else if (this->left != NULL) {
					if (this->data < this->left->data) {
						std::cout << "Invalid tree: " << this->left->data << " is a left child of " << this->data << std::endl;
						check = false;
						return check;
					}
				}
				else if (this->right != NULL) {
					if (this->data > this->right->data) {
						std::cout << "Invalid tree: " << this->right->data << " is a right child of " << this->data << std::endl;
						check = false;
						return check;
					}
				}
				else
				 {}
				return check;
		}

		void clearTraverse() {
				this->traverse = false;

				if (this->left != NULL )
					this->left->clearTraverse();

				if (this->right != NULL )
					this->right->clearTraverse();

		}


};


#endif
