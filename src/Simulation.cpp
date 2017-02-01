//#include "stdafx.h"
#include "Simulation.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "FileInput.h"
#include "Process.h"
#include <iostream>
#include <string>

using namespace std;

class ListItem;

PriorityQueue* Simulation::eventList = new PriorityQueue();
PriorityQueue* Simulation::processList = new PriorityQueue();
Queue* Simulation::CPU = new Queue();
Queue* Simulation::IO = new Queue();
Queue* Simulation::cpuQueue = new Queue();
Queue* Simulation::ioQueue = new Queue();

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of Simulation
* prompts user to enter a file name, which will be used for the simulation
*/
Simulation::Simulation() {
	string fileName;
	cout << "Enter file name: ";
	cin >> fileName;
	file = new FileInput(fileName);
}

//////////////////////////////////////////////////////////////////////////////////
/**
* starts the simulation
*/
void Simulation::startSimulation() {
	file->startFile();
	processEventList();
	file->close();
}

//////////////////////////////////////////////////////////////////////////////////
/**
* loops through events list until its empty.
* then prints out summary table.
*/
void Simulation::processEventList() {
	while (!eventList->isEmpty()) {
		ListItem* item = eventList->remove();			// remove first event from event list
		Event* newEvent = dynamic_cast<Event*>(item);	// dynamic cast
		if (newEvent != NULL)							// safety check
			newEvent->processEvent();					// #polymorphism
	}
	cout << endl << "All Processes complete.  Final Summary:";
	printSummary();										// print out summary statistics
}

//////////////////////////////////////////////////////////////////////////////////
/**
* prints out summary statistics
*/
void Simulation::printSummary() {
	cout << endl;
	cout << "Process    Arrival         CPU      I/O       Exit       Wait" << endl;
	cout << "      #       Time        Time     Time       Time       Time" << endl;
	cout << "-------------------------------------------------------------" << endl;

	while (!processList->isEmpty()) {
		processList->remove()->print();
	}
	cout << endl << "End of Processing" << endl;
}

//////////////////////////////////////////////////////////////////////////////////
void Simulation::addEvent(Event * newEvent) {
	eventList->insert(newEvent);
}

void Simulation::addProcess(Process * newProcess)
{
	processList->insert(newProcess);
}

//////////////////////////////////////////////////////////////////////////////////
bool Simulation::cpuIsEmpty() {
	return CPU->isEmpty();
}

void Simulation::addToCPU(StartCPU * executeCPU) {
	CPU->insert(executeCPU);
}

StartCPU * Simulation::removeFromCPU() {
	return dynamic_cast<StartCPU*>(CPU->remove());
}

StartCPU * Simulation::peekCPU() {
	return dynamic_cast<StartCPU*>(CPU->peek());
}

//////////////////////////////////////////////////////////////////////////////////
bool Simulation::cpuQueueIsEmpty() {
	return cpuQueue->isEmpty();
}

void Simulation::addToCpuQueue(StartCPU * waitingCPU){
	cpuQueue->insert(waitingCPU);
}

StartCPU * Simulation::getFirstCPU() {
	return dynamic_cast<StartCPU*>(cpuQueue->remove());
}

//////////////////////////////////////////////////////////////////////////////////
bool Simulation::ioIsEmpty() {
	return IO->isEmpty();
}

void Simulation::addToIO(StartIO * newIO) {
	IO->insert(newIO);
}

StartIO * Simulation::removeFromIO() {
	return dynamic_cast<StartIO*>(IO->remove());
}

StartIO * Simulation::peekIO() {
	return dynamic_cast<StartIO*>(IO->peek());
}

//////////////////////////////////////////////////////////////////////////////////
void Simulation::addToIOQueue(StartIO * waitingIO) {
	ioQueue->insert(waitingIO);
}

bool Simulation::isIoQueueEmpty() {
	return ioQueue->isEmpty();
}

StartIO * Simulation::getFirstIO() {
	return dynamic_cast<StartIO*>(ioQueue->remove());
}
//////////////////////////////////////////////////////////////////////////////////
Simulation::~Simulation() {
}
