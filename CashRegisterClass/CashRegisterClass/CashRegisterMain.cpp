/***********************************************************
Program: CashRegisterMain.cpp (Week 7 Programming Assignment 2)

This program is the main class, using InventoryItem and CashRegister. It will create
a list of items, print that list, have the user select an item to purchase, get the number
of units to be purchased from the user, subtract the items purchased from units on hand, 
create a cashregister object to calculate subtotal, tax, and total(printing each to the user,
and finally loop the program if the user indicates that they want to purchase another item.

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
#include "CashRegister.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void printElement(const string& s)
{
	cout << left << setw(22);
	cout.fill(' ');
	cout << s;
}

void printHeader() {
	printElement("#");
	printElement("Item");
	printElement("qty on Hand");
	cout << endl << "--------------------------------------------------------------------------------";
}

int main() {
	char yOrN = 'y';
	int exit;
	int itemBeingPurchased;
	int numOfUnits;

#pragma region Create list of items
//create list of items
	const int arrayLength = 3;
	InventoryItem items[arrayLength]{
		InventoryItem(),InventoryItem(),InventoryItem("Socket Wrench", 9.1,7)
	};
	items[0].setDescription("Wrench");
	items[0].setUnits(24);
	items[0].setCost(2.2);
	items[1].setDescription("Screwdriver");
	items[1].setUnits(10);
	items[1].setCost(1.75);
	//items[2].setDescription("Wrench");
	//items[2].setUnits(7);
	//items[2].setCost(9.1);
#pragma endregion
	do {
		printHeader();
#pragma region print list of items
		for (int x = 0; x < arrayLength; x++) {
			printElement(to_string(x + 1));
			printElement(items[x].getDescription());
			printElement(to_string(items[x].getUnits()));
			cout << endl;
		}
#pragma endregion

#pragma region get item from user
		do {
			cout << "Which item above is being purchased? ";
			cin >> itemBeingPurchased;
			if (itemBeingPurchased <= 0 || itemBeingPurchased > arrayLength) {
				cout << "there is no item " << itemBeingPurchased << "!!!" << endl;
			}
		} while (itemBeingPurchased <= 0 || itemBeingPurchased > arrayLength);

#pragma endregion

#pragma region get number of units to be purchased from user
		do {
			cout << "How many units? ";
			cin >> numOfUnits;
			if (numOfUnits > items[itemBeingPurchased - 1].getUnits()) {
				cout << "cannot buy more units than what is in stock!!!" << endl;
			}
			if (numOfUnits < 0) {
				cout << "number of units cannot be negative!!!" << endl;
			}
		} while (numOfUnits > items[itemBeingPurchased - 1].getUnits() || numOfUnits < 0);
#pragma endregion

#pragma region subtract items purchased from units on hand
		items[itemBeingPurchased - 1].subtractPurchasedFromOnHand(numOfUnits);
#pragma endregion

#pragma region create cashregister object and calculate subtotal, tax, and total(printing each to the user)
		CashRegister myCashRegister(items[itemBeingPurchased - 1].getCost());
		cout << "Subtotal: $" << setprecision(2) << fixed << myCashRegister.getPurchaseSubtotal(numOfUnits) << endl;
		cout << "Sales Tax: $" << setprecision(2) << fixed << myCashRegister.getPurchaseTotal() - myCashRegister.getPurchaseSubtotal(numOfUnits) << endl;
		cout << "Total: $" << setprecision(2) << fixed << myCashRegister.getPurchaseTotal() << endl;
#pragma endregion

#pragma region ask user if they want to purchase another item
		cout << "Do you want to purchase another item? ";
		cin >> yOrN;
#pragma endregion
	} while (yOrN == 'y');
	
	cout << endl << "enter 0 to exit...";
	cin >> exit;
}