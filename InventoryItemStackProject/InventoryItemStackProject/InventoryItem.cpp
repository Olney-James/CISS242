/*************************************
Program: InventoryItem.cpp (Week 5 Programming Assignment 2)

Author: James Olney
Created: 03/30/2017
Revisions: N/A

InventoryItem.cpp has three private data members, an integer serialNum which holds
the part's serial number, manufactDate which is a string that holds the date the
item was manufactured, then lotNum which is an integer that holds the part's lot 
number. There are getters and setters for each of these private data members to be
used in the main.cpp.

**************************************/
#include "InventoryItem.h"

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display InventoryItem objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const InventoryItem &obj)
{
	strm << "Serial Num: " << obj.serialNum << " Manufacture Date: " << obj.manufactDate << " Lot Num: " << obj.lotNum;
	return strm;
}

InventoryItem::InventoryItem()
{
	serialNum = 0;
	manufactDate = "";
	lotNum = 0;
}

int InventoryItem::getSerialNum()
{
	return serialNum;
}

string InventoryItem::getManufactDate()
{
	return manufactDate;
}

int InventoryItem::getLotNum()
{
	return lotNum;
}

void InventoryItem::setSerialNum(int s)
{
	serialNum = s;
}

void InventoryItem::setManufactDate(string m)
{
	manufactDate = m;
}

void InventoryItem::setLotNum(int l)
{
	lotNum = l;
}

bool InventoryItem::operator!=(const InventoryItem &right)
{
	bool status;
	if (serialNum != right.serialNum || manufactDate != right.manufactDate || lotNum != right.lotNum) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}
