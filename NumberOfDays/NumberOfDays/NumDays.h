/*************************************
Program: NumDays.h (Week 1 Programming Assignment 1)

Author: James Olney
Created: 02/27/2017
Revisions: N/A

This is the header class for NumDays.cpp

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

#ifndef NUMDAYS_H
#define NUMDAYS_H
#pragma once

class NumDays {
public:
	NumDays();
	NumDays(int numOfHours);
	int getHours();
	double getDays();
	void setHours(int h);
	NumDays operator+(const NumDays &);
	NumDays operator-(const NumDays &);
	NumDays operator++();
	NumDays operator++(int);
	NumDays operator--();
	NumDays operator--(int);
private:
	int hours;
	double days;
	void setDays(double d);
};

#endif