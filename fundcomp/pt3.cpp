// pt3.cpp
// playing around with pointers
// refer to class discussion for the main points made
#include <iostream>
using namespace std;

int main()
{
  int n = 11;
  int * p;

  p = &n;

  cout << *p << endl;  
  cout << p << endl;
  cout << &n << endl;
  *p = 7;
  cout << n << endl;

  cout << "-----------\n";

  int a[3] = {23, 21, 28}, * ap = a;
  cout << *ap << endl;
  cout << ap << endl;
  cout << &a[0] << endl;

  cout << "-----------\n";

  char str[20] = "CS and CPEG", * sp = str;
  cout << *sp << endl;
  cout << sp << endl;
  cout << &str[0] << endl;

  return 0;
}

