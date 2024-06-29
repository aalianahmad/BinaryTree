#include"bt.h"
#include<iostream>
using namespace std;
int main()
{
	bt tree;
	for (int i = 1; i <= 7; i++)
	{
		tree.insert(i);
	}
	tree.inOrder();
	tree.deletion(6);
	tree.inOrder();
	tree.deletion(7);
	tree.inOrder();
	tree.deletion(2);
	tree.inOrder();

	return 0;
}
