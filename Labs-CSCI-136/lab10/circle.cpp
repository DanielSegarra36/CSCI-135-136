#include <iostream>
#include "main.h"
using namespace std;

void Circle(){
	// 5.
	// CIRCLE
	int radius;
	char paint;
	cout << "Enter a single character for which to draw your shape with: ";
	cin >> paint;

	cout << "Now let's draw a circle!\n";
	cout << "Enter your desired radius for a circle: ";
		while(!(cin >> radius)||radius<2){
			cin.clear();
			cin.ignore();
			cout << "Try again: ";
		}
	int diameter = radius*2;

	// Handles y-axis (amount of rows printed)
	for (int y=0; y<=radius; y++){
		// Handles x-axis
		for(int x=0; x<=diameter; x++){
			// Y is multiplied by two to widen what would typically print out as an ellipse
			if(( ((x-radius)*(x-radius))+((y*2-radius)*(y*2-radius)) <= (radius*radius) ))
				drawPixel(paint);
			else
				cout << " ";
		} // end of horizontal print
		cout  << endl;
	} // end of vertical print
}
