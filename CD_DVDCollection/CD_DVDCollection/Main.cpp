/***********************************************************
Program: Main.cpp (Week 8 Course Project)

Detail: This is Main.cpp. It maintains 2 lists, one for the CDs and another for
the DVDs. Main.cpp uses linked lists to maintain the two different lists. It uses
methods from CD.h and DVD.h to add a CD/DVD, remove a CD/DVD, and update a CD/DVD.
There is also a function that displays the entire list of CDs/DVDs. The output is 
in table format with heading.

NOTE: the Update Function was not implemented or tested.

Author: James Olney
Created: 04/22/2017
Revisions: N/A
*******************/

#include "Media.h"
#include "CD.h"
#include "DVD.h"
#include "LinkedListTemplateClass.h"

int main() {
	int exit;

	LinkedListTemplateClass<CD> cds;
	LinkedListTemplateClass<DVD> dvds;
	CD cd1;
	cd1.setLength(2);
	cd1.setName("Awesome Mix Vol. 1");
	cd1.setArtist("Guardians");
	cd1.addSong("Hooked on a Feeling", 2);
	cd1.addSong("Go All the Way", 3);
	cd1.addSong("Spirit in the Sky", 4);
	cd1.addSong("Moonage Daydream", 4);
	cd1.addSong("Fooled Around", 4);
	cd1.addSong("I'm not in Love", 6);
	cd1.addSong("I Want You Back", 2);
	cd1.addSong("Come and Get", 3);
	cd1.addSong("Cherry Bomb", 2);
	cd1.addSong("Escape", 4);
	cd1.addSong("O-o-h Child", 3);
	cd1.addSong("Aint No Mountain", 2);
	cds.appendNode(cd1);

	CD cd2;
	cd2.setLength(2);
	cd2.setName("Awesome Mix Vol. 2");
	cd2.setArtist("Guardians");
	cd2.addSong("testsong1", 2);
	cd2.addSong("testsong2", 3);
	cd2.addSong("testsong3", 4);
	cd2.addSong("testsong4", 4);
	cd2.addSong("testsong5", 4);
	cd2.addSong("testsong6", 6);
	cd2.addSong("testsong7", 2);
	cd2.addSong("testsong8", 3);
	cd2.addSong("testsong9", 2);
	cd2.addSong("testsong10", 4);
	cd2.addSong("testsong11", 3);
	cd2.addSong("testsong12", 2);
	cds.appendNode(cd2);
	cout << "adding 2 cds to cd list..." << endl;

	cds.displayTheContentsOfTheListToTheScreen();
	cout << "deleting Awesome Miz Vol. 1..." << endl << endl;
	cds.deleteNode(cd1);
	cds.displayTheContentsOfTheListToTheScreen();

	DVD dvd1;
	dvd1.setName("RED");
	dvd1.setLength(111);
	dvd1.setYear(2010);
	dvd1.addActor("Bruce Willis", "Frank Moses");
	dvd1.addActor("Mary-Louise Parker", "Sarah Ross");
	dvd1.addActor("Karl Urban", "William Cooper");
	dvd1.addActor("Morgan Freeman", "Joe Matheson");
	dvd1.addActor("John Malkovich", "Marvin Boggs");
	
	DVD dvd2;
	dvd2.setName("The A-Team");
	dvd2.setLength(117);
	dvd2.setYear(2010);
	dvd2.addActor("Liam Neeson", "Hannibal");
	dvd2.addActor("Bradley Cooper", "Face");
	dvd2.addActor("Jessica Biel", "Charissa Sosa");
	dvd2.addActor("Quinton Jackson", "B.A. Baracus");

	cout << "adding 2 dvds..." << endl;
	dvds.appendNode(dvd1);
	dvds.appendNode(dvd2);
	dvds.displayTheContentsOfTheListToTheScreen();
	dvds.deleteNode(dvd1);
	cout << "deleting RED dvd..." << endl;
	dvds.displayTheContentsOfTheListToTheScreen();

	cout << "enter 0 to exit...";
	cin >> exit;
}