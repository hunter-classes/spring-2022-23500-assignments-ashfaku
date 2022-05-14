#include <iostream>
#include "Dictionary.h"
using std::cout;
using std::endl;
using std::string;

int main()
{
	Dictionary* l = new Dictionary();
	l->insert("abc", "pepl");
	return 0;
}
