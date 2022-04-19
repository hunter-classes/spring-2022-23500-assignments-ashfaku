#pragma once
#include <iostream>
#include "Node.h"
class BsTree
{
	private:
		Node* root;
	public:
		BsTree();
		void insert(int data);
		std::string get_debug_string();
		void setup();
};
