#ifndef __BOARD_H__
#define __BOARD_H__

#include <ostream>
#include <fstream>
#include <map>

#include "Player.h"


using namespace std;

#pragma once


class Board
{
public:
	Board(int m = 10);
	~Board(void);

	void initial(int m);
	void clear();
	string toString(int x,  int y);

	////////////////////////////////////////////
	//take:
	//	ID, X, Y
	//check: false if fail
	//  full: N<=M after insertion
	//	range: location within bound
	//	ID unique
	//	location unique
	//
	//then
	//	insert players
	//	insert locations
	//	N++
	////////////////////////////////////////////
	bool Insert(int id, int x, int y);

	/////////////////////////////////////////////////
	//takes: ID;
	//check:
	// if ID exist;
	//then:
	// decrease N;
	// remove from players
	// remove from locations
	/////////////////////////////////////////////////
	bool Remove(int id);

	////////////////////////////////////////////////////
	//takes: ID:
	//check:
	//	ID in players
	///////////////////////////////////////////////////
	bool Find(int id);

	//////////////////////////////////////////////////////\
	//takes:
	//	ID, X2,Y2
	//check if:
	//	id exist: players;
	//  (x2,y2) within bound;
	//	movement legal:
	//		move along row	x1=x2
	//		move along colume y1=y2
	//		move along diagonal (y2-y1)/(x2-x1)= +-1
	//then:
	//	move
	//		if (x2,y2)have player,remove it;
	//		update players
	//		update locations
	/////////////////////////////////////////////////////
	bool MoveTo (int id, int x2, int y2);
	
	/////////////////////////////////////////
	//Print in the order of ID
	/////////////////////////////////////////
	void PrintByID();
	int Size()
	{return N;};

private:
	int M;
	int N;

	map<int, Player> players;
	map<string, int> locations;

};
#endif