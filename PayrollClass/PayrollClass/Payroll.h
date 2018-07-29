/***********************************************************
Program: Payroll.cpp (Week 7 Programming Assignment 1)

This is a header file for Payroll.cpp.

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

#ifndef PAYROLL_H
#define PAYROLL_H
#pragma once

class Payroll {
public:
	Payroll();
	double getHourlyPayRate();
	double getNumberOfHoursWorked();
	double getTotalPayForTheWeek();
	void setHourlyPayRate(double rate);
	void setNumberOfHoursWorked(double hours);
private:
	double hourlyPayRate;
	double numberOfHoursWorked;
	double totalPayForTheWeek;
};

#endif