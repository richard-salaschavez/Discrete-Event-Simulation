/*
* IntAtom.h
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/

#ifndef INTATOM_H
#define INTATOM_H
#include "ListItem.h"
//we inherit from ListItem, so this MUST be included!

using namespace std;

class IntAtom : public ListItem {
private:
	int data;
public:
	void print();
	IntAtom(int i);
	int getData();
	bool isGreaterOrEqualTo(IntAtom *intAtom);
};
#endif
