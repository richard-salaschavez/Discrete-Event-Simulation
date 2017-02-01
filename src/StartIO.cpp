//#include "stdafx.h"
#include "StartIO.h"
#include "CompleteIO.h"
#include "Simulation.h"
#include <iomanip>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of StartIO, uses parent's constructor
*
* @param  someTime (time that event happens at), sameProcess, nextBurst
*/
StartIO::StartIO(int someTime, Process * sameProcess, int nextBurst) : Event(someTime, sameProcess) {
	burstTime = nextBurst;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* Start's an IO operation and completes it, thus creating a CompleteIO event. 
*
* @param  someTime (time that event happens at), sameProcess, nextBurst
*/
void StartIO::processEvent() {
	print();
	int time = getTime();

	// triggers an I/O operation, which isn't time shared, therefore it will finish
	process->incrementIoTime(burstTime);							// increment process IO time
	CompleteIO* endIO = new CompleteIO(time + burstTime, process);	// create CompleteIO event
	Simulation::addEvent(endIO);									// add it to events list
}

//////////////////////////////////////////////////////////////////////////////////
/**
* getter of burstTime instance
*
* @return  burstTime
*/
int StartIO::getBurstTime()
{
	return burstTime;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* calls parent print method, and adds to it
*/
void StartIO::print() {
	Event::print();
	cout << "begins IO burst (" << burstTime << ")" << endl;
}

StartIO::~StartIO() {
}
