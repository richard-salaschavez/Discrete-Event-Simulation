/*
* GenericList.h
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/

#ifndef GENERICLIST_H
#define GENERICLIST_H
#include "ListItem.h"
//#include "Node.h"
//we do NOT need to include node here - we're not making an instance
//or using any of its methods; we just have a pointer to node so
//C++ must recognize the type at this point...we use a forward
//reference
using namespace std;

class Node;  //forward reference for node so it knows the symbol
class ListItem; 
class GenericList : public ListItem {

protected:
	Node* top;

public:
	GenericList();
	virtual void insert(ListItem *newItem); //insertFirst
	ListItem* removeFirst(); //removeFirst
	void print();
	bool isEmpty();
	Node* getTop();
};
#endif
