/**
* PriorityQueue will be implemented by containing an OrderedList. 
* PriorityQueue will be a child of ListItem, so it can be contained in a list.
*
* @author Richard Salas Chavez, 7764077
* @version June 18, 2016
*/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "ListItem.h"

class OrderedList; // forward references

class PriorityQueue : ListItem
{
private:
	OrderedList* theList;
public:
	PriorityQueue();
	bool isEmpty();
	void insert(ListItem * newItem);
	ListItem* remove();
	void print();
	~PriorityQueue();
};
#endif
