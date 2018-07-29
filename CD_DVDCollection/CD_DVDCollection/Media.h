#ifndef MEDIA_H
#define MEDIA_H
#pragma once
/***********************************************************
Program: Media.h (Week 8 Course Project)

Detail: This is the header class for Media.cpp

Author: James Olney
Created: 04/22/2017
Revisions: N/A
*******************/
#include <string>
using namespace std;

class Media {
private:
	string name;
	int length;
public:
	Media();
	Media(string n, int l);
	string getName();
	int getLength();
	void setName(string n);
	void setLength(int l);
};

#endif // !MEDIA_H