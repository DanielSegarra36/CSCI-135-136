#ifndef MAIN_H
#define MAIN_H

extern void drawPixel(char c);
extern void Prompt();
// Displays a menu of shapes where the user may choose the dimensions
extern void Rectangle();
// Pre: N/A
// Post: Draws a rectangle with user given dimensions
//	as long as the dimensions are valid for the shape
extern void LowerTriangle();
// Pre: N/A
// Post: Draws left bound triangle with user given dimensions
//	as long as the dimensions are valid for the shape
extern void Trapezoid();
// Pre: N/A
// Post: Draws a trapezoid with user given dimensions
//	as long as the dimensions are valid for the shape
extern void Circle();
// Pre: N/A
// Post: Draws a circle with user given dimensions
//	as long as the dimensions are valid for the shape

#endif
