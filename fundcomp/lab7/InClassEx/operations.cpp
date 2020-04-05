#include <iostream>
#include <cmath>
using namespace std;

float add(float, float);
float subtract(float, float);
float multiply(float, float);

int main()
{
  float x, y;

  cout << "enter two non-zero numbers: ";
  cin >> x >> y;

  cout << "their sum is " << add(x,y) << endl;
  cout << "their difference is " << fabs(subtract(x,y)) << endl;
  cout << "their product is " << multiply(x,y) << endl;

  return 0;
}

float add(float a, float b)
{ return (a+b); }

float subtract(float a, float b)
{ return (a-b); }

float multiply(float a, float b)
{ return (a*b); }

