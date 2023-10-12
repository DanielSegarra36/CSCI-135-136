/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 12

  This program takes two, and only two, command line arguments.
    - It sets every element of an array to equal the first argument.
    - A second, dynamically-allocated array is made as an
      exact copy of the first array.
    - Then the array element coinciding with the second argument is changed.
      i.e.
        ./program 5 0
        This would set all elements of an array to equal 5 and then change the 0th element.
    - Array ONE is printed with a change to the element equal to the second argument.
    - Array TWO is printed with a change to the first element.
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXSIZE = 16;

static int values[MAXSIZE]; // static? array of size 16
static int i;  // bad idea to call a global variable i!

void initArray(int[], int);
void printArray(int[]);
// This initializes element arr[i] to val for each array element
void initArray(int arr[], int val) // takes array and int value
{
  for (i=MAXSIZE; i >= 0; i--) // from 16 to 0
    arr[i] = val; // sets each element to the value "val"
  return;
}
// This prints the contents of the argument array, with each element printed as "index: value" on its own line
// For example, a 4-element array containing {10,11,12,13} would print as:
  //   0: 10
  //   1: 11
  //   2: 12
  //   3: 13
void printArray(int arr[]) // array argument
{
  for (int count=0; count<MAXSIZE;count++)
    cout << setw(2) << count << ": " << arr[count] << endl;
};
//int main()
int main(int argc, char * argv[])
{

  // TASK 0
  // The pointer arr2 was not a seperate array but simply pointing to an existing array (values).

   // TASK 1
  if (argc == 3)
  {
    int dummy;
    initArray(values,atoi(argv[1]));
    int *arr2 = new int[MAXSIZE]; // arr2 has been dynamically allocated as its own array
    for (int count=0; count<MAXSIZE; count++)
      arr2[count] = values[count]; // set each element of arr2 = values (every element is five)
    values[atoi(argv[2])]=9; // VALUES: change element 0 to 9 (all other elements are 5s)
    arr2[1]=8; // ARR2: change element 1 to 8 (all other elements are 5s)
    cout << "values is:" << endl;
    printArray(values);
    cout << endl << "arr2 is:" << endl;
    printArray(arr2);
  }
  else exit(1);
};
