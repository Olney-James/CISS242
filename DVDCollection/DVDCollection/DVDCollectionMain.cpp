/***********************************************************
Program: DVDCollectionMain.cpp (Week 8 Course Project)

Detail: CD/DVD Collection
This program will allow the user to keep track of a CD or DVD collection. 
This can only work exclusively with either CDs or DVDs since some of the 
data is different—your choice. Each CD/DVD in the collection will be 
represented as a class, so you will have one class that is a single CD/DVD.

The CD class will use a vector to keep track of the titles of the songs on 
the CD; this will allow each CD to have a different number of songs. It 
should also maintain the length of each song thus another vector. The class 
will also keep track of the total length of the CD. The class will also
have a data member for the artist name and the name of the CD.

The DVD class will have data members for the title of the movie, the 
length of the movie, and the year the movie was released. The class will 
have a vector which is used to store the name of the actors and actresses 
in the movie. Another vector will be used to maintain the character names 
that the actor/actress played in the movie. These two vectors must work in 
parallel, meaning the first actor/actress in the list must correspond to 
the first character in the other vector.

The program will maintain a list of CD/DVDs. This list will be a vector 
of that class type (CD or DVD). The program must provide methods 
(functions) to add a CD/DVD, remove a CD/DVD and update a CD/DVD. There 
should also be a function that displays the entire list of CDs/DVDs. The 
output must be a table format, with heading.

For the DVDs:

Movie Title
Length of Movie
Year Released
Actors/Actresses
Characters
Note: the movie title, length of movie and year released should only 
appear once while the actors/actresses and characters will have 
several lines. So the other columns must be displayed with blanks.

For the CDs:

Artist
CD Name
Length of CD
Song Title
Song Length
Note: the artist name, CD name and length of CD should only appear once 
while the song title and length will have several lines. So the other 
columns must be displayed with blanks.

Author: James Olney
Created: 02/23/2017
Revisions: N/A
*******************/

#include "DVD.h"
#include <iostream>
#include <iomanip>

void printElement(const string& s, int width)
{
	cout << left << setw(width);
	cout.fill(' ');
	cout << s;
}

void displayDvd(DVD dvd) {
	const int STRINGLENGTH = 20;
	const int NUMLENGTH = 7;
	const int INDEXLENGTH = 2;
	printElement(dvd.getMovieTitle(), STRINGLENGTH);
	printElement(to_string(dvd.getLengthOfMovie()), NUMLENGTH);
	printElement(to_string(dvd.getYearReleased()), NUMLENGTH);
	int x = 1;
	for (Actor aC : dvd.getActors()) {
		printElement(to_string(x), INDEXLENGTH);
		printElement(aC.getActorName(), STRINGLENGTH);
		printElement(aC.getCharacterName(), STRINGLENGTH);
		cout << endl;
		printElement("", INDEXLENGTH);
		printElement("", STRINGLENGTH);
		printElement("", NUMLENGTH);
		printElement("", NUMLENGTH);
		x++;
	}
	cout << endl;
}

void displayList(vector<DVD> &d) {
	const int STRINGLENGTH = 20;
	const int NUMLENGTH = 7;
	const int INDEXLENGTH = 2;
	printElement("#", INDEXLENGTH);
	printElement("Movie Title", STRINGLENGTH);
	printElement("Length", NUMLENGTH);
	printElement("Year", NUMLENGTH);
	printElement("#", INDEXLENGTH);
	printElement("Actors", STRINGLENGTH);
	printElement("Characters", STRINGLENGTH);
	cout<< endl << "----------------------------------------------------------------" << endl;
	int x = 1;
	for (DVD dvd : d) {
		printElement(to_string(x), INDEXLENGTH);
		displayDvd(dvd);
		x++;
	}
}

void updateDvd(vector<DVD> &d) {
	int selection;
	int index;
	int actorIndex;
	string update;
	string update2;
	int updateNumber;
	do {
		cout << "enter DVD#: ";
		cin >> index;
		index--;
		if (index<0 || index>d.size()) {
			cout << "there is no DVD# " << index + 1<<endl;
		}
	} while (index<0 || index>d.size());
	do {
		printElement(to_string(index + 1), 2);
		displayDvd(d[index]);
		cout << "enter 1 to update title" << endl
			<< "enter 2 to update length" << endl
			<< "enter 3 to update year" << endl
			<< "enter 4 to update actors/characters" << endl
			<< "enter 0 to exit current selection" << endl;
		cout << "Selection: ";
		cin >> selection;
		if (selection < 0 || selection > 4) {								//validation
			cout << "there is no selection " << selection << endl;
		}
		if (selection == 1) {												//update title
			cout << "enter title: ";
			cin.ignore();
			getline(cin, update);
			d[index].setMovieTitle(update);
		}
		if (selection == 2) {												//update length
			cout << "enter length(in minutes): ";
			cin >> updateNumber;
			d[index].setLengthOfMovie(updateNumber);
		}
		if (selection == 3) {												//update year
			cout << "enter year: ";
			cin >> updateNumber;
			d[index].setYearReleased(updateNumber);
		}
		if (selection == 4) {												//update actor
			do {
				cout << "enter 1 to update an actor/character" << endl
					<< "enter 2 to add a new actor/character" << endl
					<< "enter 0 to exit current selection" << endl;
				cout << "selection: ";
				cin >> selection;
				if (selection < 0 || selection > 4) {						//validation
					cout << "there is no selection " << selection << endl;
				}
				if (selection == 1) {										//update actor
					printElement(to_string(index + 1), 2);
					displayDvd(d[index]);
					do {
						cout << "enter Actor#: ";
						cin >> actorIndex;
						actorIndex--;
						if (actorIndex <0 || actorIndex>d[index].getActors().size()) {
							cout << "there is no Actor# " << actorIndex + 1<<endl;
						}
					} while (actorIndex <0 || actorIndex>d[index].getActors().size());
					cout << "enter actor name: ";
					cin.ignore();
					getline(cin, update);
					cout << "enter character name: ";
					getline(cin, update2);
					d[index].setActor(actorIndex, update, update2);
				}
				if (selection == 2) {										//add actor
					printElement(to_string(index + 1), 2);
					displayDvd(d[index]);
					cout << "enter actor name: ";
					cin.ignore();
					getline(cin, update);
					cout << "enter character name: ";
					getline(cin, update2);
					d[index].addActorAndCharacter(update, update2);
				}
			} while (selection != 0);
		}
	} while (selection != 0);
}

void removeDvd(vector<DVD> &d) {											//remove dvd
	int index;
	do {
		cout << "enter DVD #: ";
		cin >> index;
		index--;
		if (index<0 || index>d.size()) {
			cout << "there is no DVD # " << index + 1 << endl;
		}
	} while (index<0 || index>d.size());
	d.erase(d.begin() + index);
}

void addDvd(vector<DVD> &d) {												//add dvd
	string title;
	int length;
	int year;
	string actor;
	string character;
	cout << "enter title: ";
	cin.ignore();
	getline(cin, title);
	do {
		cout << "enter length(in minutes): ";
		cin >> length;
		if (length < 0) {
			cout << "length cannot be negative!!!"<<endl;
		}
	} while (length < 0);
	do {
		cout << "enter year released: ";
		cin >> year;
		if (year < 0) {
			cout << "year cannot be negative!!!" << endl;
		}
		if (year > 2017) {
			cout << "year cannot be in the future!!!" << endl;
		}
	} while (year < 0 || year>2017);
	cout << "enter main actor: ";
	cin.ignore();
	getline(cin, actor);
	cout << "enter actor's character name: ";
	getline(cin, character);
	d.push_back(DVD(title,length,year,actor,character));
}

int main() {
	int exit = 4;
	vector<DVD> myDVDs = {
		DVD("RED",111,2010,"Bruce Willis", "Frank Moses"),
		DVD("The A-Team",117,2010,"Liam Neeson","Hannibal"),
		DVD("Rogue One",133,2016,"Felicity Jones","Jyn Erso"),
		DVD("Return of the Jedi", 131, 1983, "Mark Hamill","Luke Skywalker")
	};
	myDVDs[0].addActorAndCharacter("Mary-Louise Parker", "Sarah Ross");
	myDVDs[0].addActorAndCharacter("Karl Urban", "William Cooper");
	myDVDs[0].addActorAndCharacter("Morgan Freeman", "Joe Matheson");
	myDVDs[0].addActorAndCharacter("John Malkovich", "Marvin Boggs");
	myDVDs[1].addActorAndCharacter("Bradley Cooper", "Face");
	myDVDs[1].addActorAndCharacter("Jessica Biel", "Charissa Sosa");
	myDVDs[1].addActorAndCharacter("Quinton Jackson", "B.A. Baracus");
	myDVDs[2].addActorAndCharacter("Diego Luna", "Cassian Andor");
	myDVDs[2].addActorAndCharacter("Alan Tudyk", "K-2SO");
	myDVDs[2].addActorAndCharacter("Donnie Yen", "Chirrut Îmwe");
	myDVDs[3].addActorAndCharacter("Harrison Ford", "Han Solo");
	myDVDs[3].addActorAndCharacter("Carrie Fisher", "Princess Leia");
	myDVDs[3].addActorAndCharacter("Billy Dee Williams", "Lando Calrissian");
	myDVDs[3].addActorAndCharacter("Anthony Daniels", "C-3PO");
	myDVDs[3].addActorAndCharacter("Perter Mayhew", "Chewbacca");

	cout << "DVD Collection Program"<<endl
		<< "----------------------"<<endl;
	displayList(myDVDs);
	do {
		cout << endl << "enter 1 to add a DVD" << endl 
			<< "enter 2 to remove a DVD" << endl 
			<< "enter 3 to update a DVD" << endl 
			<< "enter 4 to display collection" << endl 
			<< "enter 0 to exit program";
		cout << endl << "selection: ";
		cin >> exit;
		if (exit == 1) {														//add dvd				
			addDvd(myDVDs);
			displayList(myDVDs);
		}
		if (exit == 2) {														//remove dvd	
			removeDvd(myDVDs);
			displayList(myDVDs);
		}
		if (exit == 3) {														//update dvd
			updateDvd(myDVDs);
			displayList(myDVDs);
		}
		if (exit == 4) {														//display collection
			displayList(myDVDs);
		}
		if (exit < 0||exit > 4) {												//validation
			cout << "there is no selection " << exit<<endl;
		}
	} while (exit != 0);
}