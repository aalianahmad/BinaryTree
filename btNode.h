#pragma once
class btNode
{
public:
	int data;
	btNode* left;
	btNode* right;
	btNode();
	btNode(int d);
};