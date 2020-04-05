//Nolan Downey
//ec1.cpp

#include <iostream>
using namespace std;

//pre-code analysis
//8 and 9 pandigital numbers are never prime
//highest number pandigital prime is up to 7
//checks different pandigital numebers with 7 digits

bool prime(int);
bool order(int,int,int);

int main()
{
	order(7,0,0);

	return 0;
}

bool prime(int p)
{
	for (int z = 2; z*z<= p; z++)
	{
		if (p%z == 0)
			return false;
	}
	
	return true;
}

bool order(int length, int mid, int num)
{
	if (length == 0 and prime(num))
	{
		cout << num << endl;
		return true;
	}

	for (int i = 7 - 1; i >= 0; i--)
		{
			if (mid & (1 << i))
				continue;
			if (order(length - 1, mid + (1 << i), num*10 + i + 1))
				return true;
		}

	return false;
}
