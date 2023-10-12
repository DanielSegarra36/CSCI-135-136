/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 4

  This program does computes C(n,k) "n choose k" in two different ways.
  The different equations are to allow larger numbers to be calculated.
*/

#include <iostream>
using namespace std;

int Factorial(int x);

int main (){
	int n,k;

/*1*/
	cout << "PART ONE\n";
	cout << "For the following program we will be using this formula:\n\n";
	cout << "C(n,k) = n! / (k! * (n-k)!)\n\n";
	cout << "Where n>=0\n";
	cout << "and\n";
	cout << "0<=k<=n\n\n";
	
	cout << "Choose a number greater than or equal to zero for n: ";
	cin >> n;
		while(n<0){
			cout << "INVALID CHOICE\n";
			cout << "TRY AGAIN\n";
			cout << "Choose a number greater than or equal to zero: ";
			cin >> n;
		}
	cout << "For k, choose a number greater than or equal to zero and less than or equal to n: ";
	cin >> k;
		while(k<0 || k>n){
			cout << "INVALID CHOICE\n";
			cout << "TRY AGAIN\n";
			cout << "Choose a number greater than or equal to zero and less than or equal to n: ";
			cin >> n;
		}
	int dif = n-k;

	cout << n << "! is: " << Factorial(n) << endl;
	cout << k << "! is: " << Factorial(k) << endl;
	cout << dif << "! is: " << Factorial(dif) << endl;
	cout << "C(n,k) = " << (Factorial(n))/((Factorial(k))*(Factorial(dif))) << endl;

/*2*/
	cout << "\n\n\n\n\n";
	cout << "PART TWO\n";
	cout << "For the following program we will be using this formula:\n\n";
	cout << "C(n,k) = n(n-1)(n-2)...(n-k+1)/k!\n\n";
	cout << "Where n>=0\n";
	cout << "and\n";
	cout << "0<=k<=n\n\n";
	
	cout << "Choose a number greater than or equal to zero for n: ";
	cin >> n;
		while(n<0){
			cout << "INVALID CHOICE\n";
			cout << "TRY AGAIN\n";
			cout << "Choose a number greater than or equal to zero: ";
			cin >> n;
		}
	cout << "For k, choose a number greater than or equal to zero and less than or equal to n: ";
	cin >> k;
		while(k<0 || k>n){
			cout << "INVALID CHOICE\n";
			cout << "TRY AGAIN\n";
			cout << "Choose a number greater than or equal to zero and less than or equal to n: ";
			cin >> n;
		}
	
	
	for(int i=1, w=n; i<=k+1; i++){
		if((w-i)==0){
			n *= 1;
		}else{
			n *= (w-i);
		}
	}
	cout << "C(n,k) = " << n/Factorial(k) << endl;
}

int Factorial(int x){
	if(x==1){
		return 1;
	}
	else{
		return x * Factorial(x-1);
	}
}

/*
1.	Thirteen is the smallest value of n that returns an incorrect factorial result.
	The result of 13! is larger than the largest possible int representable.	
*/