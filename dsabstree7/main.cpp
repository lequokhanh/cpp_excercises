#include <iostream>

using namespace std;
struct TNode
{
    int data;
    TNode *pLeft;
    TNode *pRight;
};

struct Node
{
    int data;
    Node *pNext;
};
struct List
{
    Node *pHead;
    Node *pTail;
};
typedef TNode *Tree;

Node *CreateNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->pNext = NULL;
    return node;
}

TNode *CreateTNode(int data)
{
    TNode *node = new TNode;
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}
void CreateList(List &l)
{
    l.pHead = l.pTail = NULL;
}
void AddTail(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
bool Insert(Tree &root, int x)
{
    if (root)
    {
        if (root->data == x)
            return false;
        if (root->data > x)
            return Insert(root->pLeft, x);
        else
            return Insert(root->pRight, x);
    }
    root = CreateTNode(x);
    return 1;
}
int Find(Tree root, int x, int k)
{
    if (root)
    {
        if (root->data == x)
        {
            return k;
        }
        if (root->data > x)
            return Find(root->pLeft, x, k + 1);
        else
            return Find(root->pRight, x, k + 1);
    }
    return -1;
}
void InputTree(Tree &root)
{
    int x;
    cin >> x;
    while (x != 0)
    {
        Insert(root, x);
        cin >> x;
    }
}
void InputList(List &l)
{
    int x;
    cin >> x;
    while (x != 0)
    {
        AddTail(l, CreateNode(x));
        cin >> x;
    }
}
void Output(List l, Tree root)
{
    Node *p = l.pHead;
    while (p)
    {
        cout << Find(root, p->data, 0) << "\n";
        p = p->pNext;
    }
}
int main()
{
    Tree root = NULL;
    List l;
    CreateList(l);
    InputTree(root);
    InputList(l);
    Output(l, root);
    return 0;
}