#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

typedef Node *Tree;

// insert node in bst
Node *CreateNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
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
    root = CreateNode(x);
    return 1;
}
void Input(Tree &root)
{
    int x;
    cin >> x;
    while (x)
    {
        Insert(root, x);
        cin >> x;
    }
}
bool Find(Tree root, int x)
{
    if (root)
    {
        if (root->data == x)
            return true;
        if (root->data > x)
            return Find(root->pLeft, x);
        else
            return Find(root->pRight, x);
    }
    return false;
}

bool isPrime(int x)
{
    if (x < 2)
        return false;
    if (x < 4)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (int i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

void DeleteNode(Node *&p)
{
    if (p->pLeft == NULL)
        p = p->pRight;
    else if (p->pRight == NULL)
        p = p->pLeft;
    else
    {
        Node *&q = p->pRight;
        while (q->pLeft)
            q = q->pLeft;
        p->data = q->data;
        q = NULL;
    }
}

bool DeletePrimeSmaller(Tree &root)
{
    if (root)
    {
        bool l = DeletePrimeSmaller(root->pLeft);
        if (l)
            return l;
        if (isPrime(root->data))
        {
            DeleteNode(root);
            return 1;
        }
        bool r = DeletePrimeSmaller(root->pRight);
        if (r)
            return r;
    }
    return 0;
}

void Print(Tree root)
{
    if (root)
    {
        Print(root->pLeft);
        cout << root->data << " ";
        Print(root->pRight);
    }
}

int main()
{
    Tree root = NULL;
    Input(root);
    int n;
    cin >> n;
    while (n--)
        DeletePrimeSmaller(root);
    if (root)
        Print(root);
    else
        cout << "Not found tree!";
    return 0;
}