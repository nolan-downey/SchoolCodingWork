//Football Score Formula
//Nolan Downey - prog2.cpp

#include <iostream>
using namespace std;

int main()
{
int t;
cout << "Please enter number of touchdowns:";
cin >> t;
int ep;
cout << "Please enter the number of extra points:";
cin >> ep;
int fg;
cout << "Please enter the number of field goals:";
cin >> fg;
int s;
cout << "Please enter the number of safeties:";
cin >> s;
cout << "The Irish scored " << 6*t+ep+3*fg+2*s << " points.\n";
return 0;
}
