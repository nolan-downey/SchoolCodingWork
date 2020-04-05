//Nolan Downey
//Program dig_vect1.cpp

#include <iostream>
#include <vector>
using namespace std;

void find_freq(vector<int>, vector<int>&, int);
void results(vector<int>, int);
int main()
{
	vector<int>digit = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};
	
	int size = digit.size();
	vector<int>freq(10,0);

	find_freq(digit, freq, size);
	results(freq, size);


	return 0;
}

void find_freq(vector<int> digit, vector<int> &freq, int size)
{
	for (int j = 0; j<10; j++)
		for (int i=0; i<size; i++) {
			if (digit[i] == j) {
				freq[j]+=1; //uses indexing to go  through the vector to add the frequency of each digit 0-9
			}
		}
	}

void results(vector<int>freq, int size)
{
	for (int n =0; n<= 9; n++)
		cout << "digit " << n << " occurs " << freq[n] << " times" <<endl; //displays the results of the above function

}


