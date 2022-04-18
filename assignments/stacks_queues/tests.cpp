#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack.h"
#include "queue.h"

using std::out_of_range;

Stack *l = new Stack();

TEST_CASE("Stack push(int), pop(), top(), and is_empty() tests")
{
	CHECK_THROWS_AS(l->top(), out_of_range);
	l->push(1);
	CHECK(!l->is_empty());
	CHECK(l->top() == 1);
	l->push(2);
	CHECK(l->top() == 2);
	l->push(-3);

	CHECK(l->top() == -3);
	CHECK(l->pop() == -3);

	CHECK(l->top() == 2);
	CHECK(l->pop() == 2);
	CHECK(!l->is_empty());
	CHECK(l->top() == 1);
	CHECK(l->pop() == 1);

	CHECK_THROWS_AS(l->top(), out_of_range);
	CHECK_THROWS_AS(l->pop(), out_of_range);
	CHECK(l->is_empty());
	delete l;
}
TEST_CASE("Queue tests")
{
}
