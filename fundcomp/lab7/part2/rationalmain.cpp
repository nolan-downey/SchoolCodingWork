// simple driver to test the Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s;

  cout << "*** display a and b ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print();  // recall that c was instantiated with the default constructor

	//denomstration of all get methods of class Rational
	cout << "Numerator of rational number a: " << a.getNumer() << endl;

	cout << "Denominator of rational numer a: " << a.getDenom() << endl;


  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a.add(b);
  s.print();

	cout << "*** compute s as the math difference of a and b, and display s***\n";
	s = a.subtract(b);
	s.print();

	cout <<"*** compute s as the math product of a and b, and display s***\n";
	s = a.multiply(b);
	s.print();

	cout <<"*** computer s as the math quotient of a divided by b, and displays s***\n";

	s = a.divide(b);
	s.print();

 //denomstration of set methods in class Rational
 
 	c.setNumer(5);
	c.setDenom(8);

	cout <<"The new rational number for c is now: ";
	c.print();

  return 0;
}

