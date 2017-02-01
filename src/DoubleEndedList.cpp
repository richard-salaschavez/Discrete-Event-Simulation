/*
* DoubleEndedList.cpp
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/
//#include "stdafx.h"
#include <iostream> // for definition of NULL
#include "DoubleEndedList.h"
#include "Node.h"
//we DO NOT need to #include ListItem.h here because we're not
//using any of its methods or defining any instance.
//we DO need to include Node because we're using one of
//its methods (top's print!) and we are creating a new node

using namespace std;
class ListItem;

DoubleEndedList::DoubleEndedList() : GenericList(), bottom(NULL) { } // how to do this a better way?

void DoubleEndedList::insert(ListItem *newItem) {
	GenericList::insert(newItem); // call parent/base class function that has the same signature
	if (isEmpty())
		bottom = top;
}

void DoubleEndedList::insertLast(ListItem *newItem) {
	Node* newNode = new Node(newItem, NULL);
	if (isEmpty()) {
		top = newNode;
		bottom = top;
	}
	else
		bottom->setLink(newNode);
	bottom = newNode;
}
