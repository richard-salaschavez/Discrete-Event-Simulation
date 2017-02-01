//#include "stdafx.h"
#include "Process.h"
#include "Arrival.h"
#include <sstream>
#include <iostream>
#include "Simulation.h"
#include "IntAtom.h"
#include <iomanip>

using namespace std;

class IntAtom;

int Process::process_ID = 1;

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of Arrival, uses parent's constructor
*
* @param  someTime (time that event happens at), sameProcess, file
*/
Process::Process(int time, Queue *list) {
	arrivalTime = time;
	processesList = list;
	myProcessID = process_ID;
	cpuTime = 0;
	ioTime = 0;
	waitTime = 0;
	exitTime = 0;
	process_ID++;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of Process
*
* @return next burst (int)
*/
int Process::nextProcess() {
	ListItem* item = processesList->remove();
	IntAtom* intItem = dynamic_cast<IntAtom*>(item);
	return intItem->getData();
}

//////////////////////////////////////////////////////////////////////////////////
/**
* is processesList empty?
*
* @return  true is processesList is empty
*/
bool Process::isEmpty() {
	return processesList->isEmpty();
}

//////////////////////////////////////////////////////////////////////////////////
/**
* prints process id
*/
void Process::printID() {
	cout << "Process " << myProcessID << " ";
}

//////////////////////////////////////////////////////////////////////////////////
/**
* prints process stats
*/
void Process::print() {
	cout << setw(7) << myProcessID << setw(11) << arrivalTime << setw(12) << cpuTime << setw(9) << ioTime << setw(11) << exitTime << setw(11) << waitTime << endl;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* is (this) process greater the the (otherProcess)?
*
* @param  Process* otherProccess
* @return true if greater
*/
bool Process::isGreaterThan(Process* otherProccess) {
	return (this->getID()) > (otherProccess->getID());
}

//////////////////////////////////////////////////////////////////////////////////
/**
* calculates exit time
*/
void Process::calcExitTime() {
	exitTime = arrivalTime + cpuTime + ioTime + waitTime;
}

//Accesors and Mutators
//////////////////////////////////////////////////////////////////////////////////
int Process::getID() {
	return myProcessID;
}

void Process::incrementCpuTime(int increment) {
	cpuTime = cpuTime + increment;
}

void Process::incrementIoTime(int increment) {
	ioTime = ioTime + increment;
}

void Process::incrementWaitTime(int increment) {
	waitTime = waitTime + increment;
}

int Process::getArrivalTime() {
	return arrivalTime;
}
//////////////////////////////////////////////////////////////////////////////////

Process::~Process() {
}
