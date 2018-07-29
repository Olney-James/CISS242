/***********************************************************
Program: Circle.cpp (Week 6 Programming Assignment 2)

This program is a class used to create circle objects. it contains two constructors. 
One constructor accepts a radius as a parameter, and the other is a default constructor
that automatically sets the radius to 0.0. This class also has a mutator function to 
set the radius, an accessor function for radius, and functions to calculate the area,
diameter, and circumference.

Detail: Circle Class. Write a class name Circle, with the class declaration in a file
called Circle.h and the implementation in a file called Circle.cpp. The class will
have two data members, a double that holds the radius of the circle and a double
called pi which will be set to the value, 3.14159 (data member cannot be set in the
class declaration, pi should not be set via a parameter but set in the constructor).
The class must provide the following member functions
Default Constructor – that sets the radius to 0.0
Constructor – that accepts the radius of the circle as an argument
setRadius – a mutator function for the radius variable
getRadius – an accessor function for the radius variable
getArea – calculates and returns (as double) the area of the circle using the formula
area = pi * radius * radius
getDiameter – calculates and returns (as double) the diameter of the circle using the
formula
diameter = radius * 2
getCircumference – calculates and returns (as double) the circumference of the circle
using the formula
circumference = 2 * pi * radius
Write a program that demonstrates the Circle class by asking the user for the circle’s
radius and creating a Circle object and then reporting the circle’s area, diameter and
circumference. Two objects need to be created each using one of the two constructors
(showing that both work along with the mutators and accessors).

Author: James Olney
Created: 02/11/2017
Revisions: N/A
*******************/

#include "Circle.h"

Circle::Circle()
{
	radius = 0.0;
	pi = 3.14159;
}

Circle::Circle(double r)
{
	radius = r;
	pi = 3.14159;
}

void Circle::setRadius(double r)
{
	radius = r;
}

double Circle::getRadius()
{
	return radius;
}

double Circle::getArea()
{
	double area = pi * radius * radius;
	return area;
}

double Circle::getDiameter()
{
	double diameter = radius * 2;
	return diameter;
}

double Circle::getCircumference()
{
	double circumference = 2 * pi * radius;
	return circumference;
}
