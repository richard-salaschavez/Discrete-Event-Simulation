/*
* ListItem.h
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/

#ifndef LISTITEM_H
#define LISTITEM_H
using namespace std;

class ListItem {
public:
	//ListItem is an abstract class!
	//and everybody below better have a print...
	virtual void print() = 0;
	virtual ~ListItem(); //avoids warning that we have no virtual destructor
};
#endif
