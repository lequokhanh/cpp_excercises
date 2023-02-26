#include <iostream>

using namespace std;
struct TNODE
{
    int data;
    int quantity;
    TNODE *pLeft;
    TNODE *pRight;
};

typedef TNODE *Tree;

TNODE *CreateNode(int data)
{
    TNODE *node = new TNODE;
    node->data = data;
    node->quantity = 1;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}
void Insert(Tree &root, int x)
{
    if (root)
    {
        if (root->data == x)
            root->quantity++;
        else if (root->data > x)
            Insert(root->pLeft, x);
        else
            Insert(root->pRight, x);
        return;
    }
    root = CreateNode(x);
}
void CreateTree(Tree &root)
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
void PrintTree(Tree root)
{
    if (root)
    {
        PrintTree(root->pLeft);
        cout << root->data << " xuat hien " << root->quantity << " lan" << endl;
        PrintTree(root->pRight);
    }
}
TNODE *Search(Tree root, int x)
{
    if (root)
    {
        if (root->data == x)
            return root;
        else if (root->data > x)
            return Search(root->pLeft, x);
        else
            return Search(root->pRight, x);
    }
    return NULL;
}
bool AreIdentical(Tree root1, Tree root2)
{
    if (root2 == NULL)
        return true;
    if (root1 == NULL)
        return false;
    if (root1->data == root2->data)
        return AreIdentical(root1->pLeft, root2->pLeft) && AreIdentical(root1->pRight, root2->pRight);
    return false;
}
bool IsSubtree(Tree root1, Tree root2)
{
    TNODE *p = Search(root1, root2->data);
    if (p)
        return AreIdentical(root1, p);
    return false;
}
int main()
{
    Tree root1 = NULL;
    Tree root2 = NULL;
    CreateTree(root1);
    CreateTree(root2);

    return 0;
}