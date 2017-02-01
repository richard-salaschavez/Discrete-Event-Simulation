/**
* OrderedList will be implemented by inheriting a GenericList, and specializing its insert method to insert the item in order.
* The order will be determined by the ListItem's function, isGreaterOrEqualTo
*
* @author Richard Salas Chavez, 7764077
* @version June 19, 2016
*/

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include "GenericList.h"

class OrderedList :
	public GenericList
{
public:
	OrderedList();
	void insert(ListItem *key); // inserts in order, specialization
	~OrderedList();
};
#endif
