//#include "stdafx.h"
#include "Event.h"
#include "Process.h"
#include "IntAtom.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Queue;

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of Event

* @param  someTime (time that event happens at), newProcess
*/
Event::Event(int someTime, Process *newProcess) {
	time = someTime;
	process = newProcess;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* gets the next burst in the process
*
* @return  int (burst time)
*/
int Event::nextProcess() {
	return process->nextProcess();
}

//////////////////////////////////////////////////////////////////////////////////
/**
* prints time event occurs at and its process ID
*/
void Event::print()
{
	cout << "Time" << setw(5) << time << ": ";
	getProcess()->printID();
}

//////////////////////////////////////////////////////////////////////////////////
/**
* @return true if (this) object occurs later than the otherEvent 
*/
bool Event::isGreaterThan(Event *otherEvent) {
	return (time) > (otherEvent->getTime());
}

//////////////////////////////////////////////////////////////////////////////////
/**
* @return  true if (this) object occurs at the same time as the otherEvent 
*/
bool Event::equals(Event *otherEvent) {
	return time == (otherEvent->getTime());
}

//////////////////////////////////////////////////////////////////////////////////
/**
* getter of process instance
*
* @return  process
*/
Process* Event::getProcess() {
	return process;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* getter of time instance
*
* @return  time
*/
int Event::getTime() {
	return time;
}

//////////////////////////////////////////////////////////////////////////////////
/**
* setter of time instance
*
* @param  newTime
*/
void Event::setTime(int newTime) {
	time = newTime;
}

Event::~Event() {
}
