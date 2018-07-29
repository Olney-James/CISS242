/***********************************************************
Program: TestScores.cpp (Week 2 Programming Assignment 1)

This program dynamically allocates an array large enough to hold a user-defined number of test scores.

Detail: Once all the scores are entered by the user, the array must be passed to a function that sorts
them in ascending order. It must use another function that calculates the average score. The program 
should display the sorted list of scores and average with appropriate headings. The program must use 
pointer notation instead of array notation. Validation: Do not accept negative numbers for test scores; 
keep prompting the user for a new grade. Do not accept negative numbers for the number of scores the user 
wants to enter. The output should look like this:

Score

67.40

67.80

77.60

99.60

Average Score: 78.10

Program must have the following functions

void getGrades(double* score, int size)
void displayGrades(double* score, int size, double avg)
void sort(double* score, int size)
double average(double* score, int numScores)

Author: James Olney
Created: 01/12/2017
Revisions: 01/15/2017 updated array notations to be pointer notations instead
*******************/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void getGrades(double* score, int size) {
	for (int x = 0; x < size; x++) {
		cout << "Enter score " << (x + 1) << " : " << endl;
		cin >> *(score + x);
		while (score[x] < 0) {
			cout << "score must be positive!\n\n";
			cout << "Enter score " << (x + 1) << " : " << endl;
			cin >> *(score + x);
		}
	}
}

void displayGrades(double* score, int size, double average) {
	cout << "Score" << endl;
	for (int x = 0; x < size; x++) {
		cout << *(score + x) << " " << endl;
	}
	cout << "Average Score: " << average << endl;
}

void sort(double* score, int size) {
	bool swap;
	double temp;
	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (*(score + count) > *(score + count + 1)) {
				temp = *(score + count);
				*(score + count) = *(score + count + 1);
				*(score + count + 1) = temp;
				swap = true;
			}
		}
	} while (swap);
}

double average(double* score, int numScores) {
	double total = 0;
	for (int x = 0; x < numScores; x++) {
		total += *(score + x);
	}
	double average = total / numScores;
	return average;
}

int main()
{
	int size;
	double avg = 0;
	cout << "How many test scores do you want to enter? : " << endl;
	cin >> size;
	while (size < 0) {
		cout << "The number of test scores cannot be negative!\n\n";
		cout << "How many test scores do you want to enter? : " << endl;
		cin >> size;
	}
	double* score = new double[size];
	getGrades(score, size);
	avg = average(score, size);
	sort(score, size);
	displayGrades(score, size, avg);
	delete [] score;
	score = nullptr;
	cin >> size;
    return 0;
}