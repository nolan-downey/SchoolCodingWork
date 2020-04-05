//Nolan Downey
//this program gives options based on past Notre Dame football records

#include <iostream>
#include "nd_data.h"
using namespace std;

//function prototypes
void show_record();
void min_wins();
void min_losses();
void winning_season();
void losing_season();
void undefeated();
void menu_display();
void choice_director(int);
int size = (sizeof(wins)/4);

int main()
{
	int input_var;
	
	while (input_var != 7)
	{
		menu_display();
		cout << "Please enter your choice: ";
		cin >> input_var;
		choice_director(input_var);
	}

	if (input_var = 7)
	{
		cout << "See Ya Later!!" << endl;
		}

return 0;
}

void menu_display() //function display the menu of options
{
	cout << "1: Display record for a specific year" << endl;
	cout << "2: Display seasons with at least 'n' wins" << endl;
	cout << "3: Display seasons with at least 'n' losses" << endl;
	cout << "4: Display seasons with a winning record" << endl;
	cout << "5: Display seasons with a losing record" << endl;
	cout << "6: Display seasons with an uNDefeated record" << endl;
	cout << "7: Exit the menu" << endl;
}

void choice_director(int input_var) //function to direct user's choice to a given function
{
	switch (input_var)
		{
			case 1:
				show_record();
				break;
			case 2:
				min_wins();
				break;
			case 3:
				min_losses();
				break;
			case 4:
				winning_season();
				break;
			case 5:
				losing_season();
				break;
			case 6:
				undefeated();
			case 7:
				break;
			default:
				cout << "Wrong Number Dummy..." << endl;
				break;
		}
}

void show_record() 
{
	int i;
	cout << "Please enter the year you would like to see the record of: ";
	cin >> i;

	cout << "The record for " << i << " was " << wins[i-1900] << " wins and  " << losses[i-1900] << " losses. " << endl;

}

void min_wins()
{
	int i;
	cout << "Please enter a minimum number of wins: ";
	cin >> i;

	for (int w = 0; w < size; ++w) {
		if (wins[w] > i)
			cout << w+1900 << " ";
	}
	cout << endl;	
}

void min_losses()
{
	int i;
	cout << "Please enter a minimum number of losses: ";
	cin >> i;

	for (int w = 0; w<size; ++w){float add(float a, float b)
{ return (a+b); }

float subtract(float a, float b)
{ return (a-b); }

float multiply(float a, float b)
{ return (a*b); }

		if (losses[w] > i)
			cout <<w+1900 << " ";
	}
	cout << endl;
}

void winning_season()
{
 	int i;
	cout << "Every year that ended as a winning season: ";
	for (int w = 0; w<size; ++w) {
		if (wins[w] > losses[w])
			cout << w+1900 << " ";
	}
	cout << endl;
}

void losing_season()
{
	int i;
	cout << "Every year that ended as a losing season: ";
	for (int w = 0; w<size; ++w) {
		if(wins[w] < losses[w])
			cout << w+1900 << " ";
	}
	cout << endl;
}

void undefeated()
{
	int i;
	cout << "Every year that ended as an undefeated season: ";

	for (int w = 0; w<size; ++w){
		if (wins[w]!=0 and losses[w]==0)
			cout << w+1900 << " ";
	}
	cout << endl;
}
