#include <iostream>
#include "rational.h"

using namespace std;

Rational::Rational()
{
	numer = 1;
	denom = 1;
}

Rational::Rational(int n, int d)
{
	numer = n;
	denom = d;
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

void Rational::print()
{
	cout << numer << "/" << denom << endl;
}

Rational Rational::add(Rational a)
{
	return Rational((numer*a.denom) + (denom*a.numer), denom*a.denom);
}

Rational Rational::subtract(Rational s)
{
	return Rational((numer*s.denom) - (denom*s.numer), denom*s.denom);
}

Rational Rational::multiply(Rational m)
{
	return Rational(numer*m.numer, denom*m.denom);
}

Rational Rational::divide(Rational d)
{
	return Rational(numer*d.denom, denom*d.numer);
}
;
