#include <iostream>
#include "rational.h"

using namespace std;

Rational::Rational()
{
	setRational(1,1);
}

Rational::Rational(int n, int d)
{
	setRational(n,d);
	
}

Rational::~Rational() {}

int Rational::getNumer()
{
	return numer;
}

int Rational::getDenom()
{
	return denom;
}

void Rational::setNumer(int n)
{
	numer = n;
}

void Rational::setDenom(int d)
{
	denom = d;
}

void Rational::setRational(int n, int d)
{
	numer = n;
	denom = d;
}


Rational Rational::operator+ (Rational a)
{
	Rational z = Rational((numer*a.denom) + (denom*a.numer), denom*a.denom);
	simplify(z);

	return z;
}

Rational Rational::operator- (Rational s)
{
	Rational z = Rational((numer*s.denom) - (denom*s.numer), denom*s.denom);

	simplify(z);

	return z;
}

Rational Rational::operator* (Rational m)
{
	Rational z = Rational(numer*m.numer, denom*m.denom);

	simplify(z);

	return z;
}

Rational Rational::operator/ (Rational d)
{
	Rational z = Rational(numer*d.denom, denom*d.numer);

	simplify(z);
	

	return z;
}

void Rational::simplify(Rational & r)
{
	int gcd = findGCD(r.numer,r.denom);

	r.numer /= gcd;
	r.denom /= gcd;

	r.sign();

}

void Rational::sign()
{
	if (denom < 0) { //if statement to make negative sign display in front of numerator to make whole rational number display negative
		numer *= -1;
		denom *= -1;
	}
}

int Rational::findGCD(int n, int d)
{
	
	int temp;
	//GCD algorithim
	while (d!=0)
	{
		temp = n%d;
		n = d;
		d = temp;
	}
	
	return n;
	}

ostream & operator<< (ostream & os, Rational &r)
{
	

	if (r.denom == 0)
		os  << "The rational number is Undefined because the denominator is 0." << endl;
	else if (r.numer == 0)
		os << "The rational number equals 0." << endl;
	else 
		os << "The rational number is: " << r.numer << "/" << r.denom << endl;
	
	return os;

}

istream & operator>> (istream & is, Rational &r)
{
	int a, b;

	
	cout << "Please enter a numerator and denominator: " << endl;
	is >> a >> b;
	
	r.setRational(a,b);

	return is;
}
;
