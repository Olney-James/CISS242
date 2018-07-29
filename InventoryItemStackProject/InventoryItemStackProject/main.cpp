/*************************************
Program: main.cpp (Week 5 Programming Assignment 2)

Author: James Olney
Created: 03/30/2017
Revisions: N/A

This is the main class that creates a stack with a data type of InventoryItem.
The class will loop, askin the user to enter in new items to the inventory stack
or to remove an item from the inventory stack. The loop should continue until the
user indicates they are done. This is menu driven. When adding an item, the
program asks the user for the information it needs for the 3 data members of the
InventoryItem class and add a new item to the stack. When removing an item from 
the stack, the program displays all the information in the InventoryItem object
that was popped off the stack. When main ends, it pops all the remaining items off
the stack and displays that data that is in the InventoryItems as it pops them off.

There are 3 utility functions that main uses:

void popItem(DynStack<InventoryItem>* stack) // pops the item off the stack and displays it.
void pushItem(DynStack<InventoryItem>* stack) // pushes the item onto the stack
int menu();  // displays the menu and returns the user’s choice.
**************************************/

#include <iostream>
using namespace std;
#include "InventoryItem.h"
#include "StackClassTemplate.h"

void popItem(StackClassTemplate<InventoryItem>* stack); // pops the item off the stack and displays it.
void pushItem(StackClassTemplate<InventoryItem>* stack); // pushes the item onto the stack
int menu();  // displays the menu and returns the user’s choice.

int main() {
	int exit = 3;

	StackClassTemplate<InventoryItem> myInventoryItemStack;

	while(exit != 0) {
		exit = menu();
		switch (exit) {
		case 0: while (myInventoryItemStack.isEmpty() == false) {
				popItem(&myInventoryItemStack);
			}
				break;
			case 1: pushItem(&myInventoryItemStack);
				break;
			case 2: popItem(&myInventoryItemStack);
				break;
			default: cout << "please enter a number from the menu " << exit << " is not valid...";
		}
	}

	cout << "Enter 0 to exit..." << endl;
	cin >> exit;
}

void popItem(StackClassTemplate<InventoryItem>* stack)
{

	stack->pop(stack->getTopValue());
}

void pushItem(StackClassTemplate<InventoryItem>* stack)
{
	InventoryItem tempItem;
	int tempInt;
	string tempString;
	cout << "enter serialNum: ";
	cin >> tempInt;
	tempItem.setSerialNum(tempInt);
	cout << "enter manufactDate: ";
	cin >> tempString;
	tempItem.setManufactDate(tempString);
	cout << "enter lotNum: ";
	cin >> tempInt;
	tempItem.setLotNum(tempInt);
	stack->push(tempItem);
}

int menu()
{
	int choice;
	cout << endl << "(1) enter new item..." << endl
		<< "(2) remove an item..." << endl
		<< "(0) to exit menu..." << endl
		<< "selection: ";
	cin >> choice;
	return choice;
}
