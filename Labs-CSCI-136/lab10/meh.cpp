/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 10

  This program draws shapes with user given dimensions.
  If user input is of an invalid type or impossible as a dimension
  the user is prompted to enter another value.
*/

#include <iostream>
using namespace std;

void drawPixel(char c);
void Prompt();
// Displays a menu of shapes where the user may choose the dimensions
void Rectangle();
// Pre: N/A
// Post: Draws a rectangle with user given dimensions
//	as long as the dimensions are valid for the shape
void LowerTriangle();
// Pre: N/A
// Post: Draws left bound triangle with user given dimensions
//	as long as the dimensions are valid for the shape
void Trapezoid();
// Pre: N/A
// Post: Draws a trapezoid with user given dimensions
//	as long as the dimensions are valid for the shape
void Circle();
// Pre: N/A
// Post: Draws a circle with user given dimensions
//	as long as the dimensions are valid for the shape

int main(){
	Prompt();
}

void drawPixel(char c){
	cout << c;
}

void Prompt(){
	char choice;
	cout << "Enter (R)ectangle, (L)owerTriangle, (T)rapezoid, (C)ircle, or (E)nd\n";
	cin >> choice;

	switch (choice){
		case 'R':
			Rectangle();
			break;
		case 'L':
			LowerTriangle();
			break;
		case 'T':
			Trapezoid();
			break;
		case 'C':
			Circle();
			break;
		case 'E':
			exit(1);
			break;
		default:
			cout << "Invalid input\n";
			Prompt();
	}
	Prompt();
}

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
			cout << "Enter a dimension larger than the height: ";
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
			if(( ((x-radius)*(x-radius))+((y*2-radius)*(y*2-radius))<=(radius*radius) ))
				drawPixel(paint);
			else
				cout << " ";
		} // end of horizontal print
		cout  << endl;
	} // end of vertical print
}
