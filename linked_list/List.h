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
		void insert(std::string data);
		Node* locate(int n);
		void remove(int n);
		std::string toString();
};
