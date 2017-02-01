/**
* Child of abstract class Event.
* exit event occurs once the Process has completed all its bursts and
* leaves the system. Final statistics are gathered about the execution of 
* this Process
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef EXIT_H
#define EXIT_H
#include "Event.h"
class Exit :
	public Event
{
public:
	Exit(int someTime, Process* sameProcess);
	void processEvent();
	void print();
	~Exit();
};
#endif