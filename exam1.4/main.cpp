#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct TNode
{
	int data;
	TNode *pLeft;
	TNode *pRight;
};
typedef TNode *Tree;

TNode *CreateNode(int x)
{
	TNode *p = new TNode;
	p->data = x;
	p->pLeft = p->pRight = NULL;
	return p;
}

void AddNode(Tree &root, int x)
{
	if (root == NULL)
		root = CreateNode(x);
	else if (root->data > x)
		AddNode(root->pLeft, x);
	else if (root->data < x)
		AddNode(root->pRight, x);
}

bool IsCompleteBinaryTree(Tree root)
{
	if (root == NULL)
		return true;
	Tree p = root;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->pLeft;
	}
	int i = 0;
	p = root;
	while (p != NULL)
	{
		if (i == count - 1)
		{
			if (p->pLeft != NULL || p->pRight != NULL)
				return false;
		}
		else
		{
			if (p->pLeft == NULL || p->pRight == NULL)
				return false;
		}
		p = p->pRight;
		i++;
	}
	return true;
}

void Input(Tree &root)
{
	int x;
	cin >> x;
	while (x != 0)
	{
		AddNode(root, x);
		cin >> x;
	}
}

int main()
{
	Tree root = NULL;
	Input(root);
	if (root == NULL)
		cout << "Cay rong";
	else if (IsCompleteBinaryTree(root))
		cout << "The tree is not a complete binary tree";
	else
		cout << "The tree is a complete binary tree";
	return 0;
}