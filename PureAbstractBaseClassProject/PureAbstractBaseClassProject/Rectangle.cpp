/*************************************
Program: Rectangle.cpp (Week 2 Programming Assignment 2)

Author: James Olney
Created: 03/06/2017
Revisions: N/A

This is the Rectangle class. It is a derived class of the
BasicShape class. This class has 2 private data members called
width and length. Both data members are long integers. Its
constructor has parameters for both the width and length. It 
overrides the calcArea function. For this class the calcArea
function uses the formula area = length * width. It provides
member functions called getWidth and getLength which return 
correct values.

Detail: Assignment 2

Pure Abstract Base Class Project. Define a class called BasicShape
which will be a pure abstract class. The class will have one
protected data member that will be a double called area. It will
provide a function called getArea which should return the value of
the data member area. It will also provide a function called
calcArea which must be a pure virtual function.

Define a class called Circle. It should be a derived class of the
BasicShape class. This class will have 3 private data members. It
will have 2 long integer data members called centerX and centerY.
The last data member is a double called radius. It will have a
constructor that accepts values for centerX, centerY and radius.
This constructor should call the overridden calcArea function of
this class. This class defines its version of the calcArea function
which determines the area of the circle using the formula area =
3.14159 * radius * radius. The class will also provide two functions
called getCenterX and getCenterY which return the correct values.

Define a class called Rectangle. It should be a derived class of the
BasicShape class. This class will have 2 private data members called
width and length. Both data members should be long integers. Its
constructor will have parameters for both the width and length. It will
also override the calcArea function. For this class the calcArea
function will use the formula area = length * width. It will provide
member function called getWidth and getLength which should return the
correct values.

In main create instances of the Circle and Rectangle classes. It should
then display the area of the two shapes using a function defined as

void DisplayArea(BasicShape* shape)

**************************************/

#include "Rectangle.h"

Rectangle::Rectangle(long w, long l)
{
	width = w;
	length = l;
	area = calcArea();
}

double Rectangle::calcArea() const
{
	double area = (double)length * (double)width;
	return area;
}

long Rectangle::getWidth()
{
	return width;
}

long Rectangle::getLength()
{
	return length;
}
