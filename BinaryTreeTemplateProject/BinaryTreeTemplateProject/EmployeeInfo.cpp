/*************************************
Program: EmployeeInfo.cpp (Week 7 Programming Assignment 2)

Author: James Olney
Created: 04/15/2017
Revisions: N/A

This is EmployeeInfo.cpp. It holds 2 private data members. One data member is
an integer called empID which holds the id number of the employee. The second 
data member is a string called empName which holds the full name of the employee.
The binary tree (in main.cpp) will need to be sorted by the Employee ID number 
found in the EmployeeInfo class. This is done by overloaded operators (>, <. ==, 
and <<) This also allows the user to search for Employee by the Employee ID. 

**************************************/

#include "EmployeeInfo.h"

EmployeeInfo::EmployeeInfo()
{
	empID = 0;
	empName = "";
}

EmployeeInfo::EmployeeInfo(int id, string name)
{
	empID = id;
	empName = name;
}

void EmployeeInfo::setEmpID(int id)
{
	empID = id;
}

void EmployeeInfo::setEmpName(string name)
{
	empName = name;
}

int EmployeeInfo::getEmpID()
{
	return empID;
}

string EmployeeInfo::getEmpName()
{
	return empName;
}

bool EmployeeInfo::operator>(const EmployeeInfo &right)
{
	bool status;

	if (empID > right.empID) {
		status = true;
	}
	else if (empID == right.empID) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

bool EmployeeInfo::operator<(const EmployeeInfo &right)
{
	bool status;

	if (empID < right.empID) {
		status = true;
	}
	else if (empID == right.empID) {
		status = true;
	}
	else {
		status = false;
	}

	return status;
}

bool EmployeeInfo::operator==(const EmployeeInfo &right)
{
	bool status;
	
	if (empID == right.empID) {
		status = true;
	}
	else { 
		status = false;
	}

	return status;
}

ostream & operator<<(ostream &strm, const EmployeeInfo &obj)
{
	strm << obj.empID << ", " << obj.empName;
	return strm;
}
