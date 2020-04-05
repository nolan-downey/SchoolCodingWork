//Nolan Downey
//Function to produce radius and angle to a given point, along with which quadrant the given point is located

#include<iostream>
#include<cmath>

using namespace std;

double get_radius(double,double);
double get_angle(double, double);
void quadrant_info(double, double);

int main() //main function
{
	double x, y;
	cout << "Please enter the x-coordinate: ";
	cin >> x;
	cout << "Please enter the y-coordinate: ";
	cin >> y;
	cout << "The radius to the given  point is " << get_radius(x,y) << endl;
	cout << "The angle to the given point is " << get_angle(x,y) << endl;
	quadrant_info(x,y);


return 0;

}


double get_radius(double x, double y) //function defined to find length of radius
{

	double radius;
	radius = sqrt(x*x+y*y);
	return radius;

}

double get_angle(double x, double y) //function defined to find angle to the given point
{

	double angle;
	angle = atan2(x,y);
	angle = angle*180/M_PI;

	if (angle<0)
		angle = angle+360;

	return angle;

}

void quadrant_info(double x,double y) //function to tell user which quadrant the given point is located
{

	if ((x==0) and (y!=0))
		cout << "The point is on the y-axis." << endl;
	else if ((y==0) and (x!=0))
		cout << "The point is on the x-axis." << endl;
	else if ((x==0) and (y==0))
		cout << "The point is on the origin." << endl;
	else if ((x>0) and (y>0))
		cout << "The specified point is in quadrant I." << endl;
	else if ((x<0) and (y>0))
		cout << "The specified point is in quadrant II." << endl;
	else if ((x<0)and (y<0))
		cout << "The specified point is in quadrant III." << endl;
	else
		cout << "The specified point is in quadrant IV." << endl;

}

