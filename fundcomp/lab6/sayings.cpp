//Nolan Downey
//program: mysayings.cpp takes in the name of a data file and gives the user option based on  its contents (strings)

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <cctype>

using namespace std;

void display_menu();
void choice_director(int, list<string>&, string);
void sayings_display(list<string>&);
void add_new(list<string>&, string);
void list_sayings(list<string>&);
void new_file(list<string>&);
void remove_choice(list<string>&);

int main()
{
	list<string>sayings;
	ifstream ifs;
	string filename;
	string quotation;
	int input_var;

	cout << "Please enter a file name: ";
	cin >> filename;

	ifs.open(filename); //checks to see if the file exists
	if (!ifs) {
		cout << "Error opening file " << filename << endl;
		return 1;
	}

	getline (ifs, quotation);

	while (!ifs.eof()) { //puts the strings from the data file into a vector of strings
		sayings.push_back(quotation);
		getline (ifs, quotation);
	}

	while (input_var != 6) { //while loop to keep displaying the menu after every option until the exit option is chosen
		display_menu();
		cout << "Please choose an option: ";
		cin >> input_var;
		choice_director(input_var, sayings, filename);
	}

	if (input_var = 6) { //exit option display message
		cout << "See Ya Later, Alligator!" << endl;
	}
	

	return 0;
}

void display_menu() //function containing menu text
{
	cout << "1: Display all sayings currently in the database" << endl;
	cout << "2: Enter a new saying into the database" << endl;
	cout << "3: List sayings that contain a given substring entered by you" << endl;
	cout << "4: Save all sayings in a new text file" << endl;
	cout << "5: Remove a saying from the list" << endl;
	cout << "6: Quit the program" << endl;
}

void choice_director(int input_var, list<string> & sayings, string filename) //function to direct user's choice to a given function
{
	switch (input_var)
		{
			case 1:
				sayings_display(sayings);
				break;
			case 2:
				add_new(sayings, filename);
				break;
			case 3:
				list_sayings(sayings);
				break;
			case 4:
				new_file(sayings);
				break;
			case 5:
				remove_choice(sayings);
				break;
			case 6:
				break;
			default:
				cout << "Wrong Number Dummy..." << endl;
			}
}

void sayings_display(list<string>& sayings) //function to display all strings from the vector of strings
{
	for (auto itr = sayings.begin(); itr != sayings.end(); itr++)
		cout << " - " << *itr << endl;
}

void add_new(list<string>& sayings, string filename) //function to add a new string to the already existing vector of strings and the data file
{
	string n;

	cout << "Please enter the saying you would like to add: ";
	cin.ignore();
	getline (cin, n);

	sayings.push_back(n);

	ofstream ofs;
	ofs.open(filename);
	
	for (auto i=sayings.begin(); i != sayings.end(); i++)
		ofs << *i << endl;

	for (auto itr2 = sayings.begin(); itr2 !=  sayings.end(); itr2 ++) {
		cout << " - " << *itr2 << endl;
	}
}

void list_sayings(list<string> & sayings) //function to locate strings with user inputted substring
{

	string f;

	cout << "Please enter what you would like to find: ";
	cin.ignore();
	getline (cin, f);

 	int z = 0;	
	for (auto it =sayings.begin(); it != sayings.end(); ++it) {
		if ((*it).find(f)) {
			cout << "\"" << *it << "\"" << endl;
			z=1;
			
		}
	}
	
	if (z == 0) {
		cout << "No sayings with this substring were found, sorry :(" << endl;
	}
	cout << endl;
}

void new_file(list<string> & sayings) //function to save existing vector of strings into a data file
{
	ofstream newfile;
	string filename;

	cout << "Please enter the name of the new file: ";
	cin >> filename;

	newfile.open(filename);

	for (auto i= sayings.begin(); i != sayings.end();i++) {
		newfile << *i << endl;
	}

	cout << "New file " << filename << " created." << endl;
}


void remove_choice(list<string> &sayings)
{
	int n = 1;
	for (auto itr2 = sayings.begin(); itr2 != sayings.end(); itr2 ++) {
		cout << " " << n << " " << *itr2 << endl;
		n++;
	}

	int count = 1;
	int choice2;
	cout << "Choose which saying you would like to remove by the number displayed next to said saying" << endl;
	cin >> choice2;
	
	for (auto iter2 = sayings.begin(); iter2 != sayings.end(); iter2++) {
	if (choice2 == count) {
		cout << "Removing \"" << *iter2 << "\" from the list." << endl;
		sayings.remove(*iter2);
		break;
	}
	count++;
}

}
