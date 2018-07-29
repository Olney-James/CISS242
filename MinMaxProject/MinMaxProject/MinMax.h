/*************************************
Program: MinMax.h (Week 3 Programming Assignment 2)

Author: James Olney
Created: 03/17/2017
Revisions: N/A

This is the header file for MinMax.cpp.

**************************************/

#ifndef MINMAX_H
#define MINMAX_H
#pragma once

template <class T>
class MinMax {
private:
	T firstDataMember;
	T secondDataMember;
public:
	MinMax(T,T);
	T minimum();
	T maximum();
};

template class MinMax<int>;
template class MinMax<double>;
template class MinMax<char>;
#endif
