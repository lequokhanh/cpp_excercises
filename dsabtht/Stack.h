#pragma once

#include <stdio.h>
#include "Node.h"

class Stack
{
private:
	Node* pHead;

public:
	Stack();
	~Stack();
	int IsEmpty();
	Node* CreateNode(Data x);
	void Push(Data x);
	int Pop(Data& x);
	Node* GetHead();
};