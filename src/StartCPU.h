/**
* Child of abstract class Event.
* Schedules process to execute on CPU for a mximum of 4 time units.
* If the maximum is exceeded a Timeout event will be created, if not
* a CompleteCPU event will be created
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef STARTCPU_H
#define STARTCPU_H
#include "Event.h"

class Process;

class StartCPU :
	public Event
{
private:
	int burstTime;

public:
	StartCPU(int someTime, Process* sameProcess, int nextBurst);
	void processEvent();
	void print();
	int getBurstTime();
	~StartCPU();
};
#endif
