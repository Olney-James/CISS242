/***********************************************************
Program: DVD.h (Week 8 Course Project)

This program is the header file for DVD.cpp

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


#ifndef DVD_H
#define DVD_H
#pragma once
#include <string>
#include <vector>
#include "Actor.h"
using namespace std;

class DVD {
private:
	string movieTitle;
	int lengthOfMovie;
	int yearReleased;
	vector<Actor> actors;
public:
	DVD();
	DVD(string mT);
	DVD(string mT, double l, int yR, string a, string c);
	void addActorAndCharacter(string actor, string character);
	void setLengthOfMovie(double length);
	void setYearReleased(int year);
	void setMovieTitle(string title);
	void setActor(int index, string actor, string character);
	Actor getActor(int index);
	vector<Actor> getActors();
	int getLengthOfMovie();
	int getYearReleased();
	string getMovieTitle();
};

#endif