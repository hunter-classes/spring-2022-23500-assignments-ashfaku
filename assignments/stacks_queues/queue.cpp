#include <iostream>
#include "queue.h"

//     node1-->node2-->node3-->null
// head--^                ^-----------tail

Queue::Queue()
{
	head = 0;
	tail = 0;
}

std::string Queue::get_debug_string()
{
	std::string result = "";
	for (int i = 0; i < 7; i++)
	{
		result += std::to_string(arr[i]) + " ";
	}
	return result;
}

void Queue::enqueue(int data)
{
	tail %= 7;
	arr[tail] = data;
	tail++;
}

int Queue::dequeue()
{
	if (head == tail)
	{
		throw QUEUE_ERR_EMPTY;
	}
	int r = arr[head];
	for (int i = head; i < 7 - 1 - 1; i++)
	{
		arr[i] = arr[i+1];
	}
	// if we just emptied the queue, fix where tail points to
	return arr[head++];
}

int Queue::front()
{
	if (head == tail)
	{
		throw QUEUE_ERR_EMPTY;
	}

	return head->getData();

}
