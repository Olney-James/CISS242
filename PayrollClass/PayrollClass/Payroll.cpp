/***********************************************************
Program: Payroll.cpp (Week 7 Programming Assignment 1)

This program organizes a payroll object made up of hourly pay rate, hours worked,
and total pay for the week. These are all doubles. There is only a default 
constructor that sets all values to 0.0.

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

Payroll::Payroll()
{
	hourlyPayRate = 0.0;
	numberOfHoursWorked = 0.0;
	totalPayForTheWeek = 0.0;
}

double Payroll::getHourlyPayRate()
{
	return hourlyPayRate;
}

double Payroll::getNumberOfHoursWorked()
{
	return numberOfHoursWorked;
}

double Payroll::getTotalPayForTheWeek()
{
	totalPayForTheWeek = hourlyPayRate*numberOfHoursWorked;
	return totalPayForTheWeek;
}

void Payroll::setHourlyPayRate(double rate)
{
	hourlyPayRate = rate;
}

void Payroll::setNumberOfHoursWorked(double hours)
{
	numberOfHoursWorked = hours;
}

