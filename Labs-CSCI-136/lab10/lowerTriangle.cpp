#include <iostream>
#include "main.h"
using namespace std;

void LowerTriangle(){
	// 2.
	// TRIANGLE (BOTTOM)
	int side1;
	char paint;
	cout << "Enter a single character for which to draw your shape with: ";
	cin >> paint;

	cout << "Now let's make a triangle!\n";
	cout << "Enter your desired triangle dimension (same for both sides): ";
		while(!(cin >> side1)||side1<2){
			cin.clear();
			cin.ignore();
			cout << "Try again: ";
		}

		// Handles row count
	for(int i=1; i<=side1; i++){
	// Handles asterisk per line
	// Uses an increasing i value to print multiples of the asterisk character
		for(int line=0; line<i; line++)
			drawPixel(paint);
		cout << endl;
	}
	// Aesthetics
	cout << endl;

}
