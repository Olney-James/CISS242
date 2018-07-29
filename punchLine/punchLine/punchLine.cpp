/***********************************************************
Program: punchLine.cpp (Week 5 Programming Assignment 2)

This program reads and prints a joke and it's punch line from two files. One file contains a joke,
but not the punch line. The punch line will be the last line of the second file.


Detail: Punch Line: Write a program that reads and prints a joke and its punch line from two different
files (please keep it clean). The first file contains a joke, but not its punch line. The 
second file has the punch line as its last line, preceded by “garbage text” (does not matter 
what it is).  NOTE: the last sentence (punch line) will have a newline character before it. 
The program is to search for the start of the last sentence; it should NOT move backward from 
the file a fixed number of characters. It should work for any punch line file. The main function
of your program should open the two files and then call two functions, passing each one the file 
it needs. The first function should read and display each line in the file it is passed (the joke 
file). The second function should display only the last line of the file it is passed (the punch 
line file). IT should find this line by seeking to the end of the file and then backing up to the 
beginning of the last line. Data to test your program can be found in the joke.txt and punchline.
text files provided at the textbook web site.
Program must have the following functions

void displayAllLines(ifstream &infile);  //Display joke
void displayLastLine(ifstream &infile);  //Display punchline

Author: James Olney
Created: 01/16/2017
Revisions: N/A
*******************/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void displayAllLines(ifstream &infile) { //Display joke
	string input;
	if (infile) {
		getline(infile, input);
		while (infile) {
			cout << input << endl;
			getline(infile, input);
		}
		infile.close();
	}
	else {
		cout << "ERROR: Cannot open file.\n";
	}
}
void displayLastLine(ifstream &infile) {  //Display punchline
	string input;
	if (infile) {
		getline(infile, input);
		while (infile) {
			getline(infile, input);
		}
		infile.close();
		cout << input << endl;
	}
	else {
		cout << "ERROR: Cannot open file.\n";
	}
}

int main()
{
	ifstream dataInFile;
	ifstream dataInFileTwo;
	string jokeFileName = "C:\\joke.txt";
	string punchLineFileName = "C:\\punchline.txt";
	int exit;
	dataInFile.open(jokeFileName, ios::in); //open for input
	dataInFileTwo.open(punchLineFileName, ios::in); //
	displayAllLines(dataInFile); //display all
	cout << endl << "Enter 0 for punchline: ";
	cin >> exit;
	cout << endl;
	displayLastLine(dataInFileTwo);//display punchline
	cout << endl << "Enter 0 to exit...";
	cin >> exit;
    return 0;
}