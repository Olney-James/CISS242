/*************************************
Program: FeetInches.h (Week 1 Programming Assignment 2)

Author: James Olney
Created: 03/04/2017
Revisions: N/A

This is the header file for FeetInches.cpp.

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

// Specification file for the FeetInches class
#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;

class FeetInches; // Forward Declaration

				  // Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const FeetInches &);
istream &operator >> (istream &, FeetInches &);

// The FeetInches class holds distances or measurements 
// expressed in feet and inches.

class FeetInches
{
private:
	int feet;        // To hold a number of feet
	int inches;      // To hold a number of inches
	void simplify(); // Defined in FeetInches.cpp
public:
	//copy constructor
	FeetInches(const FeetInches &fi) {
		feet = fi.feet;
		inches = fi.inches;
	}

	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	//multiply function
	FeetInches multiply(const FeetInches &fi);

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	// Overloaded operator functions
	//FeetInches operator * (const FeetInches &);
	FeetInches operator + (const FeetInches &);
	FeetInches operator - (const FeetInches &);
	FeetInches operator ++ ();    // Prefix ++
	FeetInches operator ++ (int); // Postfix ++
	bool operator > (const FeetInches &);
	bool operator < (const FeetInches &);
	bool operator == (const FeetInches &);
	bool operator<=(const FeetInches &);
	bool operator>=(const FeetInches &);
	bool operator!=(const FeetInches &);
	

	// Conversion functions
	operator double();
	operator int();

	// Friends
	friend ostream &operator << (ostream &, const FeetInches &);
	friend istream &operator >> (istream &, FeetInches &);
};

#endif