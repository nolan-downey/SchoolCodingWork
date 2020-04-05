//Nolan Downey
//lifeboard.cpp

#include <iostream>
#include <string>
using namespace std;

#include "lifeboard.h"

Life::Life()
{
	for (int i = 0; i < SZ; i++) {  //initializes a blank board
		mainboard[0][i] = '-';
		tempboard[0][i] = '-';
		mainboard[41][i] = '_';
		tempboard[41][i] = '-';
	}
	for (int i = 1; i < SZ - 1; i++) {
		mainboard[i][0] = '|';
		tempboard[i][0] = '|';
		mainboard[i][41] = '|';
		tempboard[i][41] = '|';
	}

	for (int i = 1; i < SZ-1;i++) {
		for (int j = 1; j < SZ-1;j++) {
			mainboard[i][j] = BLANK;
			tempboard[i][j] = BLANK;
		}
	}
}


Life::~Life() {}

	
int Life::cellneighbors(int y, int z) //checks the surrounding neighbors of the current cell
{
	int neighbor = 0;

	if (mainboard[y-1][z-1] == ALIVE)
		neighbor++;
	if (mainboard[y][z-1] == ALIVE)
		neighbor++;
	if (mainboard[y-1][z] == ALIVE)
		neighbor++;
	if (mainboard[y-1][z+1] == ALIVE)
		neighbor++;
	if (mainboard[y+1][z-1] == ALIVE)
		neighbor++;
	if (mainboard[y+1][z] == ALIVE)
		neighbor++;
	if (mainboard[y][z+1] == ALIVE)
		neighbor++;
	if (mainboard[y+1][z+1] == ALIVE)
		neighbor++;


	return neighbor;
}


void Life::clearscreen()
{
	system("clear");
}

void Life::display() //copies the mainboard to equal the temporary board, then displays the mainboard
{
	for (int x = 0; x < SZ; x++)
		for (int y = 0; y < SZ; y++)
			mainboard[x][y] = tempboard[x][y];

	for (int i = 0; i < SZ; i++) {
		for (int j=0; j < SZ; j++) {
			cout << mainboard[i][j];
		}
		cout << endl;
	}
}

void Life::addcell(int a, int b) //adds an ALIVE cell to the chosen spot
{
	if (checkboard(a,b))
		tempboard[a][b] = ALIVE;
	else
		cout << "Not in the bounds of the board!" << endl;
}

void Life::removecell(int c, int d) //makes a certain cell DEAD
{
	if (checkboard(c,d))
		tempboard[c][d] = DEAD;
	else
		cout << "Not in the bounds of the board!" << endl;
}

void Life::advance() //iterates once through the simulation based on the rules described in the report and lab description
{

	for (int i = 1; i < SZ-1; i++)
	{
		for (int j = 1; j < SZ-1; j++)
		{
			int neighbors = cellneighbors(i,j);

			if (neighbors < 2)
				tempboard[i][j] = DEAD;
			else if (neighbors > 3)
				tempboard[i][j] = DEAD;
			else if (neighbors == 3)
				tempboard[i][j] = ALIVE;
			else if (neighbors == 2 and mainboard[i][j] == ALIVE)
				tempboard[i][j] = ALIVE;
			else if (neighbors == 3 and mainboard[i][j] == ALIVE)
				tempboard[i][j] = ALIVE;
			else
				tempboard [i][j] = BLANK;
			}
		}

		display();
}

bool Life::checkboard(int x, int y) //checks to see if a chosen cell is inside the board
{
	return ((x>=0 and x < SZ) and (y>=0 and y < SZ));
}
