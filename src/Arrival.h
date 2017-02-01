/**
* Child of abstract class Event.
* An arrival should be place in either directly into the CPU or 
* the cpu queue.
* Each arrival causes the next arrival event to be read.
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/
#ifndef ARRIVAL_H
#define ARRIVAL_H
#include "Event.h"

class FileInput;

class Arrival :
	public Event
{
private: 
	FileInput* inputFile;

public:
	Arrival(int someTime, Process* sameProcess, FileInput *file);
	void processEvent();
	void print();
	~Arrival();
};
#endif
