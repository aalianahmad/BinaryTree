#pragma once
#include"qNode.h"
class Queue
{
	qNode* front;
	qNode* rear;
	int numOfItems;
public:
	Queue();
	btNode* frontElement();
	void enqueue(btNode*);
	void dequeue();
	bool isEmpty();
};
