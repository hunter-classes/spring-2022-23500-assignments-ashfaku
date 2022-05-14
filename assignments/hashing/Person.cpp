#include <iostream>
#include "Person.h"

int Person::id = 0;

Person::Person(std::string first, std::string last)
{
	this->first = first;
	this->last = last;
	this->idnum = id;
	id++;
}
std::string Person::getName()
{
	return last + ", " + first;
}
int Person::get_id()
{
	return idnum;
}
