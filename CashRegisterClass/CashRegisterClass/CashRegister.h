/***********************************************************
Program: CashRegister.h (Week 7 Programming Assignment 2)

This is the header file for CashRegister.cpp.

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
#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#pragma once
//#using "InventoryItem.h"

class CashRegister {
private:
	
	double itemsUnitPrice;
	double purchaseSubtotal;
	double purchaseTotal;
public:
	CashRegister(double i);
	CashRegister();
	double getItemsUnitPrice(double price);
	double getPurchaseSubtotal(int qtyBeingPurchased);
	double getPurchaseTotal();
};

#endif