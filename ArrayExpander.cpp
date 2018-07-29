/***********************************************************
Program: "Array Expander" (Week 2 Programming Assignment 2)

This program creates a new array that is twice the size of the arguments array, copies the contents 
of the argument array to the new array, and initializes the unused elements of the second array with 0.

Detail: Array Expander. The program should have an array of integers. It will have a function that has
two parameters, the integer array and the array’s size. This function will create a new array that is 
twice the size of the arguments array. The function should copy the contents of the argument array to 
the new array, and initialize the unused elements of the second array with 0. The function must return 
a pointer to the new array. The program will then display the contents of the new array.

Program must have the following functions

int* expandArray(int[ ], int)
void showArray(int [ ], int)

Author: James Olney
Created: 01/15/2017
Revisions: 01/15/2017 Updated to pointer notations instead of array notations
*******************/

#include "stdafx.h"
#include <iostream>
using namespace std;

int* expandArray(int array[], int SIZE)
{
	int* expandArray = new int[SIZE * 2];
	for (int x = 0; x < SIZE; x++) {
		*(expandArray + x) = array[x];
	}
	for (int x = SIZE; x < SIZE * 2; x++) {
		*(expandArray + x) = 0;
	}
	return expandArray;
}

void showArray(int array[], int size) {
	for (int x = 0; x < size; x++) {
		cout << array[x] << " " << endl;
	}
}

int main()
{
	const int SIZE = 6;
	int exit = 0;
	int intArray[SIZE] = { 8,4,5,2,3,1 };	
	int* expandedArray = expandArray(intArray, SIZE);
	cout << "contents of expanded array:" << endl;
	showArray(expandedArray, SIZE * 2);
	cout << "enter 0 and press ENTER to exit" << endl;
	delete[] expandedArray;
	expandedArray = nullptr;
	cin >> exit;
    return 0;
}

