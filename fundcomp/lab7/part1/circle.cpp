//Nolan Downey
//implementation file for the class 'Circle'

#include <iostream>
#include <cmath>
#include "circle.h"

using namespace std;

double PI = 3.14159;

Circle::Circle() //default constructor leaves radius defined and set to 0, so the circle would have no area or circumference
{
	radius = 0;
}

Circle::Circle(float r)
{
	radius = r;
}

Circle::~Circle() {}

float Circle::getRadius()
{
	cout << radius << endl;
}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::circumference()
{
	return 2*PI*radius;
}

float Circle::area()
{
	return PI*pow(radius,2);
}

void Circle::info()
{
	cout << "  " << "radius: " << radius << endl;
	cout << "  " << "circumference: " << circumference() << endl;
	cout << "  " << "area: " << area() << endl;
}
