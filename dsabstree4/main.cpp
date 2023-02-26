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
void Input(Tree &root, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Insert(root, x);
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

int CountLeaf(Tree root)
{
    if (root == NULL)
        return 0;
    if (root->pLeft == NULL && root->pRight == NULL)
        return 1;
    return CountLeaf(root->pLeft) + CountLeaf(root->pRight);
}

void OutputLeaf(Tree root)
{
    if (root == NULL)
        return;
    if (root->pLeft == NULL && root->pRight == NULL)
        cout << root->data << " ";
    OutputLeaf(root->pLeft);
    OutputLeaf(root->pRight);
}
int main()
{
    Tree root = NULL;
    int n;
    cin >> n;
    Input(root, n);
    cout << CountLeaf(root) << endl;
    OutputLeaf(root);
    return 0;
}