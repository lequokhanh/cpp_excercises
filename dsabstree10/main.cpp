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
bool Insert(Tree &root, int x)
{
    if (root)
    {
        if (root->data == x)
            return 0;
        if (root->data > x)
            return Insert(root->pLeft, x);
        else
            return Insert(root->pRight, x);
    }
    root = CreateTNode(x);
    return 1;
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
void InputTree(Tree &root, int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Insert(root, x);
    }
}

int CountChild(Tree root)
{
    if (root->pLeft && root->pRight)
        return 2;
    else if (root->pLeft || root->pRight)
        return 1;
    return 0;
}

void LNR(Tree root, int &k)
{
    if (root)
    {
        if (CountChild(root) == 1)
            k++;
        LNR(root->pLeft, k);
        LNR(root->pRight, k);
    }
}

int main()
{
    Tree root = NULL;
    int n;
    InputTree(root, n);
    int k = 0;
    LNR(root, k);
    cout << "So node bac 1 cua cay la: " << k;
    return 0;
}