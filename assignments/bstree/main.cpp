#include "Node.h"
#include "bstree.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	Node *root = new Node(1);
	cout << root->getData() << endl;
	Node *left = new Node(2);
	Node *right = new Node(3);
	root->setLeft(left);
	root->setRight(right);
	cout << root->getLeft()->getData() << endl;
	cout << root->getRight()->getData() << endl;
	Node *left2 = new Node(4), *right2 = new Node(5), *left3 = new Node(6), *right3 = new Node(7);
	left->setLeft(left2);
	left->setRight(right2);
	right->setLeft(left3);
	right->setRight(right3);
	cout << left->getLeft()->getData() << " " << left->getRight()->getData() << " " << right->getLeft()->getData() << " " <<
	right->getRight()->getData() << endl;
	
	BsTree *t = new BsTree();
	t->setup();
	cout << t->get_debug_string() << endl;

	return 0;
}