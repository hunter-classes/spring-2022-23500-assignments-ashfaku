#pragma once
#include "Person.h"
class Node
{
	private:
		//This could be any data type
		Person* data;
		//This will be a pointer for the next Node
		Node *next;
	public:
		//Basic constructors
		Node();
		Node(Person* data);
		Node(Person* data, Node* next);

		//Basic accessor method
		Person* getData();
		Node *getNext();

		//Basic setter method
		void setData(Person* data);
		void setNext(Node *next);
};
