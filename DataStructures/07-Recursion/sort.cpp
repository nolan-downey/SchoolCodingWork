/**********************************************
* File: sort.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*
* Contains the code to teach students about MergeSort
**********************************************/
#include <iostream>
#include <cstdlib>		// exit function


/********************************************
* Function Name  : Merge
* Pre-conditions : char* charArr, long unsigned int left, long unsigned int middle, long unsigned int right
* Post-conditions: none
*
* Contains the Merge function for MergeSort
********************************************/
void Merge(char* charArr, long unsigned int left, long unsigned int middle, long unsigned int right)
{
    long unsigned i, j, k;
    long unsigned n1 = middle - left + 1;
    long unsigned n2 =  right - middle;

    /* create temp arrays */
    char* Left = new char[n1];
	char* Right = new char[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        Left[i] = charArr[left + i];
	}

    for (j = 0; j < n2; j++){
        Right[j] = charArr[middle + 1+ j];
	}

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            charArr[k] = Left[i];
            i++;
        }
        else
        {
            charArr[k] = Right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        charArr[k] = Left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        charArr[k] = Right[j];
        j++;
        k++;
    }

	delete Left;
	delete Right;
}


// Student Solution goes here
void MergeSort(char* charArray, long unsigned int left, long unsigned int right) {

  if (left == right)
    return;

  if (right > 1){

    long unsigned int middle = (left + right)/2;
    MergeSort(charArray, left, middle);
    MergeSort(charArray, middle+1, right);
    Merge(charArray, left, middle, right);

  }
}


long unsigned int getStringLen(char* string){

    long unsigned int i;

	// Iterate while the string !=
    for(i=0; string[i] != '\0'; i++)
		;	// Loops and does nothing

    return i;
}


int main(int argc, char** argv)
{
  if (argc != 2) {
      exit(-1);
  }
	// Student Solution Goes Here
  long unsigned int n = getStringLen(argv[1]);

  MergeSort(argv[1], 0, n-1);

  std::cout << argv[1] << std::endl;

	return 0;
}
