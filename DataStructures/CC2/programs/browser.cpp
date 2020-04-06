/**********************************************
* File: browser.cpp
* Author: Nolan Downey
* Email: ndowney@nd.edu
* 
* Main Driver for browser history program
**********************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../classes/Site.h"

/********************************************
* Function Name  : getFileStream
* Pre-conditions : int argc, char** argv, std::ifstream& ifs
* Post-conditions: none
* 
* Function to check the number of arguments in the command line
********************************************/
void getFileStream(int argc, char** argv, std::ifstream& ifs){
	
	// Must be exactly two characters
	if(argc != 2){
		std::cout << "Incorrect number of inputs" << std::endl;
		exit(-1);
	}
	
	// Attempt to open the file
	ifs.open (argv[1], std::ifstream::in);
	
	if(!ifs.is_open()){
		std::cout << "Input File Name " << argv[1] << " does not exist\n";
		exit(-1);
	}
	
}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
* 
* Main Driver for the browser history program
********************************************/
int main(int argc, char** argv){
	
	// Check the input 
	std::ifstream browserIn;
	getFileStream(argc, argv, browserIn);
	
	/***************************************
	 * Initialize an empty browser list 
	 * using your selected Data Structure
	 * between here and the while loop 
	 ***************************************/
	std::vector<Site> websites;
	
	// Read in the browser information 
	while( !browserIn.eof() ){
		
		// Get the unsigned int from the file 
		std::string readStr;
		
		// First, get the URL 
		std::string URL;
		std::getline(browserIn, URL);
		
		// Next, get the website header 
		std::string webHeader;
		std::getline(browserIn, webHeader);
		
		// Next, get the Date Visited
		std::string Time;
		std::getline(browserIn, Time);
		
		// Next, get the time visited
		std::string Date;
		std::getline(browserIn, Date);
		
		/***********************
		* You have everything you need to insert 
		* into a Song class object. You just need 
		* to create the object and insert into the 
		* Data Structure 
		***********************/
		
		Site info(URL, webHeader, Time, Date);

		websites.push_back(info);
		
	}
	
	/***********************
	* Now that the playlist is created 
	* print all the objects in the Data Structure
	***********************/
	
	for (unsigned int i = 0; i < websites.size(); i++) {

		std::cout<< websites.at(i);
	
	}

	return 0;
}


