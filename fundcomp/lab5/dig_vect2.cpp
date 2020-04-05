//Nolan Downey
//Prog: dig_vect2.cpp

#include <iostream>
#include <vector>
using namespace std;

void find_freq(vector<int>,vector<int>&);
void results(vector<int>);

int main()
{
	vector<int>digit = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};

	vector<int>freq(10,0);

	find_freq(digit,freq);
	results(freq);

	return 0;

}

void find_freq(vector<int> digit, vector<int>&freq)
{
	for(int j =0; j<10;j++) {
		for (auto itr = digit.begin(); itr <digit.end(); itr++){
			if (*itr == j) {
				freq[j]+=1; //uses iterators to go through the vector <int> digit to allocate the frequency of each digit 0-9
			}
		}
	}
}

void results(vector<int> freq)
{
	for (auto itr = freq.begin(); itr <freq.end(); itr++)
		cout << "digit " << (itr - freq.begin()) << " occurs " << *itr << " times" << endl; //displays the frequency of each digit 0-9
}

