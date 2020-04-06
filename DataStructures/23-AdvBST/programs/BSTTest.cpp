#include "../classes/BST.h"

#include <iostream>
#include <string>

int main(){
	
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
	
	theTree.printPreOrder(std::cout);
	theTree.printInOrder(std::cout);
	theTree.printPostOrder(std::cout);
	
	BST<std::string> NDSong;
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