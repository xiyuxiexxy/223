#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__


#include <string>
#include <list>
#include <queue>
#include <iostream>


     
using namespace std;
     
#pragma once

struct Job
{
	int job_id;
	int n_procs;
	int n_ticks;

   Job( int id, int procs, int ticks )
    : job_id ( id ),n_procs ( procs ), n_ticks ( ticks )
    {}
};

bool operator< ( const pair<int, Job>& a,const pair<int, Job>& b )
{
   return a.first < b.first;
};

class Scheduler
{
public:
	Scheduler(int p);
	~Scheduler(void);
	
	void Tick(void);
	void InsertJob(int id,int n_procs,int n_ticks,list<int> & jobSubmitted);
	
	void DecrementTimer(list<int> & jobFinished,int &ReleasedProc);
	void RunJob(void);
	
	// print contain of waitJobs: id
	// RunningQueue:	id, time, n_procs
	// freePool
	void printAll(void);



private:
	
	
	priority_queue<pair<int, Job>, vector <pair<int, Job> >, greater<pair<int, Job> > > waitingQueue;
	list <int> waitingJobs;
	list < pair<int, Job> >	runningQueue;



	int freePool;
	int totalPool;

	int idCounter;

};

#endif

