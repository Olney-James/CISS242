/*************************************
Program: FeetInches.cpp (Week 1 Programming Assignment 2)

Author: James Olney
Created: 03/04/2017
Revisions: N/A

This is the FeetInches class that is
provided in the course Content area on the assignment page for this week. This
program will show how classes will interact with each other as data members within
another class. I modified the FeetInches class by overloading the following operators
which should all return a bool.

<=
>=
!=
Next I added a copy constructor to the FeetInches class and a multiply function.

The copy constructor should accept a FeetInches object as an argument. It will
assign the feet attribute the value in the argument’s feet attribute and do the
same for the inches attributes.
The multiply function should accept a FeetInches object as an argument. The
argument object’s feet and inches attributes will be multiplied by the calling
object’s feet and inches attributes. It will return a FeetInches object containing
the result of the multiplication.


Detail: Carpet Calculator. This problem starts with the FeetInches class that is
provided in the course Content area on the assignment page for this week. This
program will show how classes will interact with each other as data members within
another class. Modify the FeetInches class by overloading the following operators
which should all return a bool.

<=
>=
!=
Next add a copy constructor to the FeetInches class and a multiply function.

The copy constructor should accept a FeetInches object as an argument. It will
assign the feet attribute the value in the argument’s feet attribute and do the
same for the inches attributes.
The multiply function should accept a FeetInches object as an argument. The
argument object’s feet and inches attributes will be multiplied by the calling
object’s feet and inches attributes. It will return a FeetInches object containing
the result of the multiplication.
Next create a class called RoomDimension which will have its class declaration in
RoomDimension.h and its implementation in RoomDimension.cpp. This class will have
two data members which have a data type of FeetInches, one for the length of the
room and another for the width of the room. The multiply function in FeedInches will
be used to calculate the area of the room. RoomDimension will have a function that
returns the area of the room as a FeetInches object.

Next create a class called RoomCarpet class that has a RoomDimension object as an
attribute. This class will have its class declaration in RoomCarpet.h and its
implementation in RoomCarpet.cpp.  It should also have an attribute for the cost
of the carpet per square foot. It will have a member function that returns the total
cost of the carpet. For example, a room that is 12 feet long and 10 feet wide has an
area of 120 square feet. If the cost per square foot is $8 then the cost to carpet
the room will be $960 (120 x 8).

The main for this program will create an instance of RoomCarpet and ask the user for
the dimensions of the room and the price per square foot for the carpet. The application
should then display the total cost of the carpet. It should allow the user to continue
doing more calculations until the user indicates they are done.

**************************************/

// Implementation file for the FeetInches class
#include <cstdlib>  // Needed for abs()
#include "FeetInches.h"

//************************************************************
// Definition of member function simplify. This function     *
// checks for values in the inches member greater than       *
// twelve or less than zero. If such a value is found,       *
// the numbers in feet and inches are adjusted to conform    *
// to a standard feet & inches expression. For example,      *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
// 5 feet -2 inches would be adjusted to 4 feet 10 inches.   *
//************************************************************

void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}

FeetInches FeetInches::multiply(const FeetInches & fi)
{
	FeetInches result;

	result.feet = fi.feet * feet;
	result.inches = fi.inches * inches;
	result.simplify();
	//result = this * result;
	return result;
}

//**********************************************
// Overloaded binary + operator.               *
//**********************************************

//FeetInches FeetInches::operator * (const FeetInches &right)
//{
//	FeetInches temp;
//
//	temp.inches = inches * right.inches;
//	temp.feet = feet * right.feet;
//	temp.simplify();
//	return temp;
//}

FeetInches FeetInches::operator + (const FeetInches &right)
{
	FeetInches temp;

	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}


//**********************************************
// Overloaded binary - operator.               *
//**********************************************

FeetInches FeetInches::operator - (const FeetInches &right)
{
	FeetInches temp;

	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();
	return temp;
}

//*************************************************************
// Overloaded prefix ++ operator. Causes the inches member to *
// be incremented. Returns the incremented object.            *
//*************************************************************

FeetInches FeetInches::operator ++ ()
{
	++inches;
	simplify();
	return *this;
}

//***************************************************************
// Overloaded postfix ++ operator. Causes the inches member to  *
// be incremented. Returns the value of the object before the   *
// increment.                                                   *
//***************************************************************

FeetInches FeetInches::operator ++ (int)
{
	FeetInches temp(feet, inches);

	inches++;
	simplify();
	return temp;
}

//************************************************************
// Overloaded > operator. Returns true if the current object *
// is set to a value greater than that of right.             *
//************************************************************

bool FeetInches::operator > (const FeetInches &right)
{
	bool status;

	if (feet > right.feet)
		status = true;
	else if (feet == right.feet && inches > right.inches)
		status = true;
	else
		status = false;

	return status;
}

//************************************************************
// Overloaded < operator. Returns true if the current object *
// is set to a value less than that of right.                *
//************************************************************

bool FeetInches::operator < (const FeetInches &right)
{
	bool status;

	if (feet < right.feet)
		status = true;
	else if (feet == right.feet && inches < right.inches)
		status = true;
	else
		status = false;

	return status;
}

//*************************************************************
// Overloaded == operator. Returns true if the current object *
// is set to a value equal to that of right.                  *
//*************************************************************

bool FeetInches::operator == (const FeetInches &right)
{
	bool status;

	if (feet == right.feet && inches == right.inches)
		status = true;
	else
		status = false;

	return status;
}

bool FeetInches::operator<=(const FeetInches &right)
{
	bool status;

	if (feet <= right.feet && inches <= right.inches) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

bool FeetInches::operator>=(const FeetInches &right)
{
	bool status;

	if (feet >= right.feet && inches >= right.inches) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

bool FeetInches::operator!=(const FeetInches &right)
{
	bool status;

	if (feet != right.feet && inches != right.inches) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const FeetInches &obj)
{
	strm << obj.feet << " feet, " << obj.inches << " inches";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into FeetInches objects.    *
//********************************************************

istream &operator >> (istream &strm, FeetInches &obj)
{
	// Prompt the user for the feet.
	cout << "Feet: ";
	strm >> obj.feet;

	// Prompt the user for the inches.
	cout << "Inches: ";
	strm >> obj.inches;

	// Normalize the values.
	obj.simplify();

	return strm;
}

//*************************************************************
// Conversion function to convert a FeetInches object         *
// to a double.                                               *
//*************************************************************

FeetInches::operator double()
{
	double temp = feet;

	temp += (inches / 12.0);
	return temp;
}

//*************************************************************
// Conversion function to convert a FeetInches object         *
// to an int.                                                 *
//*************************************************************

FeetInches:: operator int()
{
	return feet;
}