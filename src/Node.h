/*
* Node.h
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/

#ifndef NODE_H
#define NODE_H

//#include "ListItem.h"
//Node doesn't need to include listitem, since it not using its
//methods or defining any instances; it just needs to recognize
//the node symbol so it can take a pointer-to-listitem as an
//argument to its methods.  use a forward reference!
using namespace std;
class ListItem; //forward reference to listitem...

class Node {
private:
	ListItem *theItem;
	Node* link;
public:
	Node(ListItem *initItem, Node *initLink);
	void print();
	Node* getLink();
	void setLink(Node *newLink);
	ListItem* getData();
};
#endif
