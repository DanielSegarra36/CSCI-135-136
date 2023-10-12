/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 5

  This program does takes a number from the user
  and computes the sum of the digits in the number
  until it reaches a single digit number.

  Then, number may or not be changed afterwards
  in order to make it divisible by 9.
  To do this we change just the rightmost digit in the number.
*/

#include <iostream>
using namespace std;

int numDigits(int num);
// Calculates the number of digits in user input.
int getDigit(int num, int index);
// Gets a single digit within the number
// Though not an array the num is treated as one
// with the rightmost digit being index 0.
int sumDigits(int num);
// Calculates the sum of the digits of user input
// until the sum is a single digit number.
int transformNum(int &num, int sum);
// Returns: user's number transformed into a number divisible by 9.
// If the number is divisible by 9 then it is simply returned.

int main(){
	int num, place;

	cout << "Enter a number: ";
 	cin >> num;
 		while(num>(INT_MAX-9)||cin.fail()){
 			cin.clear();
 			cout << "INTEGER OVERFLOW!\n";
 			cout << "Please, enter a smaller number: ";
		 	cin >> num;
 		}

	cout << "Select desired place value from the right ";
	cout << "(Between 0 and " << (numDigits(num)-1) << ")\n";
	cout << "Choice: ";
	cin >> place;
		while (place>=numDigits(num)){
			cout << "Index does not exist.\n";
			cout << "Select desired digit from the right (counting from 0): ";
			cin >> place;
		}
	cout << "Your selected digit is: " << getDigit(num, place) << endl;

	cout << "The sum of the digits of your number is: " << sumDigits(num) << endl;

	cout << "We may or may not have to change your number"
		 << " in order for it to be divisible by 9.\n";
	cout << "Transformation: " << transformNum(num, sumDigits(num)) << endl;
}

int numDigits(int num){
	int count = 0;
	while(num>=10){
		num/=10;
		count++;
	}
	count++;
	return count;
}

int getDigit(int num, int index){
	while(index>0){
		num/=10;
		index--;
	}
	num%=10;
	return num;
}

int sumDigits(int num){
	int sum = 0;
		while(num>0){
			sum += (num%10);
			num/=10;
		}
		while(sum>9){
			sum=sumDigits(sum);
		}
	return sum;
}

int transformNum(int &num, int sum){
	if (num%9==0){
		num=num;
	}else{
		num-=getDigit(num,0);
		for(int i=0; i<10; i++){
			num++;
			if(num%9==0){
				break;
			}
		}
	}
	return num;
}
