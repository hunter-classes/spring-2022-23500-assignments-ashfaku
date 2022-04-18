#include <iostream>
#include <unistd.h>
#include "stack.h"
using std::cout;
using std::endl;
int main()
{
	Stack *l = new Stack();
	cout << l->is_empty() << endl;
//	cout << l->top() << endl;
	l->push(3);
	cout << l->pop() << endl;
	cout<< l->is_empty() << endl;
	return 0;
}
