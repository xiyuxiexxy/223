#include "ListMyJosephus.h"

ListMyJosephus::ListMyJosephus(int N,int M)
{
	init( N, M);
}

ListMyJosephus::~ListMyJosephus()
{
	clear();
}

void ListMyJosephus::init(int N,int M)
{
	mSize=N;
	mM=M;

	circ.clear();
	for (int i=0; i<N; i++)
		circ.push_back(Person(i));
	iter=circ.begin();
}

void ListMyJosephus::clear()
{
	circ.clear();
	mSize=0;
}


int ListMyJosephus::currentSize() const
{
	return mSize;
}
	
bool ListMyJosephus::isEmpty() const
{
	return mSize==0;
}

Person ListMyJosephus::eliminateNext()
{
	
	for(int i=0;i<mM;i++)
	{
		iter++;	
		if (iter==circ.end())
			iter=circ.begin();
	}

	Person tmp=(*iter);
		
	iter=circ.erase(iter);
	if (iter==circ.end())	
		iter=circ.begin();
	
	mSize--;
	return tmp;

}

Person ListMyJosephus::findWinner()
{
	/*int i=0;
	list<Person> elist;*/

	while(mSize>1)
	{
	//	elist.push_back(
		eliminateNext();
	//	i++;
	//	cout<< "After elimation round "<<i<<", the remaining players are: ";
	//	printAll();
	}

	//cout<<"Players elimated in sequence are: ";

	//for(list<Person>::iterator it=elist.begin();it!=elist.end();++it)
	//	(*it).print();
	//cout<<endl;

	/*cout<<"The winner is: ";
	(*iter).print();
	cout<<endl;*/

	return *iter;
}


void ListMyJosephus::printAll() 
{
	for(list<Person>::iterator it=circ.begin();it!=circ.end();++it)
		(*it).print();
	cout<<endl;
}