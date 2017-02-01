/**
* Process holds queue of bursts.
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include "ListItem.h"

using namespace std;

class Event;
class Queue;
class IntAtom;

class Process :
	public ListItem
{
private:
	static int process_ID;
	int myProcessID;
	int arrivalTime;
	int cpuTime;
	int ioTime;
	int waitTime;
	int exitTime;
	Queue* processesList;

public:
	Process(int arrivalTime, Queue *list); // arrival occurs when a process is submitted
	int nextProcess();
	bool isEmpty();
	void printID();
	int getID();
	void incrementCpuTime(int increment);
	void incrementIoTime(int increment);
	void incrementWaitTime(int increment);
	void calcExitTime();
	int getArrivalTime();
	void print();
	bool isGreaterThan(Process* otherProccess);
	~Process();
};
#endif

