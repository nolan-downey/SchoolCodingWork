//This program takes two integers and finds the GCD
//Nolan Downey
#include <iostream>
#include <cmath>
using namespace std;

int getgcd (int, int);

int main()
{

	int a;
	int b;

	cout << "Please enter the first integer: ";
	cin >> a;
	cout << "Please enter the second integer: ";
	cin >> b;
	cout << "The GCD of those two integrs is " << getgcd(a,b) << endl;

	return 0;
}

int getgcd(int a, int b)
{
	
	if (a==0)
		return b;
	if (b==0)
		return a; //check to see if either integer is 0

	if (a==b)
		return a; //check to see if integers are equal

	if (a>b)
		return getgcd(a-b,b); //GCD doesn't change if smaller number is subtracted from bigger number
	
	return getgcd(a,b-a);//recursive algorithim that continually runs until one integer equals 0

	//Euclidean Algorithim was used as foundation for this code

}
