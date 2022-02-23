#pragma once
#include <iostream>
#include "Node.h"
class List
{
	private:
		Node *head;
	public:
		List();
		~List();
		Node* locate(int n);
		void remove(int n);
		std::string toString();
};
