/**********************************************
* File: BST.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*
* Constains the class structure for a Binary
* Search Tree
**********************************************/

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>

#include "DynArr.h"

template<class T>
class BST{

	private:

		/* NODE contains the data and a pointer to the next node */
		struct node
		{
			T     data;
			node* left;
			node* right;

			void checkMemory(){

				if (this == NULL)
				{
					std::cerr <<  "Out of Memory" << std::endl;
					exit (-1);
				}

			}

			node() : data(), left(NULL), right(NULL) {

				// Check to ensure address properly allocated
				checkMemory();

			}

			node(T dataIn) : data(dataIn), left(NULL), right(NULL) {

				// Check to ensure address properly allocated
				checkMemory();

			}

			~node(){

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
			node(const node& copy){
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
			node& operator=(const node& assign){

				if(this != &assign){
					this->data = assign.data;
					this->left = assign.left;
					this->right = assign.right;
				}
				return *this;
			}

			node* operator=(const node* assign){

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
			bool operator!=(const node* rhs){

				return this != (void *)&rhs;

			}

		};

		node* root;


		void Insert( const T& value, node*& curr )
		{

			if( curr == NULL ){
				//std::cout << "Hello!!!" << std::endl;
				node* temp = new node(value);
				curr = temp;
			}

			else if( value < curr->data )
				Insert( value, curr->left );

			else if( curr->data < value )
				Insert( value, curr->right );

			else
				std::cout << value << " is a duplicate in the tree " << std::endl;

		}


		bool contains( const T& x, node* curr ) const
		{
			if( curr == NULL )
				return false;

			else if( x < curr->data )
				return contains( x, curr->left );

			else if( curr->data < x )
				return contains( x, curr->right );

			else
				return true;    // Match
		}



		node * findMin( node* t ) const
		{
			if( t == NULL )
				return NULL;

			if( t->left == NULL )
				return t;

			return findMin( t->left );

		}

		node * findMax( node* t ) const
		{
			if( t == NULL )
				return NULL;

			if( t->right == NULL )
				return t;

			return findMin( t->right );

		}


		void copyTree(const node* copy, node* curr){

			curr = new node( copy->data );

			if(copy->left != NULL){

				copyTree(copy->left, curr->left);

			}

			if(copy->right != NULL){

				copyTree(copy->right, curr->right);

			}
		}


		void printInOrder( std::ostream& output, const node* theNode) {

				if(theNode == NULL) {
						return;
				}

				if(theNode->left != NULL) {

						printInOrder(output, theNode->left);

				}

				output << theNode->data << " ";

				if( the Node->right !- NULL ) {

						printInOrder(output, theNode->right);
				}
		}

		void remove ( const T& x, node*& curr) {

				if( curr == NULL)
					return;

				if( x < curr->data )
					remove( x, curr->left );

				else if( curr->data < x )
					remove( x, curr->right );

				else if( curr->left != NULL && curr->right != NULL) {

						durr->data = findMin( curr->right ) ->data;

						remove( curr->data, curr->right );

				}

				else {

					node *oldNode = curr;

					curr = (curr->left != NULL) ? curr->left : curr->right;

					delete oldNode;
				}

		}


	public:

		BST() : root(NULL) {}


		~BST(){

			delete root;
		}


		BST(const BST<T>& copy) : root(NULL) {

			if( copy.IsEmpty() ){
				return;
			}

			// Must wait to define since copy may be empty
			root = new node( copy.root->data );

			copyTree(copy.root, root);

		}

		BST<T>& operator=(const BST<T>& assign){

			if(this != &assign){

				if( assign.IsEmpty() ){
					return *this;
				}

				// Must wait to define since copy may be empty
				root = new node( assign.root->data );

				copyTree(assign.root, root);

			}
			return *this;

		}

		bool IsEmpty () const{

			return root == NULL;

		}

		void Insert(const T& value){

			Insert(value, root);

		}


		bool contains( const T& x ) const
		{
			return contains( x, root );
		}


		T & findMin( )
		{
			if( IsEmpty( ) ){
				std::cout << "Tree is Empty" << std::endl;
				exit(-1);
			}

			return findMin( root )->element;
		}

		T & findMax( )
		{
			if( IsEmpty( ) ){
				std::cout << "Tree is Empty" << std::endl;
				exit(-1);
			}

			return findMax( root )->element;
		}

		void remove (const T& x) {
				remove (x, root);
		}

		void printInOrder( std::ostream& output ) {


		}


};


#endif
