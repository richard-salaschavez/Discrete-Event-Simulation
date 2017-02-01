/*
* IntAtom.cpp
* COMP 2150 Object Orientation
* (C) Computer Science, University of Manitoba
*/
//#include "stdafx.h"
#include <iostream>
#include "IntAtom.h"
using namespace std;

IntAtom::IntAtom(int i) : data(i) { }
void IntAtom::print() { cout << data << " "; }
int IntAtom::getData() {
	return data;
}

bool IntAtom::isGreaterOrEqualTo(IntAtom *intAtom)
{
	return ( this->data ) >= ( intAtom->getData() );
}

