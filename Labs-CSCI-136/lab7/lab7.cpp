/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 7

  This program manipulates a PGM file in three different ways
		1. Thresholds the image according to user given values
		2. Pixelates/blurs the picture by taking the average of the pixels
				in a window (dimensions given by user)
		3. Detects edges and alter picture according to edges found
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

const int MAXWIDTH = 512;
const int MAXHEIGHT = 512;

void readImage(int image[][MAXHEIGHT], int &width, int &height);
void writeImage(int image[][MAXHEIGHT], int width, int height);
void highlight(int image[][MAXHEIGHT], int width, int height, int t1, int t2);
void scale(int image[][MAXHEIGHT], int width, int height, int n);
void hedgeDet(int image[][MAXHEIGHT], int width, int height);

int main(){
	// dimensions of image
	int width, height;
	// array to use for all functions
	int image[MAXWIDTH][MAXHEIGHT]; // first image array
	// a second array (only used in TASK 0)
	int imageSec[MAXWIDTH][MAXHEIGHT]; // second image array
/******************************************************************************/
	// Task 0 - Reading and Writing an Image to an Array

	// Reads given image and stores it in 2D array, image
	readImage(image, width, height);

	// Loop that iterates through every array element (image's color values)
	// and copies those values into a new array
	for (int w = 0; w < MAXWIDTH; w++){
		for (int h = 0; h < MAXHEIGHT; h++){
			imageSec[w][h] = image[w][h];
		}
	}
	// This creates a PGM file from the second array
	writeImage(imageSec, width, height);

/******************************************************************************/
	// Task 1 - Thresholds

	int thresh1, thresh2;
	cout << "\n\nTASK ONE...\n\n";
	do{
	cout << "Enter bottom threshold: ";
  cin >> thresh1;
	}while(thresh1<0 || thresh1>255);

	do{
	cout << "Enter top threshold: ";
  cin >> thresh2;
	}while(thresh2<0 || thresh2>255 || thresh2<=thresh1);

  highlight(image, width, height, thresh1, thresh2);

	cout << "\nTASK ONE... COMPLETE\n\n";

/******************************************************************************/
	// Task 2 - nXn window

	cout << "\n\n\nTASK TWO...\n\n";
	int windowScale;

	do{
	cout << "Enter a dimension for your window: ";
	cin >> windowScale;
	}while(windowScale<2 || windowScale>=width);

	scale(image, width, height, windowScale);
	writeImage(image, width, height);

	cout << "\nTASK TWO... COMPLETE\n\n";

/******************************************************************************/
	// Task 3 - Sliding Window

	int ready;
	cout << "\n\n\nTASK THREE... (maybe?)\n\n";

	do {
		cout << "Enter the number 3 to see the final image: ";
		cin >> ready;
	} while(ready!=3);

	hedgeDet(image, width, height);
	writeImage(image, width, height);
}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

// reads a PGM file.
// Notice that: width and height are passed by reference!
void readImage(int image[][MAXHEIGHT], int &width, int &height) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;  assert(c == 'P');
	instr >> c;  assert(c == '2');

	// skip the comments (if any)
	while ((instr >> ws).peek() == '#') { instr.ignore(4096, '\n'); }

	instr >> width;
	instr >> height;

	assert(width <= MAXWIDTH);
	assert(height <= MAXHEIGHT);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[col][row];
	instr.close();
	return;
}

void writeImage(int image[][MAXHEIGHT], int width, int height) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[col][row] < 256);
			assert(image[col][row] >= 0);
			ostr << image[col][row] << ' ';
			// lines should be no longer than 70 characters
			if ((col + 1) % 16 == 0) ostr << endl;
		}
		ostr << endl;
	}
	ostr.close();
	return;
}

// highlight for task 1
void highlight(int image[][MAXHEIGHT], int width, int height, int t1, int t2){
	// make all pixels below t1: 0   and make all pixels above t2: 255
	for(int row=0; row<width; row++){
    for(int col=0; col<height; col++){
      if(image[row][col]<=t1) image[row][col]=0;
      else if(image[row][col]>=t2) image[row][col]=255;
    }
  }
  writeImage(image, width, height);
}

// nXn for task 2
void scale(int image[][MAXHEIGHT], int width, int height, int window){
	// we start at top left of image
	int currentWidth = 0;
	int currentHeight = 0;
	int windowWidth = window;
	int windowHeight = window;
	// To keep the while loop running
	// When window falls out of bounds on picture
	// bool will be set to false and loop will stop
	bool running = true;

	// one big loop to get average for a window per iteration
	while (running){
		float windowAvg = 0; // to hold average of nXn window
		// Loop that takes color values in image and adds them to variable windowAvg
		for (int w = currentWidth; w < windowWidth; w++){
			for (int h = currentHeight; h < windowHeight; h++){
				windowAvg += image[w][h];
			}
		}

		// Computes average by dividing by total amount pixels
		// n*n b/c the window has the same height and width
		// therefore (window * window) will always be the amount of pixels added
		windowAvg /= (window*window);
		// Rounds number so that numbers are valid pixel values
		windowAvg = round(windowAvg);

		// Sets every pixel/color value to that average
		for (int w = currentWidth; w < windowWidth; w++){
			for (int h = currentHeight; h < windowHeight; h++){
				image[w][h] = windowAvg;
			}
		}

		// if/else if statements to check if loop has encountered any edges
		/*
			1. NO EDGE
			2. HORIZONTAL EDGE
			3. VERTICAL EDGE
			4. TWO EDGES (end of picture)
		*/

		// 1. NO EDGE encountered, proceed
		if (currentWidth + window < 256 && currentHeight + window < 256){
			// will go forward by window amount
			// goes to next window selection
			currentHeight += window;
			windowHeight += window;
		}

		// 2. HORIZONTAL EDGE
		else if (currentWidth + window < 256 && currentHeight + window >= 256){
			currentHeight = 0;
			windowHeight = window;

			currentWidth += window;
			windowWidth += window;
		}

		// 3. VERTICAL EDGE
		else if (currentWidth + window >= 256 && currentHeight + window < 256){
			// will go forward by window amount
			// goes to next window selection
			currentHeight += window;
			windowHeight += window;
		}

		// 4. TWO EDGES (end of picture)
		// Loop has encountered two edges for sure
		// No more picture left to check
		// Changes bool to false and loop stops
		else if (currentWidth + window + window >= 256 && currentHeight + window + window >= 256){
			running = false; // no longer necessary to run loop
		}

	}
}

// edge detector function for TASK 3
// This one killed me
void hedgeDet(int image[][MAXHEIGHT], int width, int height){
	/*
			0	1	2
		0	a	b	c
		1	d	e	f
		2	g	h	i

	set e to array[1][1] and fix all other points around it
	*/

	int a, b, c, d, e, f, g, h, i;
	// Moves row down by one to not start at top (edge present)
	// (width-2) to ensure window does not go out of bounds
	for (int row = 1; row < width - 2; row++){
		// moves over column by one (left edge present)
		// (height-2) to ensure window does not go out of bounds
		for (int col = 1; col < height - 2; col++){

			a = image[row-1][col-1]; // up and left by one
			b = image[row-1][col];	// up by one
			c = image[row+1][col-1];	// up and right by one
			d = image[row][col-1]; // left by one
			e = image[row][col]; // center of window
			f = image[row][col+1];	// right by one
			g = image[row+1][col-1];	// down by one, left by one
			h = image[row+1][col];	// down by one
			i = image[row+1][col+1];	// down by one, right by one

			// computes horizontal edge value
			int edgeVal = ((g+(2*h)+i)-(a+(2*b)+c));

				if(edgeVal>100||edgeVal<-100){
					// For when edgeVal exceeds range
					// pull values in to either the max or min respectively
					if (edgeVal > 255) edgeVal = 255;
					else if (edgeVal < 0) edgeVal = 0;
					image[row][col] = edgeVal;	// Set pixels to edgeVal?
				}
		}
	}
}
