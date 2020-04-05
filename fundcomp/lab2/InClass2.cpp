// this code computes and displays the sum of the squares of numbers 1 through 10 and the sum of the square roots of numbers 1 through 10


#include <iostream>
using namespace std;
#include <cmath>

int main()
{

	int sum1,sum2,i;
	sum1 = 0;
	sum2 = 0;
	for (int i = 1; i <= 10; i = i+1){
		sum1 = sum1 + pow(i,2);
		sum2 = sum2 + sqrt(i);
		}

	cout << sum1 << " " << sum2 << endl;


	return 0;
}
