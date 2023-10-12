/*
  Author: Daniel Segarra
  Course: CSCI 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 2

  This program uses the Verhulst Formula to model growth rates in habitats
  Following this are test cases to show when the graph of the function would start
  to oscillate and show chaotic behavior
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double growthRate, deathRate;
	int carryingCap, currentPop, year, nextPop;

// Getting info from user
	cout << "Enter the starting population: ";
	cin >> currentPop;
	cout << "Enter the growth rate (as percentage): ";
	cin >> growthRate;
	cout << "Enter the death rate (as percentage): ";
	cin >> deathRate;
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

	for (int i=1; i<=year; i++){
	// Calculation for the year after current population
		nextPop = ((1+growthRate-deathRate) * currentPop) - (( growthRate * (pow(currentPop,2)) )/carryingCap);
	// Sets new population as the current population
	// Useful for next iteration (to calculate consecutive years).
		currentPop = nextPop;
	//Printing of List
		cout << " " << i << "\t    " << nextPop << endl;
	}
}
/***********************************************************************************************************************/
/*

// TESTING OF VALUES

//End of plateau-like behavior
	Enter the starting population: 10 
	Enter the growth rate (as percentage): 192
	Enter the death rate (as percentage): 20
	Enter the carrying capacity: 100
	Enter the desired years from now: 20
	Year	Population
	 1	    25
	 2	    56
	 3	    92
	 4	    87
	 5	    91
	 6	    88
	 7	    90
	 8	    89
	 9	    89
	 10	    89
	 11	    89
	 12	    89
	 13	    89
	 14	    89
	 15	    89
	 16	    89
	 17	    89
	 18	    89
	 19	    89
	 20	    89

// Oscillation begins
	Enter the starting population: 10
	Enter the growth rate (as percentage): 193
	Enter the death rate (as percentage): 20
	Enter the carrying capacity: 100
	Enter the desired years from now: 20
	Year	Population
	 1	    25
	 2	    56
	 3	    92
	 4	    87
	 5	    91
	 6	    88
	 7	    90
	 8	    89
	 9	    90
	 10	    89
	 11	    90
	 12	    89
	 13	    90
	 14	    89
	 15	    90
	 16	    89
	 17	    90
	 18	    89
	 19	    90
	 20	    89

// Complete oscillating-like behavior ends
	Enter the starting population: 10
	Enter the growth rate (as percentage): 269
	Enter the death rate (as percentage): 20
	Enter the carrying capacity: 100
	Enter the desired years from now: 20
	Year	Population
	 1	    32
	 2	    84
	 3	    103
	 4	    74
	 5	    110
	 6	    58
	 7	    111
	 8	    55
	 9	    110
	 10	    58
	 11	    111
	 12	    55
	 13	    110
	 14	    58
	 15	    111
	 16	    55
	 17	    110
	 18	    58
	 19	    111
	 20	    55
	
//Mildly chaotic behavior starts
	Enter the starting population: 10
	Enter the growth rate (as percentage): 275
	Enter the death rate (as percentage): 20
	Enter the carrying capacity: 100
	Enter the desired years from now: 20
	Year	Population
	 1	    32
	 2	    85
	 3	    103
	 4	    73
	 5	    112
	 6	    52
	 7	    110
	 8	    57
	 9	    113
	 10	    50
	 11	    108
	 12	    62
	 13	    114
	 14	    47
	 15	    106
	 16	    67
	 17	    114
	 18	    47
	 19	    106
	 20	    67

//Wildly chaotic behavior begins
	Enter the starting population: 10
	Enter the growth rate (as percentage): 282
	Enter the death rate (as percentage): 20
	Enter the carrying capacity: 100
	Enter the desired years from now: 20
	Year	Population
	 1	    33
	 2	    88
	 3	    100
	 4	    79
	 5	    109
	 6	    59
	 7	    115
	 8	    43
	 9	    103
	 10	    73
	 11	    113
	 12	    48
	 13	    108
	 14	    62
	 15	    116
	 16	    40
	 17	    99
	 18	    81
	 19	    108
	 20	    62

*/