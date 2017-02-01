//#include "stdafx.h"
#include "Queue.h"
#include "DoubleEndedList.h"
#include "Node.h"

Queue::Queue() {
	theList = new DoubleEndedList();
}

bool Queue::isEmpty() {
	return (theList->isEmpty());
}

void Queue::insert(ListItem * newItem) {	// inserts to the back of the line
	theList->insertLast(newItem);
}

ListItem* Queue::remove() {					// removes from front of the line
	return theList->removeFirst();
}

ListItem* Queue::peek() {
	return theList->getTop()->getData();
}

void Queue::print() {
	theList->print();
}

Queue::~Queue()
{
}
