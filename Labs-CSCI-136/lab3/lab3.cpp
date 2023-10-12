/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 3

  This program does the following with user given dimensions:
1. Draws a frame
2. Draws a left-hand bound triangle
3. Draws a trapezoid
4. Draws a right-hand bound triangle
5. Draws a circle
*/

#include <iostream>
using namespace std;

int main(){
// Clears screen (aesthetics)
	system("clear");


/*-------------------------------------------------------------------------------------*/
// 1.
// FRAME
	int frameH, frameW;
	
	cout << "Let's create your frame!\n";
	cout << "Enter your desired frame width: ";
	cin >> frameW;
	cout << "Enter your desired frame height: ";
	cin >> frameH;

// 	FIRST ROW
	for (int i=0; i<frameW; i++){
		cout << "*";
	}
	
	cout << endl;

// INNER ROWS
// Handles row count
	for (int i=0; i<frameH-2;i++){
		cout << "*";
// Handles blank spaces in row minus border asterisks
		for (int i=0; i<frameW-2; i++){
			cout << " ";
		}
		cout << "*";
		cout << endl;
	}

// 	BOTTOM ROW
	for (int i=0; i<frameW; i++){
		cout << "*";
	}

// Aesthetics
	cout << endl << endl;

/*-------------------------------------------------------------------------------------*/
// 2.
// TRIANGLE (BOTTOM)
	int side1;

	cout << "Now let's make a triangle!\n";
	cout << "Enter your desired triangle dimension (same for both sides): ";
	cin >> side1;

// Handles row count
	for(int i=1; i<=side1; i++){
// Handles asterisk per line
// Uses an increasing i value to print multiples of the asterisk character
		for(int line=0; line<i; line++){
			cout << "*";
		}
		cout << endl;
	}
// Aesthetics
	cout << endl;
	
/*-------------------------------------------------------------------------------------*/
// 3.
// TRAPEZOID
	int trapH, trapSide;

	cout << "Now let's make a trapezoid!\n";
	cout << "Enter height: ";
	cin >> trapH;
	cout << "Enter bottom width: ";
	cin >> trapSide;
		while (trapH>=trapSide){
			cout << "Dimensions invalid for shape!\n";
			cout << "Enter another dimension for the bottom width: ";
			cin >> trapSide;		
		}
	
	int heightCount = trapH;

// Handles amount of rows
	for (int i = 0; i<trapH; i++, heightCount--){
// The difference of the dimensions plus one gives the correct amount of asterisk per line
// The variable line is then decremented so that asterisk may stop printing
		for(int line=1+(trapSide-heightCount); line>0; line--){
			cout << "*";
		}
		cout << endl;
	}
// Aesthetics
	cout << endl;

/*-------------------------------------------------------------------------------------*/
// 4.
// TRIANGLE (TOP)
	int side2;
	
	cout << "Now let's make another triangle!\n";
	cout << "Enter a side length: ";
	cin >> side2;

// HEIGHT/LINE (counting down)
	for(int lineCount=side2; lineCount>0; lineCount--){
// BLANKS
// Will always be skipped first time around since side2 and lineCount are equal
// Afterwards the difference of those two becomes the amount of spaces printed
		for (int blankSpace = side2-lineCount; blankSpace>0; blankSpace--){
			cout << " ";
		}
// STARS per line
// Uses a decreasing variable (lineCount) to print less asterisk each line
			for(int star=0; star<lineCount; star++){
				cout << "*";
			}
		cout << endl;
	}
// Aesthetics
	cout << endl;
		
/*-------------------------------------------------------------------------------------*/
// 5.
// CIRCLE
	int radius;
	
	cout << "Now let's draw a circle!\n";
	cout << "Enter your desired radius for a circle: ";
	cin >> radius;
	int diameter = radius*2;

// Handles y-axis (amount of rows printed)
	for (int y=0; y<=radius; y++){
// Handles x-axis
		for(int x=0; x<=diameter; x++){
// Y is multiplied by two to widen what would typically print out as an ellipse
			if(( ((x-radius)*(x-radius))+((y*2-radius)*(y*2-radius))<=(radius*radius) )){
				cout << "*";
			}else{
				cout << " ";
			}
		}
		cout  << endl;
	}
}