#pragma once

class Node{
	private:
		//This could be any data type
		std::string data;
		//This will be a pointer for the next Node
		Node *next;
	public:
		//Basic constructors
		Node();
		Node(std::string data);
		Node(std::string data, Node* next);

		//Basic accessor method
		std::string getData();
		Node *getNext();

		//Basic setter method
		void setData(std::string data);
		void setNext(Node *next);
};
