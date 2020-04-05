//Nolan Downey
//crossword.cpp

#include <iostream>
#include <fstream>
#include "board.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	Board b;

	if (argc == 1) {
		
		string temp;
		int c = 0;

		while (c < 20) {
			c++;
			cout << "Please enter a word, or a '.' if you are done: ";
			getline (cin, temp);

			if (!temp.compare(END)) {
				break;
			}

			else if(temp.length() > SZ) {
				cout << "The word can't be longer than fifteen letters! :(" << endl << "Try again!" << endl;
				c--;
			}

			else if(temp.length() < 2) {

				cout << "The word can't be less than 2 letters... :(" << endl << "Try again!" << endl;
				c--;
			}

			else {
				b.setWord(temp);
			}
		}
	}

	else if (argc == 2 or argc == 3) {
	
		string filename;
		filename = argv[1];
		ifstream ifs;
		ifs.open(filename);

		if (!ifs) {
			cout << "You should probably type in an existing file... " << endl << "Error opening file: " << filename << endl;
			return 2;
		}

		string temp;
		ifs >> temp;
		int num = 1;
		
		while (temp.compare(END) and num < 20) {
			if (temp.length() > SZ) {
				cout << "The word cannot be longer than 15 letters." << endl;
				break;
			}

			b.setWord(temp);
			ifs >> temp;
			num++;
		}
	}

 if (argc == 1 or argc == 2) {

		b.followingWord();
		b.placeFirst();

		while (b.wordsLeft() > 0) {
			 b.followingWord();

			if (!b.placeWord()) {
				cout << "Not all words were able to be placed." << endl;
				break;
			} 
		

			system("clear");

			cout << "Solution:" << endl << endl;

			b.printBoard(cout);

			cout << endl << endl << "Crossword Puzzle: " << endl << endl;
			
			b.printPuzzle(cout);

			b.printClues(cout);
		}
		
	}

	else if (argc == 3) {
		string ofile;
		ofile = argv[2];

		ofstream ofs;
		ofs.open(ofile);

		if(!ofs) {
			cout << "You should try and type an existing file name... " << endl << "Error opening: " << ofile << endl;
			return 3;
		}

		b.followingWord();
		b.placeFirst();

		while (b.wordsLeft() > 0) {
			b.followingWord();

			if (!b.placeWord()) {
				cout << "Not all words were able to be placed." << endl;
				break;
			}
			

			system("clear");
			cout << "Solution:" << endl << endl;
			b.printBoard(ofs);

			cout << endl << endl << "Crossword: " << endl << endl;
			b.printPuzzle(ofs);
			
			b.printClues(ofs);
		}
	}

	else {
		cout << "Too many arguments when executing program." << endl;
		return 1;
	}	

return 0;

}
