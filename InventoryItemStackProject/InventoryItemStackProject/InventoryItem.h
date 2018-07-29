/*************************************
Program: InventoryItem.h (Week 5 Programming Assignment 2)

Author: James Olney
Created: 03/30/2017
Revisions: N/A

InventoryItem.h uses the stack class created in Assignment 1. This class has
its implementation in InventoryItem.cpp. 

**************************************/
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <cstring>   // Needed for strlen and strcpy
#include <string>
using namespace std;

// Constant for the description's default size
const int DEFAULT_SIZE = 51;

class InventoryItem
{
private:
	int serialNum;
	string manufactDate;
	int lotNum;
	
public:
	// Constructor #1
	InventoryItem();
	int getSerialNum();
	string getManufactDate();
	int getLotNum();
	void setSerialNum(int s);
	void setManufactDate(string m);
	void setLotNum(int l);
	bool operator!=(const InventoryItem &);
	friend ostream &operator << (ostream &, const InventoryItem &);

};


#endif // !INVENTORYITEM_H
#pragma once
