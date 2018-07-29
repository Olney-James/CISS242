/***********************************************************
Program: Circle.h (Week 6 Programming Assignment 2)

This is the header file for Circle.cpp.

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

#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once

class Circle {
public:
	Circle();
	Circle(double r);
	void setRadius(double r);
	double getRadius();
	double getArea();
	double getDiameter();
	double getCircumference();
private:
	double radius;
	double pi;
};

#endif