#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"
#include <iostream>

using std::cout;
using std::endl;

BSTree *tree = new BSTree();

TEST_CASE("Tree insert")
{
	CHECK(tree->getRoot() == nullptr);
	tree->rinsert(1);
	CHECK(tree->getRoot()->getData() == 1);
	tree->rinsert(10);
	CHECK(tree->getRoot()->getRight()->getData() == 10);
	tree->rinsert(2);
	CHECK(tree->getRoot()->getRight()->getLeft()->getData() == 2);
	tree->rinsert(-5);
	CHECK(tree->getRoot()->getLeft()->getData() == -5);
	tree->rinsert(-2);
	CHECK(tree->getRoot()->getLeft()->getRight()->getData() == -2);
	tree->rinsert(-1);
	CHECK(tree->getRoot()->getLeft()->getRight()->getRight()->getData() == -1);
	tree->rinsert(11);
	CHECK(tree->getRoot()->getRight()->getRight()->getData() == 11);
}

