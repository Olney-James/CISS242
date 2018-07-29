/*************************************
Program: EmployeeInfo.h (Week 7 Programming Assignment 2)

Author: James Olney
Created: 04/15/2017
Revisions: N/A

This is the header file for EmployeeInfo.cpp

**************************************/

#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H
#pragma once
#include <string>
#include "BinaryTree.h"
//using namespace std;

class EmployeeInfo {
private:
	int empID;
	string empName;
public:
	EmployeeInfo();
	EmployeeInfo(int id, string name);
	void setEmpID(int id);
	void setEmpName(string name);
	int getEmpID();
	string getEmpName();
	bool operator > (const EmployeeInfo &);
	bool operator < (const EmployeeInfo &);
	bool operator == (const EmployeeInfo &);
	//bool operator<=(const EmployeeInfo &);
	//bool operator>=(const EmployeeInfo &);
	//bool operator!=(const EmployeeInfo &);


	friend ostream &operator << (ostream &, const EmployeeInfo &);
};

#endif // !EMPLOYEEINFO_H


