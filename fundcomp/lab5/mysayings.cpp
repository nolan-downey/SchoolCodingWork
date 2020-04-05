//Nolan Downey
//program: mysayings.cpp takes in the name of a data file and gives the user option based on  its contents (strings)

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void display_menu();
void choice_director(int, vector<string>&, string);
void sayings_display(vector<string>&);
void add_new(vector<string>&, string);
void list_sayings(vector<string>&);
void new_file(vector<string>&);

int main()
{
	vector<string>sayings;
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

	while (input_var != 5) { //while loop to keep displaying the menu after every option until the exit option is chosen
		display_menu();
		cout << "Please choose an option: ";
		cin >> input_var;
		choice_director(input_var, sayings, filename);
	}

	if (input_var = 5) { //exit option display message
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
	cout << "5: Quit the program" << endl;
}

void choice_director(int input_var, vector<string> & sayings, string filename) //function to direct user's choice to a given function
{
	switch (input_var)
		{
			case 1:
				sayings_display(sayings);
				break;
			case:
				add_new(sayings, filename);
				break;
			case 3:
				list_sayings(sayings);
				break;
			case 4:
				new_file(sayings);
				break;
			case 5:
				break;
			default:
				cout << "Wrong Number Dummy..." << endl;
			}
}

void sayings_display(vector<string>& sayings) //function to display all strings from the vector of strings
{
	for (auto itr = sayings.begin(); itr < sayings.end(); itr++)
		cout << " - " << *itr << endl;
}

void add_new(vector<string>& sayings, string filename) //function to add a new string to the already existing vector of strings and the data file
{
	string n;

	cout << "Please enter the saying you would like to add: ";
	cin.ignore();
	getline (cin, n);

	sayings.push_back(n);

	ofstream ofs;
	ofs.open(filename);
	
	for (int i=0; i <sayings.size(); i++)
		ofs << sayings.at(i) << endl;

	for (auto itr2 = sayings.begin(); itr2 < sayings.end(); itr2 ++) {
		cout << " - " << *itr2 << endl;
	}
}

void list_sayings(vector<string> & sayings) //function to locate strings with user inputted substring
{

	string f;

	cout << "Please enter what you would like to find: ";
	cin.ignore();
	getline (cin, f);

	int z = 0;
	for (int i=0; i < sayings.size(); ++i) {
		if (sayings.at(i).find(f) <= 256) {
			cout << "\"" << sayings.at(i) << "\"" << endl;
			z = 1;
		}
	}
	
	if (z == 0) {
		cout << "No sayings with this substring were found, sorry :(" << endl;
	}
	cout << endl;
}

void new_file(vector<string> & sayings) //function to save existing vector of strings into a data file
{
	ofstream newfile;
	string filename;

	cout << "Please enter the name of the new file: ";
	cin >> filename;

	newfile.open(filename);

	for (int i = 0; i <sayings.size();i++) {
		newfile << sayings[i] << endl;
	}

	cout << "New file " << filename << " created." << endl;
}


	
