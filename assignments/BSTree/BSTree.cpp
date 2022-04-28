#include "BSTree.h"

BSTree::BSTree()
{
	root = nullptr;
}
void BSTree::insert(int data)
{
}
std::string get_debug_string_helper(Node *root)
{
	if (root == nullptr)
		return "";
	Node *left = root->getLeft();
	Node *right = root->getRight();
	int data = root->getData();
	if (left == nullptr && right == nullptr)
		return std::to_string(data);
	if (left == nullptr)
		return std::to_string(data) + get_debug_string_helper(right);
	if (right == nullptr)
		return std::to_string(data) + get_debug_string_helper(left);
	return std::to_string(data) + get_debug_string_helper(left) + get_debug_string_helper(right);
}
std::string BSTree::get_debug_string()
{
	return get_debug_string_helper(root);
}
void BSTree::setup()
{
	root = new Node(1);
	Node *l = new Node(2), *r = new Node(3);
	root->setLeft(l);
	root->setRight(r);
	Node *l2 = new Node(4);
	Node *l3 = new Node(5);
	Node *l4 = new Node(6);
	Node *l5 = new Node(7);
	l->setLeft(l2);
	l->setRight(l3);
	r->setLeft(l4);
	r->setRight(l5);
}
