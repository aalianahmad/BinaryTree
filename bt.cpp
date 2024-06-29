#include "bt.h"
#include "Queue.h"
void bt::deleteDeepest(btNode* root, btNode* nodeToBeDeleted)
{
	Queue* q = new Queue();
	q->enqueue(root);
	btNode* temp = nullptr;
	while (!q->isEmpty())
	{
		temp = q->frontElement();
		q->dequeue();
		if (temp == nodeToBeDeleted)
		{
			temp = nullptr;
			delete(nodeToBeDeleted);
			return;
		}
		if (temp->left)
		{
			if (temp->left == nodeToBeDeleted)
			{
				temp->left = nullptr;
				delete(nodeToBeDeleted);
				return;
			}
			else
			{
				q->enqueue(temp->left);
			}
		}
		if (temp->right)
		{
			if (temp->right == nodeToBeDeleted)
			{
				temp->right = nullptr;
				delete(nodeToBeDeleted);
				return;
			}
			else
			{
				q->enqueue(temp->right);
			}
		}
	}
}
void bt::inOrderTraversal(btNode* n)
{
	if (n == nullptr)
	{
		return;
	}
	inOrderTraversal(n->left);
	cout << n->data << " ";
	inOrderTraversal(n->right);
}
bt::bt() :root(nullptr) {}
// insertion
void bt::insert(int data)
{
	btNode* newNode = new btNode(data);
	if (!this->root)
	{
		root = newNode;
		return;
	}
	Queue* q = new Queue();
	q->enqueue(this->root);
	btNode* temp = nullptr;
	while (!q->isEmpty())
	{
		temp = q->frontElement();
		q->dequeue();
		if (temp->left)
		{
			q->enqueue(temp->left);
		}
		else
		{
			temp->left = newNode;
			return;
		}
		if (temp->right)
		{
			q->enqueue(temp->right);
		}
		else
		{
			temp->right = newNode;
			return;
		}
	}

}

void bt::deletion(int key)
{
	// check if root is present or not
	if (!this->root)
	{
		cout << "tree is empty ";
		return;
	}
	// if root data is equel to key
	if (this->root->left == nullptr && this->root->right == nullptr)
	{
		if (this->root->data == key)
		{
			delete root;
			root = nullptr;
		}
		return;
	}
	Queue* q = new Queue();
	q->enqueue(this->root);
	btNode* temp = new btNode();
	btNode* keyNode = nullptr;
	while (!q->isEmpty())
	{
		temp = q->frontElement();
		q->dequeue();
		if (temp->data == key)
		{
			keyNode = temp;
		}
		if (temp->left)
		{
			q->enqueue(temp->left);
		}
		if (temp->right)
		{
			q->enqueue(temp->right);
		}
	}
	if (keyNode != nullptr)
	{
		// replacing deepest node with the data of the node to be deleted 
		keyNode->data = temp->data;
		deleteDeepest(this->root, temp);
	}
}

void bt::inOrder()
{
	inOrderTraversal(root);
	cout << endl;
}
