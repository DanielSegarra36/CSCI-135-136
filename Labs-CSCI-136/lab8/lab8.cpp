/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 8

  This program:
	1.Reads through an excel sheet with information regarding
		countries' populations.
	2.Stores each country and the information regarding it's populations for the years
		1950, 1960, 1970, 1980, 1990, 2000, 2010, and 2015
		into an array of objects.
	3.Calculates the growth rate of each country for the 1960-2015 period.
		Then displays the fastest and slowest growing countries for this time period
	4.Finds the countries with a negative growth rate during this period and then
		prints those countries on the screen in order of their 2015 population.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // for setw() function
using namespace std;

// global things
const int MAXCOUNTRIES = 1000;

struct Country {
	string name;
	double pops[8];  // stores population in 1950, 1960,..., 2010, 2015 in order
	double growthRate; // From 1960-2015
};

struct Negatives{
	string name;
	double growthRate;
	double pop2015;
	int negAmount;
} negs;

struct World {
	int numCountries;
	Country countries[MAXCOUNTRIES]; // array of objects to store mult country data
	Negatives negGrowth[MAXCOUNTRIES]; // rip my grade
	int fastest, slowest;
} myWorld;

void itsMyWorld(World &obj);/*
	Reads through excel sheet.
	Stores the following in an object for each country:
		Population for the years: 1950, 1960, 1970, 1980, 1990, 2000, 2010, and 2015
			in an array and the country name in a string.
	The objects are stored in an array representing an instance of World with said countries.
	Also keeps count of the amount of countries total
*/

/****************************************************************************************************/
// 																							MAIN																								//
/****************************************************************************************************/

int main(){

/**************************************		TASK 0		*******************************************/
	itsMyWorld(myWorld); // initialize world instance


/**************************************		TASK 1		*******************************************/
// growth rate = ( (current population - older population) / older population) * 100
double rate;
int curFastest=0, curSlowest=0;
	for(int count=0; count < myWorld.numCountries; count++){
		// equation above
		rate = (((myWorld.countries[count].pops[7])-(myWorld.countries[count].pops[1]))/myWorld.countries[count].pops[1])*100;
		myWorld.countries[count].growthRate = rate; // set Country var mem, growthRate, to this rate
		// comparing rates to find slowest and fastest rates
		// for fastest
		if (myWorld.countries[count].growthRate>myWorld.countries[curFastest].growthRate) curFastest=count;
		// slowest
		else if (myWorld.countries[count].growthRate<myWorld.countries[curSlowest].growthRate) curSlowest=count;
	}
	cout << "\nThe fastest growing country is" << myWorld.countries[curFastest].name
			<< ", which grew by " << curFastest << "% between 1960 and 2015.\n";
	cout << "\nThe slowest growing country is" << myWorld.countries[curSlowest].name
			<< ", which shrunk by " << curSlowest << "% between 1960 and 2015.\n";


/**************************************		TASK 2		*******************************************/
/*
neg growthRate
order by 2015 pop
*/
int negArrayCount=0;
	for(int count=0; count < myWorld.numCountries; count++){ // get countries with neg growthRate
		if ((myWorld.countries[count].growthRate)<0.0){
			myWorld.negGrowth[negArrayCount].name = myWorld.countries[count].name;
			myWorld.negGrowth[negArrayCount].growthRate = myWorld.countries[count].growthRate;
			myWorld.negGrowth[negArrayCount].pop2015 = myWorld.countries[count].pops[7];
			negArrayCount++; // index and amount of countries w/ neg growthRate
		}
	}
	negs.negAmount = negArrayCount;

	// sort the list
	Negatives temp; // temp obj placeholder for an index when being switched around in array
	for (int i=1;i<negs.negAmount;i++){
		int j=i;
		while (j>0 && myWorld.negGrowth[j-1].pop2015>myWorld.negGrowth[j].pop2015){
			temp = myWorld.negGrowth[j];
			myWorld.negGrowth[j]=myWorld.negGrowth[j-1];
			myWorld.negGrowth[j-1] = temp;
			j--;
		}
	}

	cout << "\n\nThe countries that shrank between 1960 and 2015 (and their 'growth' rates) are:\n";
	for (int i=0; i<negs.negAmount; i++){
		cout << setw(15) << myWorld.negGrowth[i].name << setw(15)
				<< myWorld.negGrowth[i].growthRate << "%\n";
	}
} /**************************************		END OF MAIN		*******************************************/

/****************************************************************************************************/
// 																			FUNCTION DEFINITIONS																				//
/****************************************************************************************************/

void itsMyWorld(World &obj){
	ifstream data;
	data.open("population.csv");
	if (data.fail())
		cout << "Unable to open file\n";

	double yr1950, yr1970, yr1990, yr2010, yr2015; // years/columns in excel sheet
	obj.numCountries = 0;

	// read through columns. leaves us as country name at every iteration/line
	while (data >> yr1950 >> yr1970 >> yr1990 >> yr2010 >> yr2015){
		getline(data, obj.countries[obj.numCountries].name); // read country name with whitespaces
		obj.countries[obj.numCountries].pops[0] = yr1950 * 1000;
		obj.countries[obj.numCountries].pops[1] = ((yr1950+yr1970)/2) * 1000; // pop not provided
		obj.countries[obj.numCountries].pops[2] = yr1970 * 1000;
		obj.countries[obj.numCountries].pops[3] = ((yr1970+yr1990)/2) * 1000; // pop not provided
		obj.countries[obj.numCountries].pops[4] = yr1990 * 1000;
		obj.countries[obj.numCountries].pops[5] = ((yr1990+yr2010)/2) * 1000; // pop not provided
		obj.countries[obj.numCountries].pops[6] = yr2010 * 1000;
		obj.countries[obj.numCountries].pops[7] = yr2015 * 1000;
		obj.numCountries++; // keep count of amount of countries
	} // END of while

}
