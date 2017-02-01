/**
* Child of abstract class Event.
* Occurs when event exhausts its time quantum. 
* The process will be sent to the back of the queue to wait for its turn when the 
* CPU is available again.
* Next process up on the cpu queue will be processed.
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef TIMEOUT_H
#define TIMEOUT_H
#include "Event.h"
class Timeout :
	public Event
{
private:
	int burstTime;

public:
	Timeout(int someTime, Process* sameProcess, int nextBurst);
	void processEvent();
	void print();
	~Timeout();
};
#endif
