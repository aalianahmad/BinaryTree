#pragma once
#include"btNode.h"
class bt
{
	btNode* root;
	void deleteDeepest(btNode*, btNode*);
	void inOrderTraversal(btNode*);
public:
	bt();
	void insert(int);
	void deletion(int key);
	void inOrder();
};
