#include "Node.h"
#include "BSTree.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
/*	Node *root = new Node(1);
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
*/
	BSTree *t = new BSTree();

	t->rinsert(1);
	t->rinsert(10);
	t->rinsert(5);
	t->rinsert(-3);
	cout << "Try: " << t->get_debug_string() << endl;
/*	Node *root = t->getRoot();
	cout << root->getData() << endl;
	t->insert(5);
	//cout << root->getLeft() << endl;
	t->insert(-5);
	cout << root->getLeft()->getData() << endl;
	t->insert(-3);
	cout << root->getLeft()->getRight()->getData() << endl;
	t->insert(3);
	cout << root->getRight()->getLeft()->getData() << endl;
	t->insert(2);
	cout << root->getRight()->getLeft()->getLeft()->getData() << endl;
*/	return 0;
}
