/**
* Child of abstract class Event.
* Occurs when the process completes a CPU burst
* There will either be more bursts to process or it will have finished its 
* processing. Causing an Exit event to be scheduled.
* Check if there are any processes waiting to execute.
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef COMPLETECPU_H
#define COMPLETECPU_H
#include "Event.h"
class CompleteCPU :
	public Event
{
public:
	CompleteCPU(int someTime, Process* sameProcess);
	void processEvent();
	void print();
	~CompleteCPU();
};
#endif
