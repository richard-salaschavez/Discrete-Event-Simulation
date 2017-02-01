/**
* Child of abstract class Event.
* Start's an IO operation and completes it since it is not time shared.
* Thus creating a CompleteIO event.
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef STARTIO_H
#define STARTIO_H
#include "Event.h"
class StartIO :
	public Event
{
private:
	int burstTime;

public:
	StartIO(int someTime, Process* sameProcess, int nextBurst);
	void processEvent();
	int getBurstTime();
	void print();
	~StartIO();
};
#endif

