//#include "stdafx.h"
#include "CompleteCPU.h"
#include "Exit.h"
#include "Process.h"
#include "Simulation.h"
#include "StartIO.h"
#include <iomanip>

using namespace std;

class StartCPU;

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of CompleteCPU, uses parent's constructor
*
* @param  someTime (time that event happens at), sameProcess, nextBurst
*/
CompleteCPU::CompleteCPU(int someTime, Process * sameProcess) : Event(someTime, sameProcess) {}

//////////////////////////////////////////////////////////////////////////////////
/**
* Check if the process has finished its processing. 
* Check if there are any processes waiting to execute.
*/
void CompleteCPU::processEvent() {
	print();
	int time = getTime();

	Simulation::removeFromCPU();			// remove itself from CPU

	if (!process->isEmpty()) {							// check if there are more bursts, IO burst next
		int nextBurst = nextProcess();
		
		StartIO* newIO = new StartIO(time, process, nextBurst);		// make a StartIO Event

		if (Simulation::ioIsEmpty()) {					// IO is empty
			
			Simulation::addToIO(newIO);
			Simulation::addEvent(newIO);				// where do we put the newIO Event? to event list!
		}
		else {											// add to IO queue
			// know wait time should be incremented here somehow
			Simulation::addToIOQueue(newIO);
		}		
	}

	else {						// if none, the process is finished. Thus, create Exit event 
		Exit* newExit = new Exit(time, process);		// make Exit Event
		Simulation::addEvent(newExit);					// add it to events list

		if (!Simulation::cpuQueueIsEmpty()) {	// if there are more CPU processes waiting to excute
												// schedule the first one on the queue to start execution
			StartCPU* nextUp = Simulation::getFirstCPU(); // get it from queue
			nextUp->setTime(time);
			Simulation::addToCPU(nextUp);		// add it to CPU
			Simulation::addEvent(nextUp);		// add it to events list
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
/**
* calls parent print method, and adds to it
*/
void CompleteCPU::print() {
	Event::print();
	cout << "completes CPU burst" << endl;
}

CompleteCPU::~CompleteCPU() {
}
