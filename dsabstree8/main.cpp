#include <iostream>

using namespace std;
struct TNode
{
    int data;
    TNode *pLeft;
    TNode *pRight;
};
typedef TNode *Tree;

TNode *CreateTNode(int data)
{
    TNode *node = new TNode;
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}
int Insert(Tree &root, int x, int k)
{
    if (root)
    {
        if (root->data == x)
            return -1;
        if (root->data > x)
            return Insert(root->pLeft, x, k + 1);
        else
            return Insert(root->pRight, x, k + 1);
    }
    root = CreateTNode(x);
    return k + 1;
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
int InputTree(Tree &root)
{
    int x, sizedeep = 0;
    cin >> x;
    while (x != 0)
    {
        sizedeep = max(sizedeep, Insert(root, x, 0));
        cin >> x;
    }
    return sizedeep;
}

void LNR(Tree root, int k, int deep)
{
    if (root)
    {
        LNR(root->pLeft, k + 1, deep);
        if (k == deep)
            cout << root->data << " ";
        LNR(root->pRight, k + 1, deep);
    }
}

int main()
{
    Tree root = NULL;
    int sizedeep = InputTree(root);
    for (int i = 0; i < sizedeep; i++)
    {
        cout << "Deep " << i + 1 << ": ";
        LNR(root, 0, i);
        cout << "\n";
    }
    return 0;
}