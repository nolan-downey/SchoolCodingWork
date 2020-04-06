/**********************************************
* File: findCircular.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
* This contains two solutions to the Cracking the Coding Interview
* question "Given a circular linked list, implement an algorithm 
* which returns node at the beginning of the loop."
*
* I added complexity by making the following changes:
* 
* a) Given a circular singly linked list, implement an algorithm which 
* returns nodes at the beginning and end of the loop.
* b) How would your solution change if you were not permitted to use 
* an additional data structure class?
* 
* The solution to part a is findCircularHash
* The solution to part b is findCircularRace
**********************************************/

#include <iostream>
#include <unordered_map>

template< class T >
struct node
{
	T     data;
	node<T>* next;
	
	/********************************************
	* Function Name  : checkMemory
	* Pre-conditions : none
	* Post-conditions: none
	* 
	* Checks to see if the *this pointer is 
	* pointing to a valid memory location.
	* Terminates program if not to prevent stack overfloe 
	********************************************/
	void checkMemory(){
		
		if (this == NULL)
		{
			std::cerr <<  "Out of Memory" << std::endl;
			exit (-1);
		} 
		
	}
	
	/********************************************
	* Function Name  : node
	* Pre-conditions : none
	* Post-conditions: none
	* 
	* Node Struct Default Constructor 
	********************************************/
	node() : data(), next(NULL) {
		
		// Check to ensure address properly allocated
		checkMemory();
		
	}
	
	
	/********************************************
	* Function Name  : node
	* Pre-conditions : none
	* Post-conditions: none
	* 
	* Node Struct Overloaded Constructor with data input 
	********************************************/
	node(T dataIn) : data(dataIn), next(NULL) {
		
		// Check to ensure address properly allocated				
		checkMemory();
		
	}
	

	/********************************************
	* Function Name  : ~node
	* Pre-conditions : none
	* Post-conditions: none
	*  
	* Delete operator required for PQC since it contains a 
	* private member which is a pointer
	********************************************/
	~node(){
		
		//delete next;
		
	}
	

	/********************************************
	* Function Name  : node
	* Pre-conditions : const node& copy
	* Post-conditions: none
	*  
	* Rule of 3: Copy Constructor
	* Required for -weffc++ flag
	********************************************/
	node(const node& copy) : data(copy.data), next(copy.next) {}
	
	
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
			this->next = assign.next;
		}
		return *this;
	}
	
	
	/********************************************
	* Function Name  : operator=
	* Pre-conditions : const node* assign
	* Post-conditions: node*
	* 
	* Assignment Operator for Pointer
	* Required for pointer assignment in SLList
	********************************************/
	node* operator=(const node* assign){
		
		if(this != (void *)&assign){
			this->data = assign->data;
			this->next = assign->next;
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


void findCircularHash(node<int>& head){
	
	std::cout << std::endl << "Using the Hash Table method..." << std::endl;
	
	// Create the Hash Table 
	std::unordered_map< void*, bool > theHash;
	
	// Go through the nodes
	node<int> *nodeIter = &head;
	node<int> *nodePrev;
	while(theHash.count( (void *)nodeIter ) == 0 && nodeIter->next != NULL){
		
		theHash.insert( {(void *)nodeIter, true} );
		nodePrev = nodeIter;
		nodeIter = nodeIter->next;
	}
	
	// Print the results to the user
	if( nodeIter->next != NULL ){
		
		std::cout << "Circular Link exists!" << std::endl;
		std::cout << "Origin of Circular Link: Address is " << (void *)&nodePrev 
			<< " with data " << nodePrev->data << std::endl;
			
		std::cout << "Destination of Circular Link: Address is " << (void *)&(nodeIter)
			<< " with data " << nodeIter->data << std::endl;
	}
	else{
		
		std::cout << "No loop in the list" << std::endl;
	}	
	
}



void findCircularRace(node<int>& head){
	
	std::cout << std::endl << "Using the node race method..." << std::endl;
	
	// Initialize the counting pointers
	node<int> *nodeSlow = &head;
	node<int> *nodeFast = &head;
	node<int> *nodePrev = new node<int>();
	
	while(nodeFast->next != NULL){
		
		nodePrev = nodeSlow;
		nodeSlow = nodeSlow->next;
		nodeFast = nodeFast->next->next;

		if(nodeSlow == nodeFast){
			break;
		}
	}
	
	if(nodeSlow == nodeFast){
		
		// Reset slow to the Head node 
		nodeSlow = &head;
		
		// Include a previous node 
		
		// Iterate until the nodes are equal 
		while(nodeSlow != nodeFast){
			nodePrev = nodeFast;
			nodeSlow = nodeSlow->next;
			nodeFast = nodeFast->next;
		}
		
		std::cout << "Circular Link exists!" << std::endl;
		std::cout << "Origin of Circular Link: Address is " << (void *)&nodePrev 
			<< " with data " << nodePrev->data << std::endl;
			
		std::cout << "Destination of Circular Link: Address is " << (void *)&(nodeSlow)
			<< " with data " << nodeSlow->data << std::endl;
		
	}
	else{
		
		std::cout << "No loop in the list" << std::endl;
	}

}


void runBothAlgs(node<int>& head){
	
	std::cout << "---------------------------------------\n";
	
	// Find the circular list location by hashing
	findCircularHash(head);
	
	// Find the circular list location by racing 
	findCircularRace(head);
	
	
}


int main(){
	
	// Create the nodes
	node<int> node1(10);
	node<int> node2(20);
	node<int> node3(30);
	node<int> node4(40);
	node<int> node4b(45);
	node<int> node5(32);
	
	// Make the circular list
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node1;	// Circular occurs here
	
	// Find the circular list location
	runBothAlgs(node1);

	// Make the circular list odd length
	node4.next = &node4b;
	node4b.next = &node5;

	// Find the circular list location
	runBothAlgs(node1);	
	
	// Move the loop to the node3
	node5.next = &node3;

	// Find the circular list location
	runBothAlgs(node1);

	// Delete the link 
	node5.next = new node<int>();
	
	// Find the circular list location
	runBothAlgs(node1);

	return 0;
	
}
