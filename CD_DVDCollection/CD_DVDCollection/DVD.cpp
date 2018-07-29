/***********************************************************
Program: DVD.cpp (Week 8 Course Project)

Detail: The DVD class has data members for the year the movie was released. The 
class has a linked list for storage of the name of the actors and actresses in 
the movie. The class also maintains the character names that the actors/actresses
played in the movie. The actors/ actresses and characters information are 
stored in a structure which will be stored in the linked list.  
Author: James Olney
Created: 04/22/2017
Revisions: N/A
*******************/
#include "DVD.h"

DVD::actors::actors()
{
	actorName = "";
	characterName = "";
}

DVD::actors::actors(string a, string c)
{
	actorName = a;
	characterName = c;
}

string DVD::actors::getActorName()
{
	return actorName;
}

string DVD::actors::getCharacterName()
{
	return characterName;
}

void DVD::actors::setActorName(string a)
{
	actorName = a;
}

void DVD::actors::setCharacterName(string c)
{
	characterName = c;
}

DVD::DVD() : Media()
{
	year = 0000;
}

ostream & operator<<(ostream &strm, DVD &obj)
{
	strm << endl;
	obj.printElement("Movie Title", 20);
	obj.printElement("Length", 7);
	obj.printElement("Year", 5);
	obj.printElement("Actors", 20);
	obj.printElement("Characters", 20);
	strm << endl << "--------------------------------------------------------------------------";
	strm << endl;
	obj.printElement(obj.getName(), 20);
	obj.printElement(to_string(obj.getLength()), 7);
	obj.printElement(to_string(obj.getYear()), 5);
	strm << endl;
	obj.getActorList().displayTheContentsOfTheListToTheScreenWithLessSpacing();
	return strm;
}

void DVD::printElement(const string & s, int width)
{
	cout << left << setw(width);
	cout.fill(' ');
	cout << s;
}

void DVD::setYear(int y)
{
	year = y;
}

int DVD::getYear()
{
	return year;
}

void DVD::addActor(string a, string c)
{
	actors newActor(a, c);
	actorList.appendNode(newActor);
}

bool DVD::operator==(DVD &right)
{
	bool status = false;

	if (getName() == right.getName() && getLength() == right.getLength() && getYear() == right.getYear()) {
		status = true;
	}

	return status;
}

bool DVD::operator!=(DVD &right)
{
	bool status = false;

	if (getName() != right.getName() && getLength() != right.getLength() && getYear() != right.getYear()) {
		status = true;
	}
	
	return status;
}
