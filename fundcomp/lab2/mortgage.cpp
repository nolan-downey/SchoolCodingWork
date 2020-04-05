//This program displays how long it takes to pay off a mortage given a specific principal, interest rate, and desired monthly payment
//Nolan Downey

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
//Defining variables and asking for inputs
	cout << fixed << setprecision(2);
	float principal;
	float rate;
	float dmp;

	cout << "Please enter the principal amount: " << endl;
	cin >> principal;
	cout << endl;

	cout << "Please enter the interest rate: " << endl;
	cin >> rate;
	cout << endl;

	cout << "Please enter the desired monthly payment: " << endl;
	cin >> dmp;
	cout << endl;

	if (principal <= 0){
		cout << "Error: Principal too low.\n";
		}
	else if (rate <= 0){
		cout << "Error: Invalid rate.\n";
		}
	else if (dmp <= 0){
		cout << "Error: Desired monthly payment too low.\n";
		}		

	cout <<"Month" << setw(15) << right << "Payment" << setw(14) << right <<  "Interest"<< setw(14) << right << "Balance" << endl;

	int month;
	float interest;
	float balance;
	float finalp;
	
	rate = rate/100;
	month = 1;
	interest = rate/12 * principal;
	balance = principal;

	while (balance > 0) {
		if (balance < dmp){
			interest = rate/12*balance;
			finalp = balance+interest;
			balance = 0;
			cout << setw(6) << left << month;
			cout << setw(5) << right << "$";
			cout << setw(9) << right << finalp;
			cout << setw(5)<< right << "$";
			cout << setw(9)<< right << interest;
			cout << setw(5) << right << "$";
			cout << setw(9) << right << balance << endl;

			}
		else {
		interest = rate/12*balance;
		balance = balance + interest - dmp;
			if (balance >principal){
				cout << "You will never pay off your mortgage.";
				break;
				}
		
		cout<< setw(6) << left << month;
		cout << setw(5) << right << "$";
		cout << setw(9) << right << dmp;
		cout << setw(5) << right << "$";
		cout << setw(9) << right << interest;
		cout << setw(5) << right << "$";
		cout << setw(9) << right <<  balance << endl;
		month = month + 1;
		}
	}	

cout << "You paid a total of $" << (month-1)*dmp + finalp << " over " << month/12 << " years and " << month%12 << " months.\n";

return 0;
}
