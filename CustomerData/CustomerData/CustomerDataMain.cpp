/*************************************
Program: CustomerDataMain.cpp (Week 2 Programming Assignment 1)

Author: James Olney
Created: 03/06/2017
Revisions: N/A

This is the main class that creates two instances of the CustomerData 
class. It createst one instance using the default constructor and then
another using the second constructor. Once both instances are fully 
populated with data, a function is called that will display the customer 
information.

Detail: Customer Data. This program will have two classes. The first 
class defines a person, which means this class can be used for 
anything that involves a person. We will use it to define a Customer 
but it could be used to define a Student.

Create a class called PersonData and it will have its class 
declaration in PersonData.h and its implementation in PersonData.cpp. 
This class will have private data member’s lastName, firstName, 
address, city, state, zip and phone number as strings. Write the 
appropriate accessor and mutator functions for these member variables. 
It should have two constructors. One constructor is a default 
constructor that sets all of the data members to empty strings. A 
second constructor has parameters for all of its data members.

Create a class called CustomerData which will have its class 
declaration in CustomerData.h and its implementation in 
CustomerData.cpp. This class will be a derived class of PersonData. 
This class will have two private data members for the customer number 
(customerNumber) as an integer; the other will be called mailingList
which is a bool to indicate if they want to be on the mailing list or 
not. Write appropriate accessor and mutator functions for these data 
members. This class will also have two constructors. It will have a 
default constructor that sets its data members to zero and false. The 
other constructor will have parameters to set all of the data members 
of the two classes.

Create a program that will create two instances of the CustomerData 
class. It must create one instance using the default constructor and
then another using the second constructor. Once both instances are 
fully populated with data, call a function that will display the 
customer information.

void displayCustomer(CustomerData c)
**************************************/

#include "CustomerData.h"
#include "PersonData.h"
#include <iostream>

void displayCustomer(CustomerData c) {
	cout << "Last Name: " << c.getLastName()<<endl;
	cout << "First Name: " << c.getFirstName() << endl;
	cout << "Address: " << c.getAddress() << endl;
	cout << "City: " << c.getCity() << endl;
	cout << "State: " << c.getState() << endl;
	cout << "ZIP: " << c.getZipCode() << endl;
	cout << "Customer Number: " << c.getCustomerNumber() << endl;
	cout << "Mailing List? ";
	if (c.getMailingList()) {
		cout << "Yes"<<endl;
	}
	else {
		cout << "No" << endl;
	}
	cout << endl;
}

int main() {
	int exit;

	CustomerData myCustomerData = CustomerData();
	CustomerData mySecondCustomerData("Smith", "John", "123 Main Street", "Grantsville", "UT", "84029", "(801)882-1234",11111, true);
	myCustomerData.setLastName("Olney");
	myCustomerData.setFirstName("James");
	myCustomerData.setAddress("515 Colorow Way");
	myCustomerData.setCity("Salt Lake City");
	myCustomerData.setState("UT");
	myCustomerData.setZipCode("84108");
	myCustomerData.setPhoneNumber("(801)882-1234");
	myCustomerData.setCustomerNumber(22222);
	myCustomerData.setMailingList(false);
	/*mySecondCustomerData.setLastName("Smith");
	mySecondCustomerData.setFirstName("John");
	mySecondCustomerData.setAddress("123 Main Street");
	mySecondCustomerData.setCity("Grantsville");
	mySecondCustomerData.setState("UT");
	mySecondCustomerData.setZipCode("84029");*/
	cout << "Customer #1" << endl;
	cout << "-----------" << endl;
	displayCustomer(myCustomerData);
	cout << "Customer #2" << endl;
	cout << "-----------" << endl;
	displayCustomer(mySecondCustomerData);
	cout << "enter 0 to exit...";
	cin >> exit;
}