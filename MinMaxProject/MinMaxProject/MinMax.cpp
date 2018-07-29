/*************************************
Program: MinMax.cpp (Week 3 Programming Assignment 2)

Author: James Olney
Created: 03/17/2017
Revisions: N/A

This is a class called MinMax which is a template class. The class has
two data members which have a data type of the template. The class provides
two member functions called minimum and maximum. The function minimum determines
which of the two data members is the lower of the two and return that value. The
function maximum determines which of the two data members is the larger of the 
two and returns that value. 

**************************************/

#include "MinMax.h"

template<class T>
MinMax<T>::MinMax(T f, T s)
{
	firstDataMember = f;
	secondDataMember = s;
}

template<class T>
T MinMax<T>::minimum()
{
	T minimum;

	if (firstDataMember < secondDataMember) {
		minimum = firstDataMember;
	}
	else {
		minimum = secondDataMember;
	}
	return minimum;
}

template<class T>
T MinMax<T>::maximum()
{
	T maximum;
	if (firstDataMember > secondDataMember) {
		maximum = firstDataMember;
	}
	else {
		maximum = secondDataMember;
	}
	return maximum;
}