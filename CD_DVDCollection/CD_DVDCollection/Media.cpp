/***********************************************************
Program: Media.cpp (Week 8 Course Project)

Detail: This is the base class that maintains the common information between a CS
and a DVD.

Author: James Olney
Created: 04/22/2017
Revisions: N/A
*******************/

#include "Media.h"
Media::Media()
{
	name = "";
	length = 0;
}

Media::Media(string n, int l)
{
	name = n;
	length = l;
}

string Media::getName()
{
	return name;
}

int Media::getLength()
{
	return length;
}

void Media::setName(string n)
{
	name = n;
}

void Media::setLength(int l)
{
	length = l;
}
