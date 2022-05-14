#pragma once
#include <iostream>

class Person
{
	private:
		static int id;
		std::string first; // first name
		std::string last; // last name
		int idnum; // some id number
	public:
		Person(std::string first, std::string last);
		std::string getName();
		int get_id();
};
