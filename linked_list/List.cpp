#include <iostream>
#include "List.h"

List::List()
{
	head = nullptr;
}
void List::insert(std::string data)
{
	Node* newNode = new Node(data);
	newNode->setNext(head);
	head = newNode;
}
Node* List::locate(int n)
{
	int c = 0;
	Node *walker = head;
	while (walker != nullptr && c++ < n)
	{
		walker = walker->getNext();
	}
	if (c == n)
		return walker;
	return nullptr;
}
void List::remove(int n)
{
	Node* walker = head;
	int c = 1; // removing the head is a bad idea
	while (walker != nullptr)
	{
		if (c == n)
		{
			walker->setNext(walker->getNext()->getNext());
			return;
		}
		walker = walker->getNext();
		c++;
	}
}
std::string List::toString()
{
	Node *walker = head;
	std::string l = "";
	while (walker != nullptr)
	{
		l += walker->getData() + "-->";
		walker = walker->getNext();
	}
	l += "nullptr";
	return l;
}
