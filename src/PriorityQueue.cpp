//#include "stdafx.h"
#include "PriorityQueue.h"
#include "OrderedList.h"

PriorityQueue::PriorityQueue() {
	theList = new OrderedList();
}

bool PriorityQueue::isEmpty() {
	return (theList->isEmpty());
}

void PriorityQueue::insert(ListItem * newItem) {
	theList->insert(newItem);
}

ListItem * PriorityQueue::remove() {
	return theList->removeFirst();
}

void PriorityQueue::print() {
	theList->print();
}

PriorityQueue::~PriorityQueue() {
}
