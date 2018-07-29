/***********************************************************
Program: PasswordVerifier.cpp (Week 3 Programming Assignment 1)

This program verifies a password input meets the following criteria:
	The password should be at least 6 characters long.
	The password should contain at least one uppercase and at least one lowercase letter.
	The password should have at least one digit.
	If the password does not meet these requirements, the program should display a message
	telling the user why the password is invalid, specifically.

Detail: Password Verifier. Here you will be creating part of a bigger program. Your task is 
to develop code that will verify the password the user is selecting meets the requirements 
of a password for the system. Create a program which will verify that a password meets the 
following criteria:

The password should be at least 6 characters long.
The password should contain at least one uppercase and at least one lowercase letter.
The password should have at least one digit.
If the password does not meet these requirements, the program should display a message 
telling the user why the password is invalid, specifically.

Program must have the following functions:

void validatePassword(char [ ])

Author: James Olney
Created: 01/16/2017
Revisions: N/A
*******************/

#include "stdafx.h"
#include <iostream>
#include <cctype>
using namespace std;

void validatePassword(char password[]) {
	bool containsDigit = false;
	bool containsUpperCase = false;
	bool containsLowerCase = false;
	bool meetsLengthRequirement = true;
	if ((unsigned)strlen(password) < 6) {
		meetsLengthRequirement = false;
	}
	for (int x = 0; x < (unsigned)strlen(password); x++) {
		if (isdigit(password[x])) {
			containsDigit = true;
		}
		if (isupper(password[x])) {
			containsUpperCase = true;
		}
		if (islower(password[x])) {
			containsLowerCase = true;
		}
	}
	if (!containsDigit || !containsUpperCase || !containsLowerCase || !meetsLengthRequirement) {
		cout << "Invalid Password!" << endl;
	}
	if (!meetsLengthRequirement) {
		cout << "The password should be at least 6 characters long." << endl;
	}
	if (!containsUpperCase) {
		cout << "The password should contain at least one uppercase letter" << endl;
	}
	if (!containsLowerCase) {
		cout << "The password should contain at least one lowercase letter." << endl;
	}
	if (!containsDigit) {
		cout << "The password should have at least one digit." << endl;
	}
}

int main()
{
	const int SIZE = 256;
	char input[SIZE];
	int exit = 1;
	cout << "The password should be at least 6 characters long." << endl;
	cout << "The password should contain at least one uppercase letter." << endl; 
	cout << "The password should contain at least one lowercase letter." << endl;
	cout << "The password should have at least one digit." << endl << endl;
	while (exit == 1) {
		cout << "Enter a password: ";
		cin >> input;
		validatePassword(input);
		cout << "enter 1 to restart or enter 0 to exit" << endl;
		cin >> exit;
	}
    return 0;
}