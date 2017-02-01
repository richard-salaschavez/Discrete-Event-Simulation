/**
* Queue will be implemented by containing a DoubleEndedList. 
* Queue will be a child of ListItem, so it can be contained in a list. 
*
* @author Richard Salas Chavez, 7764077
* @version June 18, 2016
*/

#ifndef QUEUE_H
#define QUEUE_H
#include "ListItem.h"

class DoubleEndedList; // forward references

class Queue : ListItem
{
private:
	DoubleEndedList* theList;
public:
	Queue();
	bool isEmpty();
	void insert(ListItem *newItem);
	ListItem* remove();
	ListItem* peek();
	void print();
	~Queue();
};
#endif
