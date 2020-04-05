// pt2.cpp
// similar to pt1.cpp, but with an array of char's (C string)

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char str[11] = "Notre Dame";

  // normal way, with an index
 
  for (int i = 0; i < strlen(str); i++)
    cout << str[i] << " ";
  cout << endl;

  // with a pointer
 
  char * p = str;

  while (*p != '\0') {
    cout << *p << " ";
    p++;
  }
  cout << endl;

  return 0;
}

