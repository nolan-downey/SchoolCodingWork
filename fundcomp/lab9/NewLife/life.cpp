//Nolan Downey
//life.cpp

#include <iostream>
#include <string>
#include "lifeboard.h"

using namespace std;

int main(int argc, char *argv[])
{
 Life board;
 char x;
 int y,z;
 string filename;
 ifstream ifs;

 if (argc == 1) {//just the executable is entered, the program enters interative mode
 	while (x != 'q') {
		board.display();
		cin >> x;
		if (x == 'a') {
			cin >> y >> z;
			board.addcell(y,z);
		}
		if (x == 'r') {
			cin >> y >> z;
			board.removecell(y,z);
		}
		if (x == 'n') {
			board.advance();
		}
		if (x == 'p') {
			while (true) {
				board.advance();
				usleep(300000);
				board.clearscreen();
			}
		}
	}

	if (x == 'q')
		cout << "Have a nice day :)" << endl;
}

	else if (argc == 2) { //the execubtable is followed by the name of a text file, the program enters batch mode
		ifs.open(argv[1]);

		if (!ifs) {
			cout << "Error opening file" << endl; //checks to see if file exists
			return 2;
		}
		
		ifs >> x >> y >> z;
		while (x != 'p') {
			if (x == 'a') {				
				board.addcell(y,z);
			}
			else if (x == 'r'){
				board.removecell(y,z);
			}
			ifs >> x >> y >> z;
		}
	
	board.display();
	usleep(1000000);
	 
		while (true) { //runs simulation once 'p' is read
				board.advance();
				usleep(300000);
				board.clearscreen();
			}
	}

	else {
		cout << "Invalid number of arguments: Either one or no data files" << endl; //if more than one text file is entered
		return 3;
	}



return 0;
}
