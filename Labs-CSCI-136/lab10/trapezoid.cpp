#include <iostream>
#include "main.h"
using namespace std;

void Trapezoid(){
	// 3.
	// TRAPEZOID
	int trapH, trapSide;
	char paint;
	cout << "Enter a single character for which to draw your shape with: ";
	cin >> paint;

	cout << "Now let's make a trapezoid!\n";
	cout << "Enter height: ";
		while(!(cin >> trapH)||trapH<2){
			cin.clear();
			cin.ignore();
			cout << "Try again: ";
		}
	cout << "Enter bottom width: ";
		while (!(cin >> trapSide)||trapH>=trapSide){
			cin.clear();
			cin.ignore();
			cout << "Dimensions invalid for shape!\n";
			cout << "Enter a dimension, for the width, that is larger than the height: ";
		}

	int heightCount = trapH;

	// Handles amount of rows
	for (int i = 0; i<trapH; i++, heightCount--){
	// The difference of the dimensions plus one gives the correct amount of asterisk per line
	// The variable line is then decremented so that asterisk may stop printing
		for(int line=1+(trapSide-heightCount); line>0; line--)
			drawPixel(paint);
		cout << endl;
	}
	// Aesthetics
	cout << endl;
}
