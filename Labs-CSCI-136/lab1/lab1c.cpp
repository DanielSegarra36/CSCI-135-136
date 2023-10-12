/*
	Author: Daniel Segarra
	Course: CSCI Lab 136
	Instructor: Ilya Korsunsky
	Assignment: Lab 1

	This program prints an appropriate greeting
	using the sunset time offered by the user
	and the actual time of day.
	It then asks the user in how many minutes
	do they expect to be home and uses that information
	to tell them what time they will get home.
*/


#include <iostream>
#include <ctime>
using namespace std;

int main(){

//Given by instructor
	time_t t;
	struct tm *now;
	t = time(0);             // get current time                                           
	now = localtime(&t);     // adjust for local timezone
	int hour = now->tm_hour; // retrieve current hour
	int min = now->tm_min;   // retrieve current min

//My own work
	int sunHour, sunMin, homeTime;
	
	cout << "Enter the hours part of today's sunset time (4-9 PM):\n";
	cin >> sunHour;
	cout << "Enter the minutes part of today's sunset time (0-59):\n";
	cin >> sunMin;
	cout << "How many minutes from now do you expect to be home?\n";
	cin >> homeTime;
	cout << endl;

/*
	1: "noon" is set to time of noon in minutes
	2: "midnight" set to zero minutes
	
	3: The HOUR of sunset entered by the user is converted to minutes
	4: "sunset" is set to equal the time of sunset in minutes
	5: "sunset" is set to equal its time in minutes after noon
	
	6: Current hour is set to minutes
	7: "curTime" is set to equal time of day in minutes
	
	8: homeTime is divided by sixty to get a time in hours
	9: remainder of homeTime / sixty is set to homeMin
	10: Hours until time of arrival (homeHour) added to the hours of the current time
	11: Minutes until time of arrival (homeMin) added to minutes of the current time
	
	12: If arrivalMin is greater than or equal to 60:
		- 
		- arrivalMin will take the remainder of
		  arrivalMin / 60 as its new value
		If arrivalHour is 
	
*/
	/*1*/int noon = 12 * 60;
	/*2*/int midnight = 0;

//Sunset is after noon so add the time of sunset in minutes to noon in minutes	
	/*3*/int sunHourM = sunHour * 60;
	/*4*/int sunset = sunHourM + sunMin;
	/*5*/sunset += noon;
	
	/*6*/int hourM = hour * 60;
	/*7*/int curTime = hourM + min;

	/*8*/int homeHour = homeTime / 60;
	/*9*/int homeMin = homeTime % 60;
	/*10*/int arrivalHour = hour + homeHour;
	/*11*/int arrivalMin = min + homeMin;

	/*12*/
	if (arrivalMin >= 60){
		arrivalHour += (arrivalMin / 60);
		arrivalMin %= 60;
		while (arrivalHour>=24){
			arrivalHour %= 24;
			}
	}

	while (arrivalHour>=24){
		arrivalHour %= 24;
		cout << arrivalHour << endl;
	}


/*
// Use curTime for CURRRENT time
// Use sunset for SUNSET time
// Use noon for NOON time
// Use midnight for MIDNIGHT
*/
//GREETINGS
	if(curTime >= midnight && curTime < noon){
		cout << "Good morning, Korsunsky!";
	}
	
	if(curTime >= noon && curTime < sunset){
		cout << "Good afternoon, Korsunsky!";
	}
	
	if (curTime >= sunset && curTime > midnight){
		cout << "Good evening, Korsunsky!";
	}

	cout << endl;

//ARRIVAL TIME
//If arrivalMin is a single digit it will not print a zero before it
	if (arrivalHour > 9 && arrivalMin < 10){
		cout << "You will get home at: " << arrivalHour << ":0" << arrivalMin <<endl;
	}
	if (arrivalHour < 9 && arrivalMin > 10){
		cout << "You will get home at: 0" << arrivalHour << ":" << arrivalMin <<endl;
	}
	if (arrivalHour < 9 && arrivalMin < 10){
		cout << "You will get home at: 0" << arrivalHour << ":0" << arrivalMin <<endl;
	}
//All other cases will print this out
	if (arrivalHour > 9 && arrivalMin > 10){
		cout << "You will get home at: " << arrivalHour << ":" << arrivalMin << endl;
	}
/*
// To aid in testing this code as I changed time zones on my laptop
	cout << "sunset hour in mins: " <<sunHour<< endl;
	cout << "sunset mins: " <<sunMin<< endl;
	cout << "sunset in mins: " << sunset << endl << endl;
	
	cout << "noon in mins: " <<noon<< endl;
	cout << "current time in mins: " <<curTime<< endl;
*/
}