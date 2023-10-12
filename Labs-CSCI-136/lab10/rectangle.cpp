#include <iostream>
#include "main.h"
using namespace std;

void Rectangle(){
	// 1.
	// FRAME
	int frameH, frameW;
	char paint;
	cout << "Enter a single character for which to draw your shape with: ";
	cin >> paint;

	cout << "Let's create your frame!\n";
	cout << "Enter your desired frame width: ";
		while(!(cin >> frameW)||frameW<2){
			cin.clear();
			cin.ignore();
			cout << "Try again: ";
		}
	cout << "Enter your desired frame height: ";
		while(!(cin >> frameH)||frameH<2){
			cin.clear();
			cin.ignore();
			cout << "Try again: ";
		}

	// 	FIRST ROW
	for (int i=0; i<frameW; i++)
		drawPixel(paint);

	cout << endl;

	// INNER ROWS
	// Handles row count
	for (int i=0; i<frameH-2;i++){
		cout << paint;
		// Handles blank spaces in row minus border asterisks
		for (int i=0; i<frameW-2; i++)
			cout << " ";
		drawPixel(paint);
		cout << endl;
	}

	// 	BOTTOM ROW
	for (int i=0; i<frameW; i++)
		drawPixel(paint);

	// Aesthetics
	cout << endl << endl;
}
