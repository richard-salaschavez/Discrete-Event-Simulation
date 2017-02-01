/*
* Node.cpp
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/

//#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "ListItem.h"
// #include "IntAtom.h"
//Need to include ListItem.h because we call one of its methods
// (theItem's print()!)

using namespace std;

//class IntAtom; 

Node::Node(ListItem *initItem, Node *initLink) : theItem(initItem), link(initLink) {}

void Node::print() {
	theItem->print();
	if (link != NULL) {
		link->print();
	}
}

Node* Node::getLink() {
	return link;
}

void Node::setLink(Node *newLink) {
	link = newLink;
}

ListItem* Node::getData() {
	return theItem;
}

