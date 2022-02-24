#include <iostream>
#include "List.h"
using std::cout;
using std::endl;
using std::string;

int main()
{
	List l;
	l.insert("first");
	l.insert("second");
	l.insert("third");
	cout << l.toString() << endl;
	l.remove(2);
	cout << l.toString() << endl;
	return 0;
}
