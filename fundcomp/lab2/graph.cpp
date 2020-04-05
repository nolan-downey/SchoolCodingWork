//This program outputs the graph of y=5(2-0.5cosx) using the vertical axis as the x axis and the horizontal axis as the y axis from x= 0 to 20.0

#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
cout << fixed << setprecision(1);
double y;
double r;
double x;
double ymin;
double ymax;
ymin = 100;
ymax = 0;


for (x=0.; x <= 20.;x+=.20){
	cout << endl;
	r = 0.5*cos(x);
	y = 5*(2-r);
	cout << setw(4) << right << x << " " << setw(4) << right <<  y;

	if (y>ymax){
		ymax = y;
		}
	
	if (y<ymin){
		ymin = y;
		}

	for (int j =1; j <= y; j+=1){
	cout << "*";
	}
}

cout << endl;

cout << "The graph's maximum is  " << ymax << endl;
cout << "The graph's  minimum is " << ymin << endl;

return 0;
}
