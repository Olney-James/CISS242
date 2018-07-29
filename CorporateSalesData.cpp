/***********************************************************
Program: CorporateSalesData.cpp (Week 4 Programming Assignment 1)

This program will have a structure that holds data about each division of a corporation. The
program will prompt the user to enter the quarterly sales, calculate the total and average, 
then present these to the user.

Detail: Corporate Sales Data. This program will have a structure that holds data about each division of a corporation. This structure will have a string object that holds the division’s name, 4 doubles that hold the sales totals for each quarter. The structure will also have two other doubles, one for the annual sales and the other will hold the average of the quarter sales. The program should use four variables (instances) of this structure. Each variable should represent one of the following corporate divisions: East, West, North, South. The user should be asked for the four quarters’ sales figures for each division. Each division’s total and average sales should be calculated and stored in the appropriate member of each structure variable. The output of the program will be all the figures in the structures. Validation: Do not accept negative numbers for any sales figures.

Program must have the following functions
void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south);
void FindTotalAndAverageSales(Division& div);
void GetDivisionSales(Division& div);

Author: James Olney
Created: 01/20/2017
Revisions: N/A
*******************/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Division {
	string name;
	double salesTotalQtrOne;
	double salesTotalQtrTwo;
	double salesTotalQtrThree;
	double salesTotalQtrFour;
	double annualSales;
	double quarterSalesAverage;
};

void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south) {
	cout << "Total Annual Sales:" << endl;
	cout << "East Division: $" << east.annualSales << endl;
	cout << "West Division: $" << west.annualSales << endl;
	cout << "North Division: $" << north.annualSales << endl;
	cout << "South Division: $" << south.annualSales << endl;
	cout << "Average Quarterly Sales:" << endl;
	cout << "East Division: $" << east.quarterSalesAverage << endl;
	cout << "West Division: $" << west.quarterSalesAverage << endl;
	cout << "North Division: $" << north.quarterSalesAverage << endl;
	cout << "South Division: $" << south.quarterSalesAverage << endl;
}

void FindTotalAndAverageSales(Division& div) {
	div.annualSales = div.salesTotalQtrOne + div.salesTotalQtrTwo + div.salesTotalQtrThree + div.salesTotalQtrFour;
	div.quarterSalesAverage = div.annualSales / 4;
}

void GetDivisionSales(Division& div) {
	cout << "Enter the quarterly sales for the " << div.name << " Division: " << endl;
	do {
		cout << "First Quarter: ";
		cin >> div.salesTotalQtrOne;
		if (div.salesTotalQtrOne < 0) {
			cout << "sales figures must not be negative!!!" << endl;
		}
	} while (div.salesTotalQtrOne < 0 || div.salesTotalQtrOne == NULL);
	do {
		cout << "Second Quarter: ";
		cin >> div.salesTotalQtrTwo;
		if (div.salesTotalQtrTwo < 0) {
			cout << "sales figures must not be negative!!!" << endl;
		}
	} while (div.salesTotalQtrTwo < 0 || div.salesTotalQtrTwo == NULL);
	do {
		cout << "Third Quarter: ";
		cin >> div.salesTotalQtrThree;
		if (div.salesTotalQtrThree < 0) {
			cout << "sales figures must not be negative!!!" << endl;
		}
	} while (div.salesTotalQtrThree < 0 || div.salesTotalQtrThree == NULL);
	do {
		cout << "Fourth Quarter: ";
		cin >> div.salesTotalQtrFour;
		if (div.salesTotalQtrFour < 0) {
			cout << "sales figures must not be negative!!!" << endl;
		}
	} while (div.salesTotalQtrFour < 0 || div.salesTotalQtrFour == NULL);
}

int main()
{
	int exit = 1;
	Division east = { "East" }, west = { "West" }, north = { "North" }, south = { "South" };
	GetDivisionSales(east);
	GetDivisionSales(west);
	GetDivisionSales(north);
	GetDivisionSales(south);
	FindTotalAndAverageSales(east);
	FindTotalAndAverageSales(west);
	FindTotalAndAverageSales(north);
	FindTotalAndAverageSales(south);
	DisplayCorpInformation(east, west, north, south);
	cout << "enter 0 to exit";
	cin >> exit;
    return 0;
}

