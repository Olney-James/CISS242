/***********************************************************
Program: RainfallDataArray.cpp (Week 1 Programming Assignment 2)

This program reads in Rainfall data for each month of the year, returning the total,
average, lowest, and highest.

Detail: This program will be a modification of the program done in CISS 241, 
Week 7 Programming Assignment 1. That was the Rainfall Statistics program. For
those who did not take 241, that program description is below. Modify the Rainfall
Statistics program so that it displays a list of months, sorted in the order of 
rainfall from highest to lowest.

Original Assignment: Write a program that lets the user enter the total rainfall
for each of 12 months into an array of doubles. The program should use two 12 
element arrays. One array will hold strings, the names of the 12 months. This 
array will be initialized when the array is created using an initialization list
(could also be created as a array of constants). The second array will hold 
doubles which will be the total rainfall for each month. The program will 
prompt the user for the rainfall for each month (using both arrays) and store
the value entered into the array with the rainfall totals, the other is used to
display which month the program is asking for the rainfall total. The program 
should display the following once the data is all entered:

The total rainfall for the year
The average monthly rainfall
The month with the highest amount of rainfall (must display the month as a string)
The month with the lowest amount of rainfall (must display the month as a string)
The program must have the following functions:

double getTotal(double [ ], int);
double getAverage(double [ ], int);
double getLowest(double [ ], int, int&); //returns the lowest value, provides the index of the lowest value in the last parameter.
double getHighest(double [ ], int, int&); //returns the highest value, provides the index of the highest value in the last parameter.

Author: James Olney
Created: 01/04/2017
Revisions: 01/04/2017 added display of a list of months, sorted in the order of rainfall from highest to lowest.
*******************/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

double getTotal(double array[], int arraylength) {
	double sum = 0;
	for (int x = 0; x < arraylength; x++) {
		sum += array[x];
	}
	return sum;
}

double getAverage(double array[], int arraylength) {
	double total = getTotal(array, arraylength);
	return total / arraylength;
}

void bubbleSortTwoArrays(double array[], string parallelArray[], int size) {
	bool swap;
	double temp;
	string temp2;

	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (array[count] > array[count + 1]) {
				temp = array[count];
				temp2 = parallelArray[count];
				array[count] = array[count + 1];
				parallelArray[count] = parallelArray[count + 1];
				array[count + 1] = temp;
				parallelArray[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

//getLowest(below) returns the lowest value, provides the index of the lowest value in the last parameter.
double getLowest(double array[], int arraylength, int &index) {
	double lowestValue = array[0];
	for (int x = 0; x < arraylength; x++) {
		if (array[x] < lowestValue) {
			lowestValue = array[x];
			index = x;
		}
	}
	return lowestValue;
}

//getHighest(below) returns the highest value, provides the index of the highest value in the last parameter.
double getHighest(double array[], int arraylength, int &index) {
	double highestValue = array[0];
	for (int x = 0; x < arraylength; x++) {
		if (array[x] > highestValue) {
			highestValue = array[x];
			index = x;
		}
	}
	return highestValue;
}

int main()
{
	string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	double totalRainfall[12];
	int lengthOfTotalRainfallArray = sizeof(totalRainfall) / sizeof(totalRainfall[0]);
	double sumOfAllRainfall=0;
	double averageMonthlyRainfall;
	int index = 0;
	int exit;
	cout << "Enter the total rainfall for each of 12 months: " << endl;
	for (int x = 0; x < lengthOfTotalRainfallArray; x++) {
		cout << months[x] << ": ";
		cin >> totalRainfall[x];
	}

	sumOfAllRainfall = getTotal(totalRainfall, lengthOfTotalRainfallArray);
	averageMonthlyRainfall = getAverage(totalRainfall, lengthOfTotalRainfallArray);
	cout << "The total rainfall for the year: " << sumOfAllRainfall << endl;
	cout << "The average monthly rainfall: " << averageMonthlyRainfall << endl;
	cout << "The lowest rainfall was " << getLowest(totalRainfall, lengthOfTotalRainfallArray, index) << ", occuring in the month of ";
	cout << months[index] << endl;
	cout << "The highest rainfall was " << getHighest(totalRainfall, lengthOfTotalRainfallArray, index) << ", occuring in the month of ";
	cout << months[index] << endl;
	cout << "A list of months, sorted in the order of rainfall from highest to lowest:" << endl;
	bubbleSort(totalRainfall, months, lengthOfTotalRainfallArray);
	for (int x = 0; x < lengthOfTotalRainfallArray; x++) {
		cout << months[x] << ": " << totalRainfall[x] << endl;
	}
	cout << "TEST";
	cout << "enter 0 to exit";
	cin >> exit;
    return 0;
}

