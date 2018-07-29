/*************************************
Program: Main.cpp (Week 6 Programming Assignment 1)

Author: James Olney
Created: 04/07/2017
Revisions: N/A

This is the main class that calls a function that uses recursion to raise
a number to a power. The function accepts 2 arguments, the number to be
raised and the exponent. This program is written with the assumption that
the exponent is a nonnegative integer. Main shows that this function works
correctly for several values.

**************************************/

#include <iostream>
using namespace std;

int raiseNumberToaPower(int numToBeRaised, int exponent) {
	if (exponent == 0)
		return 1;
	else
		return numToBeRaised * raiseNumberToaPower(numToBeRaised, exponent - 1);
}

int main() {
	int exit;
	cout << "2 to the power of 5 is " << raiseNumberToaPower(2, 5) << endl;
	cout << "3 to the power of 3 is " << raiseNumberToaPower(3, 3);

	cout << endl << "enter 0 to exit...";
	cin >> exit;
}