#include "Queue.h"
// constructor
Queue::Queue() :front(nullptr), rear(nullptr), numOfItems(0) {}
// front element 
btNode* Queue::frontElement() { return this->front->data; }
// insertion in queue 
void Queue::enqueue(btNode* data)
{
	qNode* newNode = new qNode(data);
	if (isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	numOfItems++;
}
void Queue::dequeue()
{
	if (isEmpty())
	{
		cout << "queue is Empty ";
	}
	else
	{
		qNode* temp = this->front;
		front = front->next;
		delete temp;
		numOfItems--;
	}
}

bool Queue::isEmpty()
{
	if (numOfItems > 0) return false;
	return true;
}
