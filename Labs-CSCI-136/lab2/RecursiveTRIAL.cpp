#include <iostream>
#include <cmath>
using namespace std;

	double growthRate, deathRate;
	int carryingCap, currentPop, year, nextPop;

// Function prototype
int calculation(int x);


int main(){

// Getting info from user
	cout << "Enter the starting population: ";
	cin >> currentPop;

	cout << "Enter the growth rate (as percentage): ";
	cin >> growthRate;

	cout << "Enter the death rate (as percentage): ";
	cin >> deathRate;
// A restriction of deathRate input
		while (deathRate>=100){
			cout << "\nERROR: Death rate of 100% or more will result in no population.\n";
			cout << "       Enter the death rate (as percentage): ";
			cin >> deathRate;
		}

	cout << "Enter the carrying capacity: ";
	cin >> carryingCap;

	cout << "Enter the desired years from now: ";
	cin >> year;

// To set percentages
	growthRate /= 100;
	deathRate /= 100;

// ACTUAL FORMULA
//  	nextPop = ((1 + (growthRate - deathRate)) * currentPop) - (( growthRate * (pow(currentPop,2)) )/carryingCap);

	cout << "Year\tPopulation\n";
 	for (int i = 1; i<=year; i++){
		cout << "  " << i << "\t    " << calculation(1) << endl;
 	}
}

// Recursive function #hannn
int calculation(int x){
	if (x==0){
		return currentPop;
	}
	else{
		nextPop = ((1+growthRate-deathRate) * currentPop) - (( growthRate * (pow(currentPop,2)) )/carryingCap);
		currentPop = nextPop;
		return calculation(--x);
	}
}