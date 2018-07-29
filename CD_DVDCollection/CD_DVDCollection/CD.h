/***********************************************************
Program: CD.h (Week 8 Course Project)

Detail: this is the header class for CD.h

Author: James Olney
Created: 04/22/2017
Revisions: N/A
*******************/

#ifndef CD_H
#define CD_H
#pragma once
#include "Media.h"
#include "LinkedListTemplateClass.h"
#include <iomanip>

class CD : public Media {
private:
	struct song {
	private:
		string title;
		int length;
	public:
		song();
		song(string t, int l);
		string getTitle();
		int getLength();
		void setTitle(string t);
		void setLength(int l);
		friend ostream & operator<<(ostream &strm, song &obj)
		{
			obj.printElement(obj.getTitle(), 20);
			obj.printElement(to_string(obj.getLength()), 4);
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
	LinkedListTemplateClass<song> listOfTitles;
	string artist;
public:
	CD();
	friend ostream &operator << (ostream &, CD &);
	bool operator==(CD &);
	bool operator!=(CD &);
	LinkedListTemplateClass<song> &getListOfTitles() { return listOfTitles; };
	void addSong(string t, int l);
	string getArtist();
	void setArtist(string a);
	void printElement(const string& s, int width);
};


#endif // !CD_H


