/*************************************
Program: PersonData.cpp (Week 2 Programming Assignment 1)

Author: James Olney
Created: 03/06/2017
Revisions: N/A

This is the PersonData class it has private data member’s lastName, 
firstName, address, city, state, zip and phone number as strings. 
with accessor and mutator functions for these member variables.
It has two constructors. One constructor is a default
constructor that sets all of the data members to empty strings. The
second constructor has parameters for all of its data members.

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

#include "PersonData.h"

PersonData::PersonData()
{
	lastName = "";
	firstName = "";
	address = "";
	city = "";
	state = "";
	zipCode = "";
	phoneNumber = "";
}

PersonData::PersonData(string l, string f, string a, string c, string s, string z, string p)
{
	l = lastName;
	f = firstName;
	a = address;
	c = city;
	s = state;
	z = zipCode;
	p = phoneNumber;
}

void PersonData::setLastName(string l)
{
	lastName = l;
}

void PersonData::setFirstName(string f)
{
	firstName = f;
}

void PersonData::setAddress(string a)
{
	address = a;
}

void PersonData::setCity(string c)
{
	city = c;
}

void PersonData::setState(string s)
{
	state = s;
}

void PersonData::setZipCode(string z)
{
	zipCode = z;
}

void PersonData::setPhoneNumber(string p)
{
	phoneNumber = p;
}

string PersonData::getLastName()
{
	return lastName;
}

string PersonData::getFirstName()
{
	return firstName;
}

string PersonData::getAddress()
{
	return address;
}

string PersonData::getCity()
{
	return city;
}

string PersonData::getState()
{
	return state;
}

string PersonData::getZipCode()
{
	return zipCode;
}

string PersonData::getPhoneNumber()
{
	return phoneNumber;
}
