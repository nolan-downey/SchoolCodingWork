//This program outputs a multiplication table of a desired number of rows/columns
//Nolan Downey

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
//Asking the users input on number of rows and columns

	int x;
	int y;

	cout << "Please enter the number of rows: " << endl;
	cin >> y;

	cout << "Please enter the number of columns: " << endl;
	cin >> x;

//Creating the first line of the table

	cout << "  *   ";

	for (int h = 1; h <= x;h=h+1) {
		cout << h << " ";
		cout << setw(3);
		}

//Creating the rest of the table

	for (int i = 1; i <= y;i=i+1) {
		
		cout << endl;
		cout << i << " ";
		cout << setw(3);
			
			for (int j = 1; j <= x; j=j+1) {
				cout << i*j << " ";
				cout << setw(3);
			}
			}

	cout << endl;
			

return 0;

}
