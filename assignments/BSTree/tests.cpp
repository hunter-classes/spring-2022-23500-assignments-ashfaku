#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"
#include <iostream>

using std::cout;
using std::endl;

BSTree *tree = new BSTree();

TEST_CASE("Tree rinsert")
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
	tree->rinsert(1);
	CHECK(tree->getRoot()->getData() == 1);
	tree->rinsert(13);
	CHECK(tree->getRoot()->getRight()->getRight()->getRight()->getData() == 13);
	tree->rinsert(12);
	CHECK(tree->getRoot()->getRight()->getRight()->getRight()->getLeft()->getData() == 12);
}
TEST_CASE("Tree rsearch")
{
	CHECK(tree->rsearch(1) == 1);
	CHECK(tree->rsearch(10) == 10);
	CHECK(tree->rsearch(2) == 2);
	CHECK(tree->rsearch(-5) == -5);
	CHECK(tree->rsearch(-2) == -2);
	CHECK(tree->rsearch(-1) == -1);
	CHECK(tree->rsearch(11) == 11);
	CHECK(tree->rsearch(13) == 13);
	CHECK(tree->rsearch(12) == 12);

	CHECK_THROWS_AS(tree->rsearch(15), int);
	CHECK_THROWS_AS(tree->rsearch(-15), int);
	CHECK_THROWS_AS(tree->rsearch(3), int);
}
