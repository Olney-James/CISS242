/*************************************
Program: NumberOfDays.cpp (Week 1 Programming Assignment 1)

Author: James Olney
Created: 02/27/2017
Revisions: N/A

This is the main class testing the overloaded functions in the NumDays class. Each
function is tested within this class.

Detail: Number of Days. Design a class called NumDays. The class’s purpose is to store a 
value that will convert the number of worked hours to a number of days. For 
example, 8 hours would be converted to 1 day, 12 hours would be converted to 1.5 
days and 18 hours converted to 2.25 days. The class must have a constructor that 
accepts a number of hours. There must also be member function to set and get the 
hours and days. The class should have 2 data members, hours and days.

The class will also overload several operators:
the addition operator. This operator will add the hours of the two objects and 
return a new instance of the NumDays with its hour’s data member set to the sum of
the other two objects.
the subtraction operator will also be overloaded which will subtract the two 
objects and return a new instance of the NumDays class.
the prefix and postfix increment operator. These operators should increment the 
number of hours stored in the object. It will return an instance of the NumDays 
object.
the prefix and postfix decrement operator. These operators should decrement the 
number of hours stored in the object. It will return an instance of the NumDays 
object.
Note that when the number of hours changes, the number of days should always be updated. The user of this class should be able to use the object in a statement like C = A + B; where A, B and C are instances of the NumDays class. Main must show that the class and all the operators work correctly.

**************************************/
#include "NumDays.h"
#include <iostream>
using namespace std;

int main() {
	int exit;

	NumDays myNumDays(12);
	NumDays myNumDays2(18);

	cout << "myNumDays hours: " << myNumDays.getHours() << endl;
	cout << "myNumDays days: " << myNumDays.getDays() << endl;
	cout << "myNumDays2 hours: " << myNumDays2.getHours() << endl;
	cout << "myNumDays2 days: " << myNumDays2.getDays() << endl;

	cout << endl << "adding myNumDays and myNumDays2 to make myNumDays3..." << endl;
	NumDays myNumDays3 = myNumDays + myNumDays2;
	cout << "myNumDays3 hours: " << myNumDays3.getHours() << endl;
	cout << "myNumDays3 days: " << myNumDays3.getDays() << endl;

	cout << endl << "subtracting myNumDays2 from myNumDays3..." << endl;
	myNumDays3 = myNumDays3 - myNumDays2;
	cout << "myNumDays3 hours: " << myNumDays3.getHours() << endl;
	cout << "myNumDays3 days: " << myNumDays3.getDays() << endl;

	cout << endl << "testing prefix(++obj) operator..." << endl;
	NumDays myNumDays4;
	for (int x = 0; x < 2; x++) { 
		myNumDays4 = ++myNumDays3;
		cout << "myNumDays4 hours: " << myNumDays4.getHours() << " myNumDays3 hours: " << myNumDays3.getHours() << endl;
		cout << "myNumDays4 days: " << myNumDays4.getDays() << " myNumDays3 days: " << myNumDays3.getDays() << endl;
	}

	cout << endl << "testing postfix(obj++) operator..." << endl;
	NumDays myNumDays5;
	for (int x = 0; x < 2; x++) {
		myNumDays5 = myNumDays3++;
		cout << "myNumDays5 hours: " << myNumDays5.getHours() << " myNumDays3 hours: " << myNumDays3.getHours() << endl;
		cout << "myNumDays5 days: " << myNumDays5.getDays() << " myNumDays3 days: " << myNumDays3.getDays() << endl;
	}

	cout << endl << "testing prefix(--obj) operator..." << endl;
	NumDays myNumDays6;
	for (int x = 0; x < 2; x++) {
		myNumDays6 = --myNumDays3;
		cout << "myNumDays6 hours: " << myNumDays6.getHours() << " myNumDays3 hours: " << myNumDays3.getHours() << endl;
		cout << "myNumDays6 days: " << myNumDays6.getDays() << " myNumDays3 days: " << myNumDays3.getDays() << endl;
	}

	cout << endl << "testing postfix(obj--) operator..." << endl;
	NumDays myNumDays7;
	for (int x = 0; x < 2; x++) {
		myNumDays7 = myNumDays3--;
		cout << "myNumDays7 hours: " << myNumDays7.getHours() << " myNumDays3 hours: " << myNumDays3.getHours() << endl;
		cout << "myNumDays7 days: " << myNumDays7.getDays() << " myNumDays3 days: " << myNumDays3.getDays() << endl;
	}

	cout << "enter 0 to exit...";
	cin >> exit;
}