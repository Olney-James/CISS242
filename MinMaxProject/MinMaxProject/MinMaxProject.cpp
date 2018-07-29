/*************************************
Program: MinMaxProject.cpp (Week 3 Programming Assignment 2)

Author: James Olney
Created: 03/17/2017
Revisions: N/A

This a program that creates 3 instances of MinMax for the data types int, double and char.

**************************************/

#include <iostream>
#include "MinMax.h"
using namespace std;

int main() {
	int exit;

	int minInt = 2;
	int maxInt = 4;
	double minDouble = 2.5;
	double maxDouble = 4.5;
	char minChar = 'c';
	char maxChar = 'f';
	MinMax<int> forInt(minInt, maxInt);
	MinMax<double> forDouble(minDouble, maxDouble);
	MinMax<char> forChar(minChar, maxChar);

	cout << "testing forInt..." << endl;
	cout << "min: " << forInt.minimum() << endl;
	cout << "max: " << forInt.maximum() << endl;
	cout << endl << "testing forDouble..." << endl;
	cout << "min: " << forDouble.minimum() << endl;
	cout << "max: " << forDouble.maximum() << endl;
	cout << endl << "testing forChar..." << endl;
	cout << "min: " << forChar.minimum() << endl;
	cout << "max: " << forChar.maximum() << endl;
	cout << endl << "enter 0 to exit...";
	cin >> exit;
}