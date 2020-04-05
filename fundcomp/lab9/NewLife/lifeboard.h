//Nolan Downey
//lifeboard.h
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

const int SZ = 42; //actual size of the board is 40*40, but has to be 42 to include the border
const char ALIVE = 'X';
const char DEAD = ' ';
const char BLANK = ' ';

class Life
{
	public:
		Life();
		~Life();
		int cellneighbors(int,int);
		void clearscreen();
		void display();
		void addcell(int,int);
		void removecell(int,int);
		void advance();
		bool checkboard(int, int);
	private:
		char tempboard[SZ][SZ];
		char mainboard[SZ][SZ];
};


