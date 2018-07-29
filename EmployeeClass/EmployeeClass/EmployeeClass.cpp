/***********************************************************
Program: EmployeeClass.cpp (Week 6 Programming Assignment 1)

This program creates 3 Employee objects, using 3 different constructors. It then uses
mutator functions to set the missing variables, and then uses accessor functions to 
display these in the form of a table using the functions displayEmployee() and 
printElement().

Detail: Employee Class. Write a class named Employee, with the class declaration in
a file called Employee.h and the implementation in a file called Employee.cpp. The 
class should have the following data members:
name – A string that holds the employee’s name
idNumber – An int variable that holds the employee’s ID number
department – a string that holds the name of the department where the employee works
position – A string that holds the employee’s job status
The class must have the following constructors:
A constructor that accepts the following values as arguments and assigns them to the
appropriate number variables: employee’s name, employee’s ID number, department and 
position.
A constructor that accepts the following values as arguments and assigns them to the 
appropriate member variable: employee’s name, employee’s ID number. The department 
and position fields should be assigned an empty string (“ “).
A default constructor that assigns empty string (“”) to the name, department and 
position member variables and 0 to the idNumber member variable. Write the appropriate 
mutator functions that store values in these member variables and accessor functions 
that return the values in these member variables. Once you have written the class, write
a separate program that creates 3 instances of the Employee class. Each instance of the 
class should use a different constructor than the other 2 objects (so all three 
constructors must be used). Main should use a function called displayEmployee that has 
one parameter which is a pointer to a constant Employee object. Main will call the 
function 3 times to display the information for each of the 3 instances of the Employee 
class.
void displayEmployee(Employee* const e);
The output of the program must be in the form of a table

Author: James Olney
Created: 02/10/2017
Revisions: N/A
*******************/

#include "Employee.h"
#include <iomanip>

void printElement(const string& s)
{
	cout << left << setw(22);
	cout.fill(' ');
	cout << s;
}

void printHeader() {
	printElement("Name");
	printElement("ID Number");
	printElement("Department");
	printElement("Position");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
}

void displayEmployee(Employee* const e) {
	printElement(e->getName());
	printElement(to_string(e->getIdNumber()));
	printElement(e->getDepartment());
	printElement(e->getPosition());
	cout << endl;
}

int main() {
	int exit;
	Employee emp1("James", 12, "Software", "Engineer");
	Employee emp2("Brian", 11);
	emp2.setDepartment("Machining");
	emp2.setPosition("Machinist");
	Employee emp3;
	emp3.setName("Camilla");
	emp3.setIdNumber(10);
	emp3.setDepartment("Accounting");
	emp3.setPosition("Trainer");
	printHeader();
	displayEmployee(&emp1);
	displayEmployee(&emp2);
	displayEmployee(&emp3);
	cout << endl << "enter 0 to exit...";
	cin >> exit;
}
