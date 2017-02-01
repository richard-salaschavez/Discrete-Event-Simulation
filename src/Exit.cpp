//#include "stdafx.h"
#include "Exit.h"
#include <iostream>
#include "Process.h"
#include "Simulation.h"
#include <iomanip>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
/**
* Constructor of Exit, uses parent's constructor
*
* @param  someTime (time that event happens at), sameProcess
*/
Exit::Exit(int someTime, Process * sameProcess) : Event(someTime, sameProcess) {}

//////////////////////////////////////////////////////////////////////////////////
/**
* Gathers final statistics about the execution of this Process
*/
void Exit::processEvent() {
	process->calcExitTime();			// calculate Exit time, and modifies it in the correct Process object
	Simulation::addProcess(process);	// add modified object to list 
}

//////////////////////////////////////////////////////////////////////////////////
/**
* calls parent print method, and adds to it
*/
void Exit::print() {
	Event::print();
	cout << "complete!" << endl;
}

Exit::~Exit() {
}
