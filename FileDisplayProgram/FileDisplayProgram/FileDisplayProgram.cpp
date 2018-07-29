/***********************************************************
Program: FileDisplayProgram.cpp (Week 5 Programming Assignment 1)

This program will ask user for filename, then display the content of the file. If
the files contents wont fit, it will display 24 lines. Striking a key will present
24 more lines.

Detail: File Display Program. Write a program that asks the user for the name of 
a file. The program should display the content of the file on the screen. If the 
file’s contents won’t fit on a single screen, the program should display 24 lines 
of the output at a time, and then pause. Each time the program pauses, it should 
wait for the user to strike a key before the next 24 lines are displayed.

Author: James Olney
Created: 01/27/2017
Revisions: N/A
*******************/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void showContentsAndCloseFile(fstream &file) {
	int numOfLines = 24;
	string input;
	int goAgain;
	if (file) {
		getline(file, input);

		while (file) {
			while (numOfLines > 0) {  //read 24 lines
				cout << input << endl;
				getline(file, input);
				numOfLines--;
			}
			numOfLines = 24;
			cout << "enter 0 to continue: ";
			cin >> goAgain;
		}
		file.close();
	}
	else {
		cout << "ERROR: Cannot open file.\n";
	}
}

int main()
{
	fstream dataFile;
	string filename;
	int exit;
	string input;
	//cout << "Please enter a filename: ";
	//cin >> filename;
	filename = "C:\\Othello.txt";
	cout << "Opening file...\n";
	dataFile.open(filename, ios::in); //open for input
	showContentsAndCloseFile(dataFile); //display all
	cout << "enter 0 to exit...";
	cin >> exit;
    return 0;
}