#include <iostream>
#include <cstdlib>
#include "main.h"
using namespace std;

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
