/*
* GenericList.cpp
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/
//#include "stdafx.h"
#include <iostream> // for definition of NULL
#include "GenericList.h"
#include "Node.h"
//we DO NOT need to #include ListItem.h here because we're not
//using any of its methods or defining any instance.
//we DO need to include Node because we're using one of
//its methods (top's print!) and we are creating a new node

using namespace std;
class ListItem;

GenericList::GenericList() : top(NULL) { }

void GenericList::insert(ListItem *newItem) {
	top = new Node(newItem, top);
}

ListItem* GenericList::removeFirst() {
	Node* temp = top; // point to top of the list
	top = top->getLink();
	return temp->getData();
}

void GenericList::print() {
	cout << "(";
	if (top != NULL)
		top->print();
	cout << ") ";
}

bool GenericList::isEmpty() {
	return (top == NULL);
}

Node* GenericList::getTop() {
	return top;
}
