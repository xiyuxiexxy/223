/*
 * VectorMyJosephus:
 * This class implements a MyJosephus circle using an STL Vector
 * N : initial number of players
 * M : interval to jump for next removal
 */

#ifndef __VECTORMyJosephus_H__
#define __VECTORMyJosephus_H__

#include <iostream>
#include <vector>
#include "Person.h"

using namespace std;

class VectorMyJosephus {

public:
	// Constructors:
	// 		Provide a default empty circle constructor 
	VectorMyJosephus();

	//		- a constructor that initializes the circle with N people who 
	//				will play this game
	//		- position values should be system assigned in the order of insertion
	//			for example, if N=5, then the people in the circle should be
	//						assigned positions: 0,1,2,3,4.
	VectorMyJosephus(int N,int M);


	// Destructor:
	~VectorMyJosephus();

	// Public methods:

	//		this does the same thing as the argument constructor above
	void init(int N,int M);

	//	makes the circle empty
	void clear();

	//	prints the number of people in the circle
	int currentSize()const;

	//	returns true if circle is empty
	bool isEmpty()const;

	// eliminates the next person as per the game's rule
	Person eliminateNext();

	// prints the current content of circle in sequence starting from the person with the least position number
	void printAll();
	Person findWinner();

	// any other member functions of your choice
	// ....

private:
	vector<Person> circ; // or simply vector<int> if you are keeping track of the people IDs (which is an INT)
	vector<Person>::iterator iter;
	int mSize;	// dynamic size of circle; initially size=N and then it will keep decreasing with each elimination
	int mM;		// interval size; i.e., number of positions to skip before next elimination

	// any other variables of your choice
	// ....
};



#endif
