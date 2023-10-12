/*
	Author: Daniel Segarra
	Course: CSCI Lab 136
	Instructor: Ilya Korsunsky
	Assignment: Lab 1

	This program prints an appropriate greeting
	using the sunset time offered by the user
	and the actual time of day.
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
	int sunHour, sunMin;
	
	cout << "Enter the hours part of today's sunset time (4-9 PM):\n";
	cin >> sunHour;
	cout << "Enter the minutes part of today's sunset time (0-59):\n";
	cin >> sunMin;
	cout << endl;

/*
	1: "noon" is set to time of noon in minutes
	2: "midnight" set to zero minutes
	
	3: The HOUR of sunset entered by the user is converted to minutes
	4: "sunset" is set to equal the time of sunset in minutes
	5: "sunset" is set to equal its time in minutes after noon
	
	6: Current hour is set to minutes
	7: "curTime" is set to equal time of day in minutes
	
*/
	/*1*/int noon = 12 * 60;
	/*2*/int midnight = 0;

//Sunset is after noon so add the time of sunset in minutes to noon in minutes	
	/*3*/sunHour *= 60;
	/*4*/int sunset = sunHour + sunMin;
	/*5*/sunset += noon;
	
	/*6*/hour *= 60;
	/*7*/int curTime = hour + min;
	

// Use curTime for CURRRENT time
// Use sunset for SUNSET time
// Use noon for NOON time
// Use midnight for MIDNIGHT

	if(curTime >= midnight && curTime < noon){
		cout << "good morning, Korsunsky!\n";
	}
	
	if(curTime >= noon && curTime < sunset){
		cout << "good afternoon, Korsunsky!\n";
	}
	
	if (curTime >= sunset && curTime > midnight){
		cout << "good evening, Korsunsky!\n";
	}
/*	
	cout << "sunset hour in mins: " <<sunHour<< endl;
	cout << "sunset mins: " <<sunMin<< endl;
	cout << "sunset in mins: " << sunset << endl << endl;
	
	cout << "noon in mins: " <<noon<< endl;
	cout << "current time in mins: " <<curTime<< endl;
*/
}