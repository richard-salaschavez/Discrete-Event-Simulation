/**
* Abstract class.
* Holds a Process object and has a time at which it occurs.
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef EVENT_H
#define EVENT_H
#include "ListItem.h"
#include "Process.h"

using namespace std; 

class Event :
	public ListItem
{
protected: 
	int time;			// time at which event takes place
	Process *process;

public:
	Event(int someTime, Process* newProcess);
	virtual void processEvent() = 0;
	virtual void print();
	bool isGreaterThan(Event *otherEvent);
	bool equals(Event *otherEvent);
	Process* getProcess();
	int getTime();
	void setTime(int newTime);
	int nextProcess();	// give children access to the processes
	virtual ~Event();
};
#endif

