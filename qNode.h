#pragma once
#include"btNode.h"
#include<iostream>
using namespace std;
class qNode
{
public:
	btNode* data;
	qNode* next;
	qNode();
	qNode(btNode*);
};
