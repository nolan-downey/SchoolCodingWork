//Nolan Downey
//program: states1.cpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line1;
	string line2 = "notre dame fighting irish";
	vector<string>states = {"Indiana","Michigan","Ohio","Illinois","Iowa"};

	cout << "Please enter a line: ";
	getline(cin,line1);

	cout << "The first line is: " << line1 << endl;
	cout << "The second line is: " << line2 << endl;

	cout<< "The states are: " << endl;
	for (int i = 0; i < 5; i++)
		cout << " - " << states[i] << endl;
	

	cout << "Displaying the states with a space between each letter: " << endl; //uses C++ strings and their methods to output the intended output
	for (int i = 0; i<states.size();i++) {
		cout << " - ";
		for (int j = 0; j < states.at(i).length(); j++) {
			cout << states[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
		
