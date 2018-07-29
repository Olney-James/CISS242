/*************************************
Program: DriverMain.cpp (Week 5 Programming Assignment 1)

Author: James Olney
Created: 03/30/2017
Revisions: N/A

This is the driver program(main) that shows that the stack 
works for at least two different data types.

**************************************/

#include "StackClassTemplate.h"
#include <iostream>
//#include "DriverMain.h"
using namespace std;

template<class T>
void print(StackClassTemplate<T> &stack) {
	cout << "stack: ";
	stack.printStack();
}

int main() {
	int exit;
	StackClassTemplate<int> myIntStackClassTemplate;
	StackClassTemplate<double> myDoubleStackClassTemplate;

	if (myIntStackClassTemplate.isEmpty()) {
		cout << "myIntStackClassTemplate is empty" << endl;
	}
	if (myDoubleStackClassTemplate.isEmpty()) {
		cout << "myDoubleStackClassTemplate is empty" << endl;
	}

	int firstInt = 8;
	int secondInt = 6;
	double firstDouble = 7.5;
	double secondDouble = 5.5;

	cout << "myIntStackClassTemplate: " << endl;
	myIntStackClassTemplate.push(firstInt);
	print(myIntStackClassTemplate);
	myIntStackClassTemplate.push(secondInt);
	print(myIntStackClassTemplate);
	myIntStackClassTemplate.pop(secondInt);
	print(myIntStackClassTemplate);
	
	cout << "myDoubleStackClassTemplate: " << endl;
	myDoubleStackClassTemplate.push(firstDouble);
	print(myDoubleStackClassTemplate);
	myDoubleStackClassTemplate.push(secondDouble);
	print(myDoubleStackClassTemplate);
	myDoubleStackClassTemplate.pop(secondDouble);

	cout << "enter 0 to exit...";
	cin >> exit;
}