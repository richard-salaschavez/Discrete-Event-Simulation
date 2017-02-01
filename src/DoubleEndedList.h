/*
* DoubleEndedList.h
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/

#ifndef DOUBLEENDEDLIST_H
#define DOUBLEENDEDLIST_H
#include "GenericList.h"
//#include "ListItem.h"
//#include "Node.h"
//we do NOT need to include node here - we're not making an instance
//or using any of its methods; we just have a pointer to node so
//C++ must recognize the type at this point...we use a forward
//reference
using namespace std;
class ListItem;
class Node;  //forward reference for node so it knows the symbol

class DoubleEndedList :
	public GenericList 
{
private:
	Node *bottom;
public:
	DoubleEndedList();
	void insert(ListItem *newItem); // extending parent's insert function
	void insertLast(ListItem *newItem);
};
#endif
