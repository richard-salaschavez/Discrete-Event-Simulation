/**
* Runs simulation
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include<iostream>
#include "Queue.h"
#include "IntAtom.h"
#include "Process.h"
#include "Arrival.h"
#include "PriorityQueue.h"
#include "FileInput.h"
#include "StartCPU.h"
#include "StartIO.h"
#include "Event.h"
#include "GenericList.h"

using namespace std;

class ListItem;
class StartIO;
class GenericList;

class Simulation
{
private:
	static PriorityQueue* eventList;
	static PriorityQueue* processList;
	static Queue* CPU;
	static Queue* IO;
	static Queue* cpuQueue;
	static Queue* ioQueue;
	FileInput* file;

public:
	Simulation();

	void startSimulation();
	void processEventList();
	void printSummary();

	//////////////////////////////////////////////////////////////////////////////////
	static void addEvent(Event *newEvent);
	static void addProcess(Process *newProcess);
	//////////////////////////////////////////////////////////////////////////////////
	static bool cpuIsEmpty();
	static void addToCPU(StartCPU* executeCPU);
	static StartCPU* removeFromCPU();
	static StartCPU* peekCPU();
	//////////////////////////////////////////////////////////////////////////////////
	static bool cpuQueueIsEmpty();
	static void addToCpuQueue(StartCPU* waitingCPU);
	static StartCPU* getFirstCPU();
	//////////////////////////////////////////////////////////////////////////////////
	static bool ioIsEmpty();
	static void addToIO(StartIO* newIO);
	static StartIO* removeFromIO();
	static StartIO* peekIO();
	//////////////////////////////////////////////////////////////////////////////////
	static void addToIOQueue(StartIO* waitingIO);
	static bool isIoQueueEmpty();
	static StartIO* getFirstIO();
	//////////////////////////////////////////////////////////////////////////////////
	~Simulation();
};
#endif
