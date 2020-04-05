//Nolan D Downey
//Simple Arithmetic Calculator

#include <iostream>
#include <cmath>

using namespace std;

//function prototypes

void addition();
void subtraction();
void multiplication();
void division();
void menu_display();
void choice_director(int);



int main() //main function
{
	int input_var;
	int answer;
	
	input_var = 0;

	while (input_var !=5)
	{

	menu_display();
	cout << "Please enter your choice: ";
	cin >> input_var;
	choice_director(input_var);

	}

	if (input_var==5)
		cout << "See Ya Later!!"<< endl;

	




	return 0;
}

void menu_display() //function to display menu of choices
{
	cout << "1 for Addition" << endl;
	cout << "2 for Subtraction" << endl;
	cout << "3 for Multiplication" << endl;
	cout << "4 for Division" << endl;
	cout << "5 to Quit" << endl;

}

void choice_director(int input_var) //function to direct user's choice to given function
{

		switch (input_var)
			{
				case 1:
					addition();
					break;
				case 2:
					subtraction();
					break;
				case 3:
					multiplication();
					break;
				case 4:
					division();
					break;
				case 5:
					break;
				default:
					cout << "Wrong Number Dummy..." << endl;
					break;
			}

}


void addition() //addition function
{
	int a, b, c;
	cout << "Please enter the first integer: ";
	cin >> a;
	cout << "Please enter the second integer: ";
	cin >> b;
	c = a+b;
	cout << a << " + " << b << " = " << c << endl;
}

void subtraction() //subtraction function
{
	int a, b, c;
	cout << "Please enter the first integer: ";
	cin >> a;
	cout << "Please enter the second integer: ";
	cin >> b;
	c = a - b;
	cout << a << " - " << b << " = " << c << endl;
}

void multiplication() //multiplication function
{
	int a, b, c;
	cout << "Please enter the first integer: ";
	cin >> a;
	cout << "Please enter the second integer: ";
	cin >> b;
	c = a*b;
	cout << a << " * " << b << " = " << c << endl;
}

void division() //division function
{
	int a, b, c;
	cout << "Please enter the first integer: ";
	cin >> a;
	cout << "Please enter the second integer: ";
	cin >> b;
	c = a/b;
	cout << a << " / " << b << " = " << c << endl;
}


