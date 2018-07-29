/***********************************************************
Program: PhoneNumberList.cpp (Week 3 Programming Assignment 2)

This program asks the user to enter a name or partial name to search for in an array, and
returns any entries in the array that match the string entered displayed to the user.

Detail: Phone Number List. This program should have an array of at least 10 string objects. 
The array will hold people’s names and phone numbers. The following list is an example of 
the data in the array.
"Renee Javens, 678-1223",
"Joe Looney, 586-0097",
"Geri Palmer, 223-8787",
"Lynn Presnell, 887-1212",
"Bill Wolfe, 223-8878",
"Sam Wiggins, 486-0998",
"Bob Kain, 586-8712",
"Tim Haynes, 586-7676",
"John Johnson, 223-9037",
"Jean James, 678-4939",
"Ron Palmer, 486-2783"
The program should ask the user to enter a name or partial name to search for in the array.
Any entries in the array that match the string entered should be displayed. For example, 
if the user enters “Palmer” the program should display the following names from the list:
Geri Palmer, 223-8787
Ron Palmer, 486-2783
Note: if the user enters “Pal” it should produce the same output.

Author: James Olney
Created: 01/16/2017
Revisions: N/A
*******************/

#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
	char input[256];
	char list[11][256] = { 
		"Renee Javens, 678-1223", 
		"Joe Looney, 586-0097", 
		"Geri Palmer, 223-8787", 
		"Lynn Presnell, 887-1212", 
		"Bill Wolfe, 223-8878", 
		"Sam Wiggins, 486-0998", 
		"Bob Kain, 586-8712", 
		"Tim Haynes, 586-7676", 
		"John Johnson, 223-9037", 
		"Jean James, 678-4939", 
		"Ron Palmer, 486-2783" 
	};
	cout << "enter a name or partial name to search for in the array: ";
	cin >> input;
	for (int x = 0; x < 11; x++) {
		if (strstr(list[x], input) != NULL) {
			cout << list[x] << endl;
		}
	}
	int exit = 1;
	cout << "enter 0 to exit" << endl;
	cin >> exit;
    return 0;
}