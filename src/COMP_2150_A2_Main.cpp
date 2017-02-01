//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Simulation.h"

using namespace std;

int main() {
	Simulation* newSimulation = new Simulation();	// make Simulation object
	newSimulation->startSimulation(); 						// call startSimulation method

	return 0;
}
