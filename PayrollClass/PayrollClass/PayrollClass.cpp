/***********************************************************
Program: PayrollClass.cpp (Week 7 Programming Assignment 1)

This program creates an array of 7 payroll objects, and enters payrate for each.
then, it prompts the user to enter the hours worked for each. Then it displays 
the gross pay for each. this program will not accept values greater than 60 for 
the hours worked.


Detail: Payroll. Write a class name Payroll, with the class declaration in a file
Payroll.h and the implementation in a file called Payroll.cpp.The class will have 
data members for an employee’s hourly pay rate, number of hours worked and total 
pay for the week.All of the data members will be doubles.The class only needs one
constructor which can be a default constructor that sets all data members to zero.
Then add the mutators and accessor for the class.The program will have an array 
of 7 Payroll objects.The program will prompt the user for number of hours each 
employee has worked and will then display the amount of gross pay each has earned.
Before asking the user for the hours, the program should set the pay rate for 
each employee without user input.Validation : Do not accept values greater than 
60 for the number of hours worked.

Author: James Olney
Created: 02/11/2017
Revisions: N/A
*******************/
#include "Payroll.h"
#include <iostream>
using namespace std;

int main() {
	int exit;
	double hoursWorked;
	const int arrayLength = 7;
	Payroll payrollArray[arrayLength];
	payrollArray[0].setHourlyPayRate(10);
	payrollArray[1].setHourlyPayRate(12.5);
	payrollArray[2].setHourlyPayRate(7.5);
	payrollArray[3].setHourlyPayRate(13);
	payrollArray[4].setHourlyPayRate(11.5);
	payrollArray[5].setHourlyPayRate(27.8);
	payrollArray[6].setHourlyPayRate(18);
	for (int x = 0; x < arrayLength; x++) {
		do {
			cout << "please enter the number of hours employee " << x+1 << " has worked: ";
			cin >> hoursWorked;
			if (hoursWorked > 60) {
				cout << "hours worked cannot be greater than 60!" << endl;
			}
		} while (hoursWorked > 60);
		payrollArray[x].setNumberOfHoursWorked(hoursWorked);
	}
	cout << endl << "Gross pay for each employee: " << endl;
	for (int x = 0; x < arrayLength; x++) {
		cout << "Employee " << x+1 << ": " << payrollArray[x].getTotalPayForTheWeek() << endl;
	}
	cout << endl << "enter 0 to exit...";
	cin >> exit;
}