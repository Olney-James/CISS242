/***********************************************************
Program: LotteryWinners.cpp (Week 1 Programming Assignment 1)

This program determines if the user is a winner in a lottery game. 

Detail: A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit "lucky" 
combinations. The program initializes an array with these numbers and then let the player enter this 
week's winning 5-digit number. The program performs both a linear search and a binary search through 
the list of player's numbers to report whether or not one of the tickets is a winner this week. Here
are the numbers, and the array is created with the values in this order: 13579, 62483, 26791, 77777, 
26792, 79422, 33445, 85647, 55555, 93121.

Author: James Olney
Created: 01/04/2017
Revisions: N/A
*******************/

#include "stdafx.h"
#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
	bool swap;
	int temp;

	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (array[count] > array[count + 1]) {
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int binarySearch(const int array[], int numElems, int value) {
	int first = 0;
	int last = numElems - 1;
	int middle;
	int position = -1;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (array[middle] == value) {
			found = true;
			position = middle;
		}
		else if (array[middle] > value) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}
	return position;
}

int main()
{
	int buyersTickets[10] = {13579, 62483, 26791, 77777, 26792, 79422, 33445, 85647, 55555, 93121};
	int buyersTicketsSize = sizeof(buyersTickets) / sizeof(buyersTickets[0]);
	int winningNumber;
	int results;
	bool win = false;

	cout << "Enter this week's winning 5-digit number:";
	cin >> winningNumber;
	//linear search
	for (int x = 0; x < buyersTicketsSize; x++) {
		if (winningNumber == buyersTickets[x]) {
			cout << "you win!!! Ticket " << x + 1 << " is the winning ticket!!!" << endl;
			win = true;
			break;
		}
	}
	if (!win) {
		cout << "Sorry, but you didn't win. " << endl << "The number was not found within your list of ticket numbers." << endl;
	}
	//sort array
	bubbleSort(buyersTickets, buyersTicketsSize);
	cout << "array has been sorted." << endl;
	//binary search
	results = binarySearch(buyersTickets, buyersTicketsSize, winningNumber);
	if (results == -1) {
		cout << "Sorry, but you didn't win. " << endl << "The number was not found within your list of ticket numbers." << endl;
	}
	else {
		cout << "you win!!! Ticket " << results + 1 << " is the winning ticket!!!" << endl;
	}
	cout << "Enter 0 to close.";
	cin >> winningNumber;
    return 0;
}