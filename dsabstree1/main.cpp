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

void DeleteNode(Tree &root)
{
    if (root->pLeft == NULL)
        root = root->pRight;
    else if (root->pRight == NULL)
        root = root->pLeft;
    else
    {
        Tree &temp = root->pLeft;
        while (temp->pRight)
            temp = temp->pRight;
        root->data = temp->data;
        DeleteNode(root->pLeft);
    }
}

void Delete(Tree &root, int x)
{
    if (root)
    {
        if (root->data == x)
            DeleteNode(root);
        else if (root->data > x)
            Delete(root->pLeft, x);
        else
            Delete(root->pRight, x);
    }
}

void LNR(Tree root)
{
    if (root)
    {
        LNR(root->pLeft);
        cout << root->data << " ";
        LNR(root->pRight);
    }
}
void LRN(Tree root)
{
    if (root)
    {
        LRN(root->pLeft);
        LRN(root->pRight);
        cout << root->data << " ";
    }
}
void RNL(Tree root)
{
    if (root)
    {
        RNL(root->pRight);
        cout << root->data << " ";
        RNL(root->pLeft);
    }
}
void RLN(Tree root)
{
    if (root)
    {
        RLN(root->pRight);
        RLN(root->pLeft);
        cout << root->data << " ";
    }
}
void NLR(Tree root)
{
    if (root)
    {
        cout << root->data << " ";
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}
void NRL(Tree root)
{
    if (root)
    {
        cout << root->data << " ";
        NRL(root->pRight);
        NRL(root->pLeft);
    }
}
void Input(Tree &root)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Insert(root, x);
    }
}
int main()
{
    Tree root = NULL;
    Input(root);
    int x;
    cin >> x;
    Delete(root, x);
    LNR(root);
    return 0;
}