//Nolan Downey
//Grade Calculator

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float mean_calc (int []);
float standard_deviation (int[]);

int main()
{
	cout << fixed << setprecision(2);
	float display_mean;
	float display_stddv;
	int grades[50] =
		{ 96,73,62,87,80,63,93,79,71,99,
			82,83,80,97,89,82,93,92,95,89,
			71,97,91,95,63,81,76,98,64,86,
			74,79,98,82,77,68,87,70,75,97,
			71,94,68,87,79, -1};

	display_mean =  mean_calc(grades);

	display_stddv = standard_deviation(grades);

	cout << "The average of those grades is " << display_mean << endl;
	cout << "The standard deviation for the given grades is " << display_stddv << endl;
	
	return 0;
}

float mean_calc (int grades[])
{
	float sum1 = 0.0;
	int z=0;
	float mean;

	while (grades[z] != -1) {
		sum1 += grades[z];
		++z;
		}

	mean = sum1/z;

	return mean;
}

float standard_deviation (int grades[])
{
	float mean2;
	float stddv = 0.0;
	int j=0;
	

	mean2 = mean_calc(grades);
	
	while (grades[j] !=-1){
		stddv += pow(grades[j] - mean2, 2); //Standard Deviation Formula - each number minus mean, then squared
		++j;
	}

	cout << "There are " << j << " grades given." << endl;
	return sqrt(stddv/j); //sum of all averages from beginnning of Standard Deviation Formula, then averaged, then square rooted
}
	
