# Discrete-Event-Simulation
Simulated the operation of a multi-programming Operating System with a focus on Object Orientation

========================================================================
    CONSOLE APPLICATION : COMP_2150_A2_Main Project Overview
========================================================================

This file contains a summary of what you will find in each of the files that
make up your COMP_2150_A2_Main application.

COMP_2150_A2_Main.cpp
    This is the main application source file where the main function lies.
    It simply makes a new Simulation event and calls the simulation's 
    startSimulation() function.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

Simulation.cpp class:
    the constructor prompts the user to enter a file name which is used to 
    make a new FileInput object, which will be used throughout the simulation.

    the startSimulation() function:
        calls the FileInput object's startFile() method.

        then the processEventList() is then called, which loops through the 
        events lists until there are no more events left.
 
	Inside this loop it simply removes the first item on the events list,
	downcasts it from a ListItem to an Event (abstract) and then the Event's
	processEvent() function is called (which deals with tasks in code)
	
	Then it prints out a summary of the statistics.

    	it then calls the FileInput object's close().

/////////////////////////////////////////////////////////////////////////////
FileInput.cpp 
     the startFile() method calls:
     	the readProcess() function, which reads the next line of the file, as 
        long as it's not empty. And then calls the makeProcess() function.

	the makeProcess() function makes a Process object that holds its 
	processID and its list of bursts(CPU or I/O). It then passes this 
	Process object to an Arrival event. This arrival event is then added
	onto the events list.

/////////////////////////////////////////////////////////////////////////////
Other notes:

Make sure there are no extra spaces before or after a line in the test file, and also make sure
that there are no empty lines (there can sometimes be one at the end of a file).
Otherwise, the program will not run. 

If running the program simply type in "test.txt" when prompted to insert file name.

/////////////////////////////////////////////////////////////////////////////
