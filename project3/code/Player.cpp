#include "Player.h"

Player::Player(int id, int x, int y)
{
	 if(id <=0|| x<=0 || y<=0)
		throw exception("could not initial play with nonpositive ID, position");
	 else
		initial(id,x,y);
}

Player::~Player(void)
{	
}


void Player::initial(int id, int x,int y)
{
	ID= id;
	X=x;
	Y=y;

	location= toString(x,y);
}

string Player::toString(int x, int y)
{
	stringstream ss;
	ss<<"("<<x<<","<<y<<")";
	return ss.str();
}

