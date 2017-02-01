//#include "stdafx.h"
#include "FileInput.h"
#include "Queue.h"
#include "IntAtom.h"
#include "Process.h"
#include "Arrival.h"
#include "Simulation.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
/**
* opens file
*
* @param  string fileName 
*/
FileInput::FileInput(string fileName) {
	inFile.open(fileName.c_str());	// convert to c-style string
}

//////////////////////////////////////////////////////////////////////////////////
/**
* starts simulation
*/
void FileInput::startFile() {
	cout << "Simulation begins..." << endl;
	readProcess();
}

//////////////////////////////////////////////////////////////////////////////////
/**
* reads life if it is not the end of file
*/
void FileInput::readProcess() {
	if (!inFile.eof()) {
		string line;
		getline(inFile, line);
		makeProcess(line); // make Process and process it	
	}
}

//////////////////////////////////////////////////////////////////////////////////
/**
* makes a Process object from a line of the file
*
* @param  string line
*/
void FileInput::makeProcess(string line) {
	istringstream iss(line);	// used to scan line
	int arrivalTime;
	iss >> arrivalTime;				// first int is the arrival time

	Queue* processesList = new Queue();

	int num;
	while (iss >> num)			// keeps going until the end of the line
	{
		// the rest of the ints will be CPU and/or IO time
		if (num < 0)
			num = num * -1;		//absolute value
		IntAtom* processInt = new IntAtom(num);
		processesList->insert(processInt);
	}

	Process* newProcess = new Process(arrivalTime, processesList); // make a process
	Arrival* newArrival = new Arrival(arrivalTime, newProcess, this); // make an arrival event that has the process
	Simulation::addEvent(newArrival); // add arrival to events list // should 
}

//////////////////////////////////////////////////////////////////////////////////
/**
* closes file
*/
void FileInput::close() {
	inFile.close();
}

FileInput::~FileInput() {
}
