//Nolan Downey
//program: letterfreq.cpp

#include <iostream>
#include <list>
#include <cctype>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

void makelower (list <string> &);
void display (vector<string>, vector<int>, int, int, int, float);

int main()
{

	ifstream ifs;
	string input_file, line, zstring, help, help2;
	list <string> file_text;
	vector <string> alphabet = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	vector<int> count (26);
	int j = 0;

	cout << "Please enter the name of the data file: ";
	cin >> input_file;

	ifs.open(input_file);

	if (!ifs) {
		cout << "Uh Oh! That doesn't exist." << endl;
		return 1;
	}

	getline(ifs, line);
	while (!ifs.eof()) {
		file_text.push_back(line);
		getline(ifs, line);
	}

	makelower(file_text);

	int spaces = 0;
	int total = 0;
	int letters = 0;
	for (auto itr = file_text.begin(); itr != file_text.end(); itr++) {
		zstring = *itr;
		spaces++;
		total++;
		total += zstring.size();

		for (auto i = 0; i < zstring.size(); i++) {
			j = 0;

			for (auto itr2 = alphabet.begin(); itr2 != alphabet.end(); itr++) {
				help = zstring[i];
				help2 = *itr2;

				if (help.compare(help2) == 0) {
					letters++;
					count[j]++;
					break;
				}

				else if (isspace(zstring[i])){
					spaces++;
					break;
				}

				j++;
			}
		}
	}

	spaces++;
	total++;

	float a = spaces;
	float b = total;
	float space_percentage = (a/b) *100;

	display (alphabet, count, total, spaces, letters, space_percentage);

	return 0;
}


void makelower(list<string>& file_text)
{
	string temp;
	for (auto itr = file_text.begin(); itr != file_text.end(); itr++) {
		temp = *itr;
		for (int i = 0; i < temp.size(); i++) {
			temp [i] = tolower(temp[i]);
		}
		*itr = temp;
	}
}

void display (vector<string> alphabet, vector<int> count, int total, int spaces, int letters, float space_percentage)
{
	int j = 0, k = 1;

	for(auto itr = alphabet.begin(); itr < alphabet.end(); ++itr) {
		if (k == 6) {
			cout << *itr << ": " << count [j] << endl;
			k = 0;
		}

		else {
			cout << *itr << ": ";
			cout << setw(6) << count[j] << "\t";
		}
		j++;
		k++;
	}

	cout << endl;
	cout << "There are " << letters << " letters in the file." << endl;
	cout << "There are " << total << " characters in the file." << endl;
	cout << "There are " << spaces << " spaces in the file." << endl;
	cout << fixed << setprecision(2);
	cout << "The percentage of white space for this file is: " << space_percentage << "%" << endl;

}
	
