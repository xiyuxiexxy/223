#include "Board.h"

ofstream out("testresult.txt");	
Board::Board(int m)
{
	if (m<=0)
		throw exception("could not initial board with nonpositive number");
	initial(m);
}
void Board::initial(int m)
{
	out<<"creating a board of: "<<m<<"*"<<m<<endl;
	M=m;
	N=0;
}

Board::~Board(void)
{
	clear();
}

void Board::clear()
{
	M=0;
	N=0;
	players.clear();
	locations.clear();
}

bool Board::Insert (int id, int x, int y)
{
	string location=toString(x,y);
	out<<endl<<"try to insert: "<<id<<" @ "<<location<<endl;

	//	N<=M after insertion
	if (N>=M)
	{
		out<<"board full"<<endl;
		return false;
	}

	//	location within bound
	if ( x>M | y>M)
	{	
		out<< "out of board"<<endl;
		return false;
	}

	//	ID unique check
	if (players.find(id)!=players.end())
	{	
		out<<"ID conflict!"<<endl;
		return false;
	}
	
		//	location uniqueness check 
	if (locations.find(location)!=locations.end())
	{	
		out<<"location conflict!"<<endl;
		return false;
	}

	else
	{
	
		Player tmp(id,x,y);
		players.insert( pair<int, Player> (id, tmp));
		out<<"insert: "<<id<<" @ "<<location<<endl<<endl;

		locations.insert(pair<string,int>(location,id));	
		N++;

	//	if(N==M)
	//		out<<"board is full after insertion"<<endl;
		return true;
	}

}
string Board::toString(int x, int y)
{
	stringstream ss;
	ss<<"("<<x<<","<<y<<")";
	return ss.str();
}

bool Board::Remove(int id)
{
	out<<endl<<"Try to remove Player: "<<id<<endl;
	map<int,Player>::iterator it;
	it=players.find(id);
	
	// if ID exist;
	if (it==players.end())
	{	
		out<<"ID does not exist!"<<endl;
		return false;
	}
	else 
	{
		string location=(*it).second.getLocation();
		
		// remove from players
		players.erase(it);
		out<<"move: "<<id<<" from "<<location<<endl;
		// remove from locations	
		locations.erase(location);
		// decrease N;	
		N--;
		
		return true;
	}

}

bool Board::Find( int id)
{
	//out<<endl<<"Try to find Player: "<<id<<endl;
	return players.find(id)!=players.end();
}

bool Board::MoveTo(int id, int x2,int y2)
{
	string location=toString(x2,y2);
	out<<endl<<"try to move player: "<<id<<" to "<<location<<endl;
	map<int,Player>::iterator it;
	it=players.find(id);

	//move or not
	//  (x2,y2) within bound
	if(x2>M | y2>M)
	{	
		out<<"out of board"<<endl;
		return false;
	}

	//	id exist
	if (it==players.end())
	{	
		out<<"ID does not exist, could not move!"<<endl;
		return false;
	}
	// move legal
	else 
	{
		int x1=(*it).second.getX();
		int y1=(*it).second.getY();


		double slope=0;
		if (x1!=x2)
		{
			slope= (double)(y2-y1)/(double)(x2-x1);
			//out<<slope<<"slope"<<endl;
		}

		//	move along row	x1=x2
		//	move along colume y1=y2
		//	move along diagonal (y2-y1)/(x2-x1)= +-1
		if (x1!=x2 && y1!=y2 && slope!=1 && slope!=-1) 
		{	
		
			out<<"illegal movement"<<endl;
			return false;
		}

		else
		{
			//if (x2,y2)have player,remove it;
			map<string,int>::iterator it2;
			it2=locations.find(location);

			if (it2!=locations.end())
			{	
				out<<"remove is need when moving"<<endl;
				int id2=(*it2).second;
				Remove (id2);	//replaces for efficiency;	
			}

			//update players
			//update locations

			Remove(id);
			Insert(id,x2,y2);
			return true;
		}
	}
	
}

void Board::PrintByID()
{
	out<<N<<" players on board: "<<endl;
	for(map<int,Player>::iterator it=players.begin(); it!=players.end();it++)
		out<<(*it).first<<" at "<<(*it).second.getLocation()<<endl;
}
