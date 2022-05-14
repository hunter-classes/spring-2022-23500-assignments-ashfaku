#pragma once
#include <iostream>
#include "Node.h"
#include "Person.h"
class OList
{
	private:
		Node *head;
	public:
		OList();
		~OList();
		void insert(Person* value);
		std::string toString();
		bool contains(Person* value);
		Person* get(int n);
		void remove(int n);
		void reverse();
};
