# include "VectorMyJosephus.h"


VectorMyJosephus::VectorMyJosephus(int N,int M)
{
	init( N, M);
}

VectorMyJosephus::~VectorMyJosephus()
{
	clear();
}

void VectorMyJosephus::init(int N,int M)
{
	mSize=N;
	mM=M;

	circ.clear();	
	for (int i=0; i<N; i++)
		circ.push_back(Person(i));
	
	iter=circ.begin();
}

void VectorMyJosephus::clear()
{
	circ.clear();
	mSize=0;
}


int VectorMyJosephus::currentSize() const
{
	return mSize;
}
	
bool VectorMyJosephus::isEmpty() const
{
	return mSize==0;
}

Person VectorMyJosephus::eliminateNext()
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


Person VectorMyJosephus::findWinner()
{
	while(mSize>1)
		eliminateNext();
	return *iter;
}


void VectorMyJosephus::printAll() 
{
	for(vector<Person>::iterator it=circ.begin();it!=circ.end();++it)
		(*it).print();
	cout<<endl;

}

