/***********************************************************
Program: CashRegister.cpp (Week 7 Programming Assignment 2)

This program is the cash register class for InventoryItem.cpp, and to calculate the unit price,
subtotal, and total to be displayed to the user in CashRegistermain.cpp

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
#include "CashRegister.h"

CashRegister::CashRegister(double i) {
	itemsUnitPrice = i*1.3;
	purchaseSubtotal = 0.0;
	purchaseTotal = 0.0;
}

CashRegister::CashRegister() {
	itemsUnitPrice = 0.0;
	purchaseSubtotal = 0.0;
	purchaseTotal = 0.0;
}

double CashRegister::getItemsUnitPrice(double price)
{
	itemsUnitPrice = price * 1.3;
	return itemsUnitPrice;
}

double CashRegister::getPurchaseSubtotal(int qtyBeingPurchased)
{
	purchaseSubtotal = itemsUnitPrice * qtyBeingPurchased;
	return purchaseSubtotal;
}

double CashRegister::getPurchaseTotal()
{
	purchaseTotal = purchaseSubtotal * 1.06;
	return purchaseTotal;
}
