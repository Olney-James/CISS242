// Employee.cpp : Defines the entry point for the console application.
//

#include "Employee.h"
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

Employee::Employee(string n, int i, string d, string p)
{
}

Employee::Employee(string n, int i)
{
	string department = " ";
	string position = " ";
}

Employee::Employee() {
	string name = "";
	int idNumber = 0;
	string department = "";
	string position = "";
}

void Employee::printElement(const string& s, const int& width)
{
	cout << left << setw(width);
	cout.fill(' ');
	cout << s;
}

void Employee::displayEmployee(Employee* const e) {
	const int nameWidth = 6;
	const int numWidth = 8;

	printElement("Name", nameWidth);
	printElement("ID Number", nameWidth);
	printElement("Department", nameWidth);
	printElement("Position", nameWidth);
	cout << endl << "-------------------------------------------------------" << endl;
	printElement(e->name, nameWidth);
	printElement(e->idNumber, numWidth);
	printElement(e->department, nameWidth);
	printElement(e->position, nameWidth);
	cout << endl;
}