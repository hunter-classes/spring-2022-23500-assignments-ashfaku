#pragma once
#include "OList.h"
#include <iostream>
using std::string;
class Dictionary
{
	private:
		OList* arr[10];
		int hashIndex(Person* p);
	public:
		Dictionary();
		~Dictionary();
		void insert(string first, string last);
		Person* retrieve(int id_num);
		string getAllKeys();
};
