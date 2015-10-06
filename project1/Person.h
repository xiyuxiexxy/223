/*
 * Person:
 * This class encapsulates a person within the Josephus circle.
 */

#ifndef __PERSON_H__
#define __PERSON_H__


#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;
 class Person {

	public: 
		// Constructor:
		// It should not be possible to create a person without a valid position
		// ...
	
		Person(int ID)
		{
			if(ID>=0)
				position=ID;
		};


		// Destructor
		// ...
		~Person()
		{
		}
		;
		
		// print the position
		void print()
		{
			cout<<position;
		};


	private:
		int position; // position occupied by the person at any point of the game
						// Note: Because each position occupies a unique position initially, 
						// 		that initial position can also be treated as the identifier						//		or name for that person
};
 
#endif
