//this code serves to return the force of gravity from given inputs
//Nolan Downey - prog3.cpp

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float mone;
	cout << "Please enter the mass of the first object in kg: ";
	cin >> mone;
	float mtwo;
	cout << "Please enter the mass of the second object in kg: ";
	cin >> mtwo;
	float r;
	cout << "Please enter the distance between these objects in m: ";
	cin >> r;
	float a;
	a = mone*mtwo;
	a = a*0.00000000006674;
	a = a/(r*r);
	cout << "The force of gravity is: " << a << " Newtons.\n";
	return 0;
}
