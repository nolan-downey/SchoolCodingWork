#include "../classes/SplayTree.h"

#include <iostream>
#include <string>

template<class T>
void insertSplay(SplayTree<T>& theTree, const T& value){
	
	std::cout << "Inserting " << value << " into the splay..." << std::endl;
	theTree.Insert(value);
	theTree.printPreOrder(std::cout);
	theTree.printInOrder(std::cout);
	theTree.printPostOrder(std::cout);
	std::cout << "------------------------------" << std::endl;
}

int main(){
	
	SplayTree<int> theTree;
	
	insertSplay(theTree, 12);
	insertSplay(theTree, 10);
	insertSplay(theTree, 8);
	insertSplay(theTree, 13);
	insertSplay(theTree, 11);
	insertSplay(theTree, 14);
	insertSplay(theTree, 16);
	insertSplay(theTree, 15);
	insertSplay(theTree, 17);
	insertSplay(theTree, 7);
	insertSplay(theTree, 9);
	
	SplayTree<std::string> NDSong;
	NDSong.Insert("Send");
	NDSong.Insert("A");
	NDSong.Insert("Volley");
	NDSong.Insert("Cheer");
	NDSong.Insert("On");
	NDSong.Insert("High");
	
	NDSong.printPreOrder(std::cout);
	NDSong.printInOrder(std::cout);
	NDSong.printPostOrder(std::cout);
	
	return 0;
}