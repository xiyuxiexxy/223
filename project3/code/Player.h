#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <exception>
#include <string> 
#include <sstream>

using namespace std;
#pragma once

class Player
{
public:
	Player(int id, int x, int y);

	
	~Player(void);

	void initial(int id,int x, int y);


	string toString(int x, int y);
	const int getID()
	{return ID; };
	
	const int getX()
	{return X;};
	const int getY()
	{return Y;};
	const string getLocation()
	{return location;};
	
private:
	int ID;
	int X;
	int Y;
	string location;
};
#endif