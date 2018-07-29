/***********************************************************
Program: CD.cpp (Week 8 Course Project)

Detail: this class is derived from the base class: Media.cpp. The CD class uses
a linked list to keep track of the titles of the songs on the CD; this allows each
CD to have a different number of songs. It also maintains the length of each song,
thus the class uses a structure which will have the song title and its length. 
Each song will be an instance of this structure and will be stored in the linked
list. The class also has a data member for the artist name.

Author: James Olney
Created: 04/22/2017
Revisions: N/A
*******************/
#include "CD.h"

CD::CD() : Media()
{
	artist = "";
}

bool CD::operator==(CD &right)
{
	bool status = false;

	if (getArtist() == right.getArtist() && getName() == right.getName()) {
		status = true;
	}

	return status;
}

bool CD::operator!=(CD &right)
{
	bool status = false;

	if (getArtist() != right.getArtist() && getName() != right.getName()) {
		status = true;
	}

	return status;
}

void CD::addSong(string t, int l)
{
	song newSong(t, l);
	getListOfTitles().appendNode(newSong);
}


ostream & operator<<(ostream &strm, CD &obj)
{
	obj.printElement("Artist", 20);
	obj.printElement("CD Name", 20);
	obj.printElement("CDLength", 4);
	obj.printElement("Song Title", 20);
	obj.printElement("Length", 4);
	strm << endl << "--------------------------------------------------------------------------";
	strm << endl;
	obj.printElement(obj.getArtist(), 20);
	obj.printElement(obj.getName(), 20);
	obj.printElement(to_string(obj.getLength()), 4);
	strm << endl;
	obj.getListOfTitles().displayTheContentsOfTheListToTheScreenWithSpacing();
	return strm;
}

CD::song::song()
{
	title = "";
	length = 0;
}



CD::song::song(string t, int l)
{
	title = t;
	length = l;
}

string CD::song::getTitle()
{
	return title;
}

int CD::song::getLength()
{
	return length;
}

string CD::getArtist()
{
	return artist;
}

void CD::song::setTitle(string t)
{
	title = t;
}

void CD::song::setLength(int l)
{
	length = l;
}

void CD::setArtist(string a)
{
	artist = a;
}

void CD::printElement(const string & s, int width)
{
	cout << left << setw(width);
	cout.fill(' ');
	cout << s ;
}
