//#include "stdafx.h"
#include "StartCPU.h"
#include "Event.h"
#include "Process.h"
#include "Timeout.h"
#include "CompleteCPU.h"
#include "Simulation.h"
#include <iostream>
#include <iomanip>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of StartCPU, uses parent's constructor
*
* @param  someTime (time that event happens at), sameProcess, nextBurst
*/
StartCPU::StartCPU(int someTime, Process * sameProcess, int nextBurst) : Event(someTime,sameProcess) {
	burstTime = nextBurst;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* Schedules process to execute on CPU for a mximum of 4 time units.
* If the maximum is exceeded a Timeout event will be created, if not
* a CompleteCPU event will be created
*/
void StartCPU::processEvent() {
	print();
	int time = getTime();
		
	if (burstTime > 4) {				// 4 is the time quantum, should probably be a constant somewhere
		process->incrementCpuTime(4);   // increment process CPU time
		int nextBurst = burstTime - 4;	// change StartCPU event time 
		Timeout* newEvent = new Timeout(getTime() + 4, process, nextBurst); // make a TimeOut event 
		Simulation::addEvent(newEvent);
	}
	
	else {
		process->incrementCpuTime(burstTime);										// increment process CPU time
		CompleteCPU* newEvent = new CompleteCPU(getTime() + burstTime, process);	// make a CompleteCPU event
		Simulation::addEvent(newEvent);
	}
	
}

//////////////////////////////////////////////////////////////////////////////////
/**
* calls parent print method, and adds to it
*/
void StartCPU::print() {
	Event::print();
	cout << "begins CPU burst (" << burstTime << ")" << endl;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* getter of burstTime instance
*
* @return  burstTime
*/
int StartCPU::getBurstTime() {
	return burstTime;
}

StartCPU::~StartCPU() {
}
