/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 9

  This program:
  0. Asks the user for the coefficients of a polynomial
    and stores them in an array.
  1. It then evaluates the polynomial at a given x value.
  2. Find smallest value of x for which either p1>p2 or vise versa
      whichever happens first
*/

#include <iostream>
#include <cmath> // for pow()
using namespace std;

double *polyCoefficients(int);
// Post: Stores coefficients of a polynomial in a dynamic array and returns
//        said array.
double eval(double * poly, int degree, double x);
// Post: Evaluates a polynomial at a given value, x, and returns answer.
void largerPoly(double *p1, int p1Deg, double *p2, int p2Deg);
// Post: Finds and returns smallest x value for which either p1>p2 or vise vera
/***************************************************************************/
int main(){
  // TASK 0 - store coefficients in array
  int deg;
  cout << "Enter polynomial degree: ";
  cin >> deg;
  double *coefficientArr = polyCoefficients(deg); // dynamic array of poly coefficients
/***************************************************************************/
  // TASK 1 - Evaluate polynomial @ given x value
  double userX;
  cout << "Evaluate polynomial with: ";
  cin >> userX;
  double answer = eval(coefficientArr, deg, userX); // polynomial evaluated @ given x value
  cout << answer << endl;
  delete [] coefficientArr;
  coefficientArr = nullptr;
/***************************************************************************/
  // TASK 2 - find smallest value of x for which either p1>p2 or vise versa
  // POLYNOMIAL ONE
  int p1Deg;
  cout << "Enter first polynomial degree: ";
  cin >> p1Deg;
  double *p1 = polyCoefficients(p1Deg); // dynamic array of p1 coefficients
  // POLYNOMIAL TWO
  int p2Deg;
  cout << "Enter second polynomial degree: ";
  cin >> p2Deg;
  double *p2 = polyCoefficients(p2Deg); // dynamic array of p2 coefficients
  largerPoly(p1, p1Deg, p2, p2Deg);
  delete [] p1;
  p1 = nullptr;
  delete [] p2;
  p2 = nullptr;
}
/*
TASK 3 - accessing data once pointer has been deleted
  This results in Segmentation fault: 11
  which is an attempt at accessing data not available to use
TASK 4 -- accessing elements out of bounds of array
  just displays zeroes after actual array elements have been printed
*/
double *polyCoefficients(int degree){
  double coefficient;

  double *pointer;
  pointer = new double[degree+1];

  while(degree>=0){
    cout << "Enter coefficient of term " << degree << ": ";
    cin >> coefficient;
    if (cin.eof()){
      while(degree>=0) // While not at array[0]
      {
        pointer[degree]=0; // Set remaining elements to 0
        degree--;
      }
    }else{
      pointer[degree]=coefficient;
      degree--;
    }
  }
  return pointer;
}

double eval(double * poly, int degree, double x){
  double total=0;

  for(int count=1;count<=degree;count++) // Use count as array element and degree of x
    total += ( poly[count] * (pow(x,count)) ); // coefficient * (x^degree); e.i. 3x^2

  total+=poly[0]; // add constant

  return total;
}

void largerPoly(double *p1, int p1Deg, double *p2, int p2Deg){
  double p1Answer;
  double p2Answer;
  int x = 0; // Incrementing x value for both polynomials

  do {
    p1Answer = eval(p1, p1Deg, x); // Evaluate p1 @ x
    p2Answer = eval(p2, p2Deg, x); // Evaluate p2 @ x
    if (p2Answer>p1Answer)
      cout << "A positive integral, x0, such that p2(x0)>p1(x0) is: " << x << endl;
    else if (p1Answer>p2Answer)
      cout << "A positive integral, x0, such that p1(x0)>p2(x0) is: " << x << endl;
    else x++;
  } while((p1Answer<p2Answer)&&(p2Answer<p1Answer));
}
