#include <iostream>
#include <cstdlib>
using namespace std;

int main (int argc, char *argv[])
{
	int x,y,a,b;

	if (argc == 1) {
		cout << "Please enter two integers: ";
		cin >> x >> y;
		cout << "The sum of your integers is: " << x+y << endl;
	}
	else if (argc > 3){
		cout << "Two many numbers!" << endl;
		return 1;
	}
	else {
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		cout << "The sum of your integers is: " << a+b << endl;
		}
	
	return 0;
}
