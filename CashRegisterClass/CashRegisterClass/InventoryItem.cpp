/***********************************************************
Program: InventoryItem.cpp (Week 7 Programming Assignment 2)

This program is the item class for CashRegister to access the Description, units, and unit 
price. There are the usual getters and setters, and also a function added to subtract
the purchased quantity from the units on hand.

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
#include "InventoryItem.h"

// Private member function.
void InventoryItem::createDescription(int size, char *value)
{
	// Allocate the default amount of memory for description.
	description = new char[DEFAULT_SIZE];
	// Store a value in the memory.
	strcpy_s(description, strlen(value) + 1, value);
}

// Constructor #1
InventoryItem::InventoryItem()
{
	// Store an empty string in the description
	// attribute.
	createDescription(DEFAULT_SIZE, "");

	// Initialize cost and units.
	cost = 0.0;
	units = 0;
}

// Constructor #2
InventoryItem::InventoryItem(char *desc)
{
	// Allocate memory and store the description.
	createDescription(strlen(desc), desc);

	// Initialize cost and units.
	cost = 0.0;
	units = 0;
}

// Constructor #3
InventoryItem::InventoryItem(char *desc, double c, int u)
{
	// Allocate memory and store the description.
	createDescription(strlen(desc), desc);

	// Assign values to cost and units.
	cost = c;
	units = u;
}

// Destructor
InventoryItem::~InventoryItem()
{
	delete[] description;
}

// Mutator functions
void InventoryItem::setDescription(char *d)
{
	strcpy(description, d);
}

void InventoryItem::setCost(double c)
{
	cost = c;
}

void InventoryItem::setUnits(int u)
{
	units = u;
}

void InventoryItem::subtractPurchasedFromOnHand(int purchased)
{
	units -= purchased;
}

// Accessor functions
const char *InventoryItem::getDescription() const
{
	return description;
}

double InventoryItem::getCost() const
{
	return cost;
}

int InventoryItem::getUnits() const
{
	return units;
}