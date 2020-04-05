//rectangle.cpp
//Nolan Downey
#include <iostream>
using namespace std;

float find_perim(float, float);
float find_area(float, float);
void display(float, float);
int main()
{

	float len, wid;
	float perim, area;

	cout << "enter the length: ";
	cin >> len;
	cout << "enter the width: ";
	cin >> wid;

	perim = find_perim(len, wid);
	area = find_area(len,wid);

	display(perim,area);

	return 0;

}

float find_perim(float len, float wid)
{
	float perim;
	perim = 2*(len+wid);

	return perim;
}

float find_area(float len, float wid)
{
	float area;
	area = len*wid;

	return area;
}

void display(float perim, float area)
{

	cout << "The perimeter is: " << perim << endl;
	cout << "The area is: " << area << endl;

}
