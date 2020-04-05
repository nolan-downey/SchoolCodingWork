// simple driver to test the Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a, b, c, s;

	cin >> a;
	cin >> b;

	a.simplify(a);	//demonstration of simplify method
	b.simplify(b);

  cout << "*** display a and b ***\n";
  cout << a;
  cout << b;
  cout << "*** display c ***\n";
  cout << c;  // recall that c was instantiated with the default constructor

	//denomstration of all get methods of class Rational
	cout << "Numerator of rational number a: " << a.getNumer() << endl;


	cout << "Denominator of rational numer a: " << a.getDenom() << endl;


  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a+b;
	cout << s;

	cout << "*** compute s as the math difference of a and b, and display s***\n";
	s = a-b;
	cout << s;

	cout <<"*** compute s as the math product of a and b, and display s***\n";
	s = a*b;
	cout << s;

	cout <<"*** computer s as the math quotient of a divided by b, and displays s***\n";

	s = a/b;
	cout << s;


  return 0;
}

