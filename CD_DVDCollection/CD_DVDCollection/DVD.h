/***********************************************************
Program: DVD.h (Week 8 Course Project)

Detail: this is the header class for DVD.h

Author: James Olney
Created: 04/22/2017
Revisions: N/A
*******************/

#ifndef DVD_H
#define DVD_H
#pragma once
#include "Media.h"
#include "LinkedListTemplateClass.h"
#include <iomanip>

class DVD : public Media {
private:
	int year;
	struct actors {
	private:
		string actorName;
		string characterName;
	public:
		actors();
		actors(string a, string c);
		string getActorName();
		string getCharacterName();
		void setActorName(string a);
		void setCharacterName(string c);
		friend ostream &operator << (ostream &strm, actors &obj) {
			obj.printElement(obj.getActorName(), 20);
			obj.printElement(obj.getCharacterName(), 20);
			strm << endl;
			return strm;
		}
		void printElement(const string& s, int width)
		{
			cout << left << setw(width);
			cout.fill(' ');
			cout << s;
		}
	};
	LinkedListTemplateClass<actors> actorList;
	
	
public:
	DVD();
	void printElement(const string & s, int width);
	void setYear(int y);
	int getYear();
	void addActor(string a, string c);
	LinkedListTemplateClass<actors> &getActorList() { return actorList; };
	friend ostream &operator << (ostream &, DVD &);
	bool operator==(DVD &);
	bool operator!=(DVD &);
};

#endif // !DVD_H