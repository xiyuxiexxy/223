#include "Scheduler.h"
#include "Scheduler.cpp"

int main()
{
	Scheduler S1(10);

	for(int i=1;i<=10;i++)
	{
		cout<<"\n Tick: "<<i<<endl;
		S1.Tick();
	}
	
	return 0;
}