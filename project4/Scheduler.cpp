#include "Scheduler.h"

Scheduler::Scheduler(int p)
{
	freePool = p;
	totalPool= p;
	idCounter= 0;
}

Scheduler::~Scheduler(void)
{
}


void Scheduler::Tick(void)
{
	list<int> jobSubmitted;
	list<int> jobFinished;
	int ReleasedProc=0;

	string job_des;
	int	   n_procs;
	int	   n_ticks;

	while (job_des!= "null")
	{
		cout << "Please enter job_des(string) n_procs(int) n_ticks(int) : \n";
		cout<<"\tnull -1 -1 , if no new jobs"<<endl;
		cout<<"\texit -1 -1 , if want to exit\n"<<endl;
		
		cin >> job_des>>n_procs>>n_ticks;
		if (job_des=="exit")
		{
			cout<<"exit!"<<endl;
			exit (1);
		}

		else
		{
			if ( n_procs <=totalPool && n_procs >0 && n_ticks> 0  &&job_des!="null" )
			{
				idCounter++;
				InsertJob(idCounter,n_procs,n_ticks,jobSubmitted);
			}
			else
			{
				cout<<"bad job"<<endl;
			}
		}
	}

	DecrementTimer(jobFinished,ReleasedProc);
	RunJob();

	cout<<"\nAfter this Tick:\n";
	
	cout<<"valid job_ids submitted during this tick: \n";
	list<int>::iterator it;
	for ( it=jobSubmitted.begin(); it != jobSubmitted.end(); it++ )
		cout<<*it<<"\t";
	cout<<endl;
	
	
	
	cout<<"valid job_ids finished during this tick: \n";
	
	for ( it=jobFinished.begin(); it != jobFinished.end(); it++ )
		cout<<*it<<"\t";
	cout<<endl;
	
	
	cout<<"number of processors releasd during this tick: "<<ReleasedProc<<endl;
	
	printAll();
	
}

	 
void Scheduler::InsertJob(int id,int n_procs,int n_ticks,  list<int> & jobSubmitted )
{
   waitingQueue.push (make_pair (n_ticks, Job (id, n_procs,n_ticks )  ) );
   waitingJobs.push_front( id );
   jobSubmitted.push_back(id);
}

void Scheduler::DecrementTimer(list<int> & jobFinished,int & ReleasedProc)
{
	if(!runningQueue.empty())
	{
		list<pair<int,Job> >::iterator it;
		for ( it=runningQueue.begin(); it != runningQueue.end(); it++ )
		{
			it->first--;
			if(it->first<=0)
			{
				freePool+= it->second.n_procs;
				ReleasedProc+= it->second.n_procs;
				jobFinished.push_back(it->second.job_id);
				it=runningQueue.erase(it);
			}
		 }
	}
}


void Scheduler::RunJob(void)
{
	if (waitingQueue.top().second.n_procs<= freePool)
	{
		waitingJobs.remove(waitingQueue.top().second.job_id);
		freePool-=waitingQueue.top().second.n_procs;
		runningQueue.push_back(waitingQueue.top());
		waitingQueue.pop();
		
	}
}


void Scheduler::printAll(void)
{
	//print:
	//list <int> waitingJobs;

	cout<<"contain of waitQuene(id) :\n ";
	list <int>::iterator it;
	for ( it=waitingJobs.begin(); it != waitingJobs.end(); it++ )
		cout<<*it<<"\t";
	cout<<endl;
	

//	list < pair<int, Job> >	runningQueue;
	
	cout<<"contains of RunningQueue(id, time remaining, n_procs:\n";
	list<pair<int,Job> >::iterator i;
	for ( i=runningQueue.begin(); i != runningQueue.end(); i++ )
		cout<<i->second.job_id<<"\t"<<i->first<<"\t"<<i->second.n_procs<<endl;
			
	cout<<endl;
	
	cout<<"number of free processor in the freePool:  ";
	cout<<freePool<<endl<<endl;
}