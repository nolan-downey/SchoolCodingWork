// computes the roots of a quadratic equation

#include <iostream>
using namespace std;
#include <cmath>

int main()
{
	double a, b, c, disc;
	double x1, x2;

	cout << "Enter the coeffificents (a,b,c) of a quadratic equation: ";
	cin >> a >> b >> c;

	disc = pow(b,2) - 4*a*c;
	x1 = (-b + sqrt(disc))/(2*a);
	x2 = (-b - sqrt(disc))/(2*a);

	if (disc == 0) {
		cout <<"There is one real solution.\n" << x1 << endl;
		}
	else if (disc >0) {
		cout <<"There is two real solutions.\n" << x2 << " " << x1 << endl;
		}
	else {
		cout <<"There are two imaginary solutions.\n";
		}

	return 0;
}
