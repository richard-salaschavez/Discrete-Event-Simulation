/**
* Child of abstract class Event.
* Occurs when an IO burst has finished and leaves the system
* Checks if there are processes on the io queue and if its
* process has a cpu burst next
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef COMPLETEIO_H
#define COMPLETEIO_H
#include "Event.h"
class CompleteIO :
	public Event
{
public:
	CompleteIO(int someTime, Process* sameProcess);
	void processEvent();
	void print();
	~CompleteIO();
};
#endif

