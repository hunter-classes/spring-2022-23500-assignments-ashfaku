#include "Dictionary.h"
#include "OList.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
Dictionary::Dictionary()
{
	for (int i = 0; i < 10; i++)
		arr[i] = new OList();
}
Dictionary::~Dictionary()
{
//	for (int i = 0; i < 10; i++)
//		delete arr[i];
}
int Dictionary::hashIndex(Person* p)
{
	string name =  p->getName();
	name += std::to_string(p->get_id()); // salt? cuz id is unique? i dunno
	int hash = 0;


	// hash function will go here


	return hash;
}
void Dictionary::insert(string first, string last)
{
	Person p = {first, last};
	int index = hashIndex(&p);
	cout << index << endl;
}
