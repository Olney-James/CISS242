/*************************************
Program: Main.cpp (Week 6 Programming Assignment 2)

Author: James Olney
Created: 04/07/2017
Revisions: N/A

This is the main class that uses a function that accepts an integer
argument and returns the sum of all the integers from 1 up to the 
number passed as an argument. For example, if 10 is passed as an 
argument, the function will return the sum of 1,2,3,4,5,6,7,8,9 and 
10. Use recursion to calculate the sum. Show that this function 
works correctly for several values.

**************************************/

#include <iostream>
using namespace std;

int sumOfAllIntegers(int argument) {
	if (argument == 0) {
		return 0;
	}
	else {
		return argument + sumOfAllIntegers(argument - 1);
	}
}

int main() {
	int exit;

	cout << "the sum of all integers from 1 up to the number 10 is " << sumOfAllIntegers(10) << endl;
	cout << "the sum of all integers from 1 up to the number 15 is " << sumOfAllIntegers(15);

	cout << endl << "enter 0 to exit...";
	cin >> exit;
}