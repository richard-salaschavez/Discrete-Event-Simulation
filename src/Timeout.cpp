//#include "stdafx.h"
#include "Timeout.h"
#include <iostream>
#include "Simulation.h"
#include "StartCPU.h"
#include <iomanip>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of Timeout, uses parent's constructor
*
* @param  someTime (time that event happens at), sameProcess, nextBurst
*/
Timeout::Timeout(int someTime, Process* sameProcess, int nextBurst) : Event(someTime, sameProcess) {
	burstTime = nextBurst;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* The process will be sent to the back of the queue to wait for its turn when the 
* CPU is available again. Next process up on the cpu queue will be processed.
*/
void Timeout::processEvent() {
	print();
	int time = getTime();	// time of arrival

	StartCPU* currentCPU = Simulation::peekCPU();
	int startTime = currentCPU->getTime();				// when process started
	int finishTime = startTime + 4; // if it was timed out then it must have spent 4 minutes in CPU

	Simulation::removeFromCPU();						// returns StartCPU Event
	StartCPU* timedOut = new StartCPU(getTime(), process, burstTime);
	Simulation::addToCpuQueue(timedOut);				//process goes to the back of the CPU queue to wait for another turn
	
	// check the process queue for any waiting processes
	if (!Simulation::cpuQueueIsEmpty()) {				// if there are more processes
		StartCPU* nextUp = Simulation::getFirstCPU();	// get next CPU process
		Process* nextUpsProcess = nextUp->getProcess();

		int thisArrivalTime = nextUpsProcess->getArrivalTime(); // when that process was placed in the queue
		
		int difference = (thisArrivalTime - startTime);			// difference in time of arrival, how much later did it arrive
		int waitTime = 0;

		if (difference > 0)
			waitTime = (finishTime - thisArrivalTime);			// difference in time of arrival, if the difference is 4 it will not have waited
																// otherwise, it would have waited 
		nextUp->setTime(getTime());
		nextUpsProcess->incrementWaitTime(waitTime);
		Simulation::addToCPU(nextUp);					// add it to the CPU
		Simulation::addEvent(nextUp);					// schedule it to event list
	}

}

//////////////////////////////////////////////////////////////////////////////////
/**
* calls parent print method, and adds to it
*/
void Timeout::print() {
	Event::print();
	cout << "exhausts its time quantum (requires " << burstTime << " units more)" << endl;
}

Timeout::~Timeout() {
}
