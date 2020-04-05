//Nolan Downey
//board.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "board.h"

using namespace std;

Board::Board() {

	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ;j++) {
			mainboard[j][i] = '\0';
			bboard[j][i] = false;
			oboard[j][i] = 0;
			
		}
	}
}

Board::~Board() {}

ostream & Board::printClues(ostream & os) {
	
	for (int j = 0; j < words.size(); j++) {
		if (words[j].placed) {
			os << right;
			os << setw(2) << words[j].across << ",";
			os << setw(2) << words[j].down;
			os << setw(7);

			if (words[j].orientation == 0) {
				os << "Down";
			}
			else {
				os << "Across";
			}

			os << "\t";
			os << words[j].s_word;
			os << endl;
		}
	}

	return os;
}

ostream & Board::printBoard(ostream & os) {
	
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (mainboard[j][i] == '\0') {
				os << ".";
			}
			else {
				os << mainboard[j][i];
			}
		}
			os << endl;
	}

	return os;
}

ostream & Board::printPuzzle(ostream & os) {
	
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (mainboard[j][i] == '\0') {
				os << "#";
			}
			else {
				os << " ";
			}
		}

		os << endl;
	}

	return os;
}

void Board::setWord(string i) {
	Word w;
	w.a_word = toUpper(i);
	w.s_word = scramble(w.a_word);
	w.placed = false;
	words.push_back(w);
}

string Board::toUpper(string s) {
	char a;
	for (int i=0; i < s.length(); i++) {
		a = s.at(i);
		a = toupper(a);
		s.at(i) = a;
	}

	return s;
}

string Board::scramble(string s) {
	for (int i = s.length(); i > 0; i--) {
		int r = rand() % s.length();
		char t = s[i-1];
		s[i-1] = s[r];
		s[r] = t;
	}
	return s;
}

void Board::placeFirst() {
	int start = (SZ-nextWord.a_word.length()) / 2;
	words[nextWordPos].down = 7;
	words[nextWordPos].across = start;
	words[nextWordPos].orientation = ACROSS;
	words[nextWordPos].placed = true;
	
	int left = nextWord.a_word.length();
	int place = 0;
	int aspot  = start;
	int dspot = 7;

	while (left > 0) {
		mainboard[aspot][dspot] = nextWord.a_word.at(place);
		bboard[aspot][dspot] = true;
		oboard[aspot][dspot] = 1;
		left--;
		place++;
		aspot++;
	}
}


void Board::followingWord() {

	nextWordPos = -1;

	for (int  i = 0; i < words.size(); i++) {
		if (!words[i].placed) {
			if (nextWordPos == -1) {
				nextWordPos = i;
			}
			else if (words[i].a_word.length() > words[nextWordPos].a_word.length()) {
				nextWordPos = i;
			}
		}
	}
	nextWord = words[nextWordPos];
}


bool Board::placeWord() {
	for (int d = 0; d < SZ; d++) {
		for (int a = 0; a < SZ; a++) {
			if (bboard[a][d]) {
				for (int i = 0; i < nextWord.a_word.length(); i++) {
					if (mainboard[a][d] == nextWord.a_word[i]) {
						if (checkPlace(a,d,i)) {
							words[nextWordPos].placed = true;
							return true;
						}
					}
				}
			}
		}
	}
}

bool Board::checkPlace(int a, int d, int i) {

	int direction = oboard[a][d];
	int dstart = 0, dend = 0, aPos = 0, dPos = 0, astart = 0, aend = 0;

	if (direction == 1) {
		dstart = d-i;
		dend = dstart + nextWord.a_word.length();
		astart = a;

		if (dstart < 0 or dend > 14)
			return false;

		if (dstart !=0 and dend != 14) {
			if (mainboard[a][dstart-1] != '\0' or mainboard[a][dend+1] != '\0') {
				return false;
			}
		}

		aPos = a;
		dPos = dstart;

		for (int i = 0; i < nextWord.a_word.length(); i++) {
			if (dPos != d) {
				if (mainboard [aPos][dPos] != '\0' or mainboard[aPos-1][dPos] != '\0' or mainboard[aPos+1][dPos] != '\0') {
					return false;
				}
			}
			dPos++;
		}

		aPos = a;
		dPos = dstart;

		for (int j = 0; j < nextWord.a_word.length(); j++) {
			mainboard[aPos][dPos] = nextWord.a_word[j];
			bboard[aPos][dPos] = true;
			oboard [aPos][dPos] = 2;
			dPos++;
		}

		words[nextWordPos].orientation = DOWN;

		}

	else if (direction == 2) {
		dstart = d;
		astart = a-i;
		aend = astart + nextWord.a_word.length();

		if (astart < 0 or aend > 14)
			return false;
		if (astart !=0 and aend !=14) {
			if (mainboard[astart-1][d] != '\0' or mainboard [aend+1][d] != '\0'){
				return false;
			}
		}

		dPos = d;
		aPos = astart;

		for (int i = 0; i < nextWord.a_word.length(); i++) {
			if (aPos != a) {
				if (mainboard[aPos][dPos] != '\0' or mainboard[aPos][dPos] != '\0' or mainboard[aPos][dPos+1] != '\0') {
					return false;
				}
			}
			aPos++;
		}

		dPos = d;
		aPos = astart;

		for (int j = 0; j < nextWord.a_word.length(); j++) {
			mainboard[aPos][dPos] = nextWord.a_word[j];
			bboard[aPos][dPos] = true;
			oboard[aPos][dPos] = 1;
			aPos++;
		}

		words[nextWordPos].orientation = ACROSS;
		
		}

		words[nextWordPos].across = astart;
		words[nextWordPos].down = dstart;

		bboard[a][d] = false;

		if (a-1 != -1 and d-1 != -1)
			bboard[a-1][d-1] = false;
		if (d-1 != -1)
			bboard[a][d-1] = false;
		if (a+1 != 15 and d-1 != -1)
			bboard[a+1][d-1] = false;
		if (a-1 != -1)
			bboard[a-1][d] = false;
		if (a+1 != 15)
			bboard[a+1][d] = false;
		if (a-1 != -1 and d+1 != 15)
			bboard[a-1][d+1] = false;
		if (d+1 != 15)
			bboard[a][d+1] = false;
		if (a+1 != 15 and d+1 != 15)
			bboard[a+1][d+1] = false;

		return true;
}


int Board::wordsLeft() {
	int c = 0;
	for (int i = 0; i < words.size(); ++i) {
		if (!words[i].placed){
			c++;
		}
	}

	return c;
}

