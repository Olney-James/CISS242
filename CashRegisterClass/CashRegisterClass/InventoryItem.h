/***********************************************************
Program: InventoryItem.h (Week 7 Programming Assignment 2)

This is the header file for InventoryItem.cpp.

Detail: The program will ask the user for the item and quantity being purchased. It will then
get the cost of the item from the InventoryItem object. It will add 30% profit to the
cost of the item to get the item’s unit price. It will then multiply the unit price
times the quantity being purchased to get the purchase subtotal. The program will then
compute a 6% sales tax on the subtotal to get the purchase total. It should then display
the purchase subtotal, tax and total on the screen. The program will then subtract the
quantity being purchased from the onHand variable of the Inventory Item class object.
InventoryItem will need to be modified to handle this.

Validation: Do not accept a negative value for the quantity of items being purchased.

Author: James Olney
Created: 02/17/2017
Revisions: N/A
*******************/

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>   // Needed for strlen and strcpy

// Constant for the description's default size
const int DEFAULT_SIZE = 51;

class InventoryItem
{
private:
	char *description;  // The item description
	double cost;        // The item cost
	int units;          // Number of units on hand

						// Private member function.
	void createDescription(int size, char *value);


public:
	// Constructor #1
	InventoryItem();

	// Constructor #2
	InventoryItem(char *desc);

	// Constructor #3
	InventoryItem(char *desc, double c, int u);

	// Destructor
	~InventoryItem();

	// Mutator functions
	void setDescription(char *d);


	void setCost(double c);


	void setUnits(int u);

	void subtractPurchasedFromOnHand(int purchased);


	// Accessor functions
	const char *getDescription() const;


	double getCost() const;

	int getUnits() const;

};

#endif