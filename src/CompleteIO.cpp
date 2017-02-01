//#include "stdafx.h"
#include "CompleteIO.h"
#include "Simulation.h"
#include "StartCPU.h"
#include "Exit.h"
#include <iomanip>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of CompleteIO, uses parent's constructor
*
* @param  someTime (time that event happens at), sameProcess, nextBurst
*/
CompleteIO::CompleteIO(int someTime, Process * sameProcess) 
	: Event(someTime, sameProcess) {}

//////////////////////////////////////////////////////////////////////////////////
/**
* Checks if there are processes on the io queue and if its process has a cpu burst
* next
*/
void CompleteIO::processEvent() {
	print();
	int time = getTime();

	Simulation::removeFromIO();			// remove itself from IO

	if (!process->isEmpty()) {			// check if there are more bursts, CPU burst next
		StartCPU* newCPU = new StartCPU(time, process, nextProcess());	// make a StartCPU Event
		if (Simulation::cpuIsEmpty()) {									// CPU is empty
			Simulation::addToCPU(newCPU);
			Simulation::addEvent(newCPU); 
		}
		else { 
			// know wait time should be incremented here somehow
			Simulation::addToCpuQueue(newCPU);
		}
	}

	else { // if there are no more processes make an Exit eventcess is finished. Thus, create Exit event 
		Exit* newExit = new Exit(time, process);		// make Exit Event
		Simulation::addEvent(newExit);					// add it to events list

		if (!Simulation::isIoQueueEmpty()) {	// if there are more IO processes waiting to excute
												// schedule the first one on the queue to start execution
			StartIO* nextUp = Simulation::getFirstIO(); // get it from queue
			nextUp->setTime(time);
			Simulation::addToIO(nextUp);				// add it to IO
			Simulation::addEvent(nextUp);				// add it to events list
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
/**
* calls parent print method, and adds to it
*/
void CompleteIO::print() {
	Event::print();
	cout << "completes IO burst" << endl;
}

CompleteIO::~CompleteIO() {
}
