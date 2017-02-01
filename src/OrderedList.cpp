//#include "stdafx.h"
#include <iostream>
#include "OrderedList.h"
#include "Node.h"
#include "Event.h"
#include "Process.h"
#include <iostream>
#include "GenericList.h"

using namespace std;

OrderedList::OrderedList() : GenericList() { }

//////////////////////////////////////////////////////////////////////////////////
/**
* inserts by calling ListItem's comparison method, by first downscasting
*
* @param  ListItem* key
*/
void OrderedList::insert(ListItem * key)
{
	Event* eventKey = dynamic_cast<Event*>(key);						// downcast ListItem to Event
	Process* processKey = dynamic_cast<Process*>(key);					// downcast ListItem to Process

	if (eventKey != NULL) {
		int thisID = eventKey->getProcess()->getID();					// Id of (this) event
		Node* newNode = new Node(eventKey, NULL);						// make a new Node
		Node* previous = NULL;											// start at top
		Node* current = top;
				
		ListItem* currentItem;
		Event* currentEvent;	// downcast ListItem to IntAtom
		int currentID;		// Id of that event

		while (current != NULL) { // ensures safe downcast
			currentItem = current->getData();
			currentEvent = dynamic_cast<Event*>(currentItem);
			currentID = currentEvent->getProcess()->getID();

			if (eventKey->isGreaterThan(currentEvent)) {
				previous = current;
				current = current->getLink();
			}

			else if (eventKey->equals(currentEvent)) { 
				if (thisID > currentID) {										// measure by process ID
					previous = current;
					current = current->getLink();
				}
				else 
					break;
			}

			else 
				break;
		}
		
		if (previous == NULL)						// at start of list
			top = newNode;
		else										// not at start
			previous->setLink(newNode);
		newNode->setLink(current);					// newNode --> old current 
	}

	else if (processKey != NULL) {
		Node* newNode = new Node(processKey, NULL);						// make a new Node
		Node* previous = NULL;											// start at top
		Node* current = top;

		ListItem* currentItem;
		Process* currentProcess;	// downcast ListItem to IntAtom

		while (current != NULL) { 
			currentItem = current->getData();
			currentProcess = dynamic_cast<Process*>(currentItem);

			if (processKey->isGreaterThan(currentProcess)) {
				previous = current;
				current = current->getLink();
			}
			else
				break;
		}

		if (previous == NULL)						// at start of list
			top = newNode;
		else										// not at start
			previous->setLink(newNode);
		newNode->setLink(current);					// newNode --> old current 
	}
}

OrderedList::~OrderedList() {
}
