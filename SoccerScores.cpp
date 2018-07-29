/***********************************************************
Program: SoccerScores.cpp (Week 4 Programming Assignment 2)

This program asks the user to enter the name, number, and points for each member of a 12 man
team. This is entered into an array of 'player' structures that is displayed in a table listing 
each member, and then the total points is calculated and displayed. Then finally, the player 
who scored the most points is also displayed.

Detail: Soccer Scores. Write a program that stores the following data about a soccer player
in a structure: Player’s name, Player’s number, Points scored by Player. The program should 
keep an array of 12 of these structures. Each element is for a different player on a team. The
program should ask the user to enter information for each player. It should then display a 
table that lists each player’s number, name and points scored. The program should also 
calculate and display the total points earned by the team. The program should also determine
which player earned the most points on the team and display that player’s information. 
Validation: Do not accept negative values for player’s number or points scored.

Program must have the following functions
void getPlayerInfo(Player &);
void showInfo(Player);
int getTotalPoints(Player [], int);
void showHighest(Player [], int);

Author: James Olney
Created: 01/16/2017
Revisions: N/A
*******************/


#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

struct Player {
	string name;
	int number;
	int points;
};

void getPlayerInfo(Player &player) {
		cout << "Player name: ";
		getline(cin, player.name);
		do {
			cout << "Player's number: ";
			cin >> player.number;
			if (player.number < 0) {
				cout << "number cannot be negative!!!" << endl;
			}
		} while (player.number < 0);
		do {
			cout << "Points scored: ";
			cin >> player.points;
			if (player.points < 0) {
				cout << "points cannot be negative!!!" << endl;
			}
		} while (player.points < 0);
		cin.ignore(); //To skip the remaining '\n' character
		cout << endl;
}
void showInfo(Player player) {
	cout << player.name << "\t" << "\t" << "\t";
	cout << player.number << "\t" << "\t";
	cout << player.points << endl;
}
int getTotalPoints(Player team[], int teamSize) {
	int total = 0;
	for (int x = 0; x < teamSize; x++) {
		total += team[x].points;
	}
	return total;
}
void showHighest(Player team[], int teamSize) {
	int highest = 0;
	for (int x = 0; x < teamSize; x++) {
		if (team[x].points > team[highest].points) {
			highest = x;
		}
	}
	cout << "The player who scored the most points is: " << team[highest].name;
}

int main()
{
	const int SIZE = 12;
	Player team[SIZE];
	int exit;
	cout << "enter information for each player: " << endl;
	for (int x = 0; x < SIZE; x++) {
		cout << "PLAYER #" << x + 1 << endl << "---------" << endl;
		getPlayerInfo(team[x]);
	}
	cout << "NAME                   NUMBER       POINTS SCORED" << endl;
	for (int x = 0; x < SIZE; x++) {
		showInfo(team[x]);
	}
	cout << "TOTAL POINTS: " << getTotalPoints(team, SIZE) << endl;
	showHighest(team, SIZE);
	cout << endl << "enter 0 to exit: ";
	cin >> exit;
	return 0;
}

