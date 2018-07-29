#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#pragma once
#include <string>
#include <iostream>
using namespace std;

//Employee class declaration

class Employee {
public:
	Employee(string n, int i, string d, string p) {
		name = n;
		idNumber = i;
		department = d;
		position = p;
	}
	Employee(string n, int i) {
		name = n;
		idNumber = i;
	}
	Employee() {

	}
	string name;
	int idNumber;
	string department;
	string position;
	void displayEmployee(Employee* const e);
	void printElement(const string& s, const int& width);
};

#endif