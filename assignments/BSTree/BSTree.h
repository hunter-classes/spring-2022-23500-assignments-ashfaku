#pragma once
#include <iostream>
#include "Node.h"
class BSTree
{
	private:
		Node* root;
		void rinsert(int value, Node **root, bool& check);
	public:
		BSTree();
		void insert(int data);
		int rsearch(int value, Node *root);//, bool& check);
		int rsearch(int value);
		void rinsert(int value);
		std::string get_debug_string();
		Node * getRoot();
		void setup();
};
