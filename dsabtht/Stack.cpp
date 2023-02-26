#include "Stack.h"

Stack::Stack()
{
    pHead = NULL;
}

Stack::~Stack()
{
    while (!IsEmpty())
    {
        Node *p = pHead;
        pHead = p->pNext;
        delete p;
    }
}

int Stack::IsEmpty()
{
    return (pHead == NULL ? 1 : 0);
}

Node *Stack::CreateNode(Data x)
{
    Node *p = new Node();
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void Stack::Push(Data x)
{
    Node *p = CreateNode(x);
    if (IsEmpty())
    {
        pHead = p;
    }
    else
    {
        p->pNext = pHead;
        pHead = p;
    }
}

int Stack::Pop(Data &x)
{
    if (IsEmpty())
    {
        return 0;
    }
    else
    {
        Node *p = pHead;
        x = p->Info;
        pHead = p->pNext;
        delete p;
    }
    return 1;
}

Node *Stack::GetHead()
{
    return pHead;
}
