#include <iostream>
#include "OList.h"
#include "Node.h"
OList::OList()
{
	head = nullptr;
}
OList::~OList()
{
/*	Node* walker = head;
	Node* hold;
	while (head != nullptr)
	{
		hold = walker->getNext();
		delete walker;
		walker = hold;
	}
*/
}
void OList::insert(int value)
{
	Node *newNode = new Node(value);
	Node *walker = head;
	Node* trailer = nullptr;
	while (walker != nullptr && walker->getData() <= value)
	{
		trailer = walker;
		walker = walker->getNext();
	}
	if (trailer == nullptr)
	{
		newNode->setNext(head);
        	head = newNode;
	}
	else
	{
		trailer->setNext(newNode);
		newNode->setNext(walker);
	}
}
int OList::get(int loc)
{
	int c = 0;
	Node *walker = head;
	while (walker != nullptr && c < loc)
	{
		walker = walker->getNext();
		c++;
	}
	if (c == loc)
		return walker->getData();
	throw std::out_of_range("Input index is not within range of list size");
}
void OList::remove(int n)
{
	Node* walker = head;
	int c = 1; // removing the head is a bad idea
	while (walker != nullptr)
	{
		if (c == n)
		{
			Node* del = walker->getNext();
			walker->setNext(del->getNext());
			delete del;
			return;
		}
		walker = walker->getNext();
		c++;
	}
	throw std::out_of_range("Input index is not within range of list size");
}
bool OList::contains(int value)
{
	Node* walker = head;
	while (walker != nullptr)
	{
		if (walker->getData() > value)
			break;
		if (walker->getData() == value)
			return true;
		walker = walker->getNext();
	}
	return false;
}
std::string OList::toString()
{
	Node *walker = head;
	std::string l = "head-->";
	while (walker != nullptr)
	{
		l += std::to_string(walker->getData()) + "-->";
		walker = walker->getNext();
	}
	l += "nullptr";
	return l;
}
void OList::reverse()
{
	Node* future;
	if (head != nullptr)
		future = head->getNext();
	Node* trailer = nullptr;
	while (head != nullptr && future != nullptr)
	{
		if (head->getNext() == nullptr)
		{
			std::cout << "Done?" << std::endl;
			head->setNext(future);
			break;
		}
		trailer = head;
		head = head->getNext();
		if (head != nullptr)
		{
			future = head->getNext();
			Node* hold;
			if (future != nullptr)
				hold = future->getNext();
			else
				break;
			head->setNext(trailer);
			future->setNext(head);
			head = hold;
		}
		//std::cout << head->getData() << " " << head->getNext()->getData() << " " << head->getNext()->getNext()->getData() << std::endl;
	}
}
