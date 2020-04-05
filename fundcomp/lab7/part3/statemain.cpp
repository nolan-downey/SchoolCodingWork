//Nolan Downey
//main function to perform class States after taking in data file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "state.h"

using namespace std;

int main()
{
//definition of necessary variables
	vector<States>states;
	States st;
	ifstream ifs;
	string filename;
	string ab, nm, cp, pop, year, rep;
	int po, yr, rp;
	int input_var;

//handles the entering in of a data file and making sure it exists
	cout << "Please enter a file name: ";
	cin >> filename;

	ifs.open(filename);

	if (!ifs) {
		cout << "Error opening file " << filename << endl;
		return 1;
	}

//stores all information from the data file into a vector of the class States
	while(ifs.peek()!= EOF) {
		getline(ifs,ab,',');
		getline(ifs,nm,',');
		getline(ifs,cp,',');
		getline(ifs,pop,',');
		getline(ifs,year,',');
		getline(ifs,rep,'\n');
		po = stoi(pop);
		yr = stoi(year);
		rp = stoi(rep);
		st = States(ab,nm,cp,po,yr,rp);
		states.push_back(st);
	}

//handles the user choice from the displayed menu of options
	while (input_var !=6)
	{
		m_display();
		cout << "Please choose an option: ";
		cin >> input_var;
		choice_director(input_var,states);
	}

//displays message if user wants to quit menu
	if (input_var == 6)
	{
		cout << "See Ya Later, Alligator!" << endl;
	}
	
return 0;

}
