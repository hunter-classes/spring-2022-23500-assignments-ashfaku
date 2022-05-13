#pragma once
#include "OList.h"
#include <iostream>
using std::string;
class Dictionary
{
	private:
		OList* arr[10];
	public:
		Dictionary();
		~Dictionary();
		void insert(string first, string last, int id_num);
		Person* retrieve(int id_num);
		string getAllKeys(); // return type?
};
