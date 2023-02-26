#include <iostream>
#include <queue>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

TNODE *CreateNode(int key)
{
    TNODE *node = new TNODE;
    node->key = key;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}
bool Insert(TREE &root, int x)
{
    if (root)
    {
        if (root->key == x)
            return 0;
        else if (root->key > x)
            Insert(root->pLeft, x);
        else
            Insert(root->pRight, x);
    }
    root = CreateNode(x);
    return 1;
}
void CreateTree(TREE &root)
{
    int x;
    cin >> x;
    while (x != -1)
    {
        Insert(root, x);
        cin >> x;
    }
}

TNODE *Search(TREE root, int x)
{
    if (root)
    {
        if (root->key == x)
            return root;
        else if (root->key > x)
            return Search(root->pLeft, x);
        else
            return Search(root->pRight, x);
    }
    return NULL;
}

bool AreIdentical(TREE root1, TREE root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    if (root1->key == root2->key)
    {
        if (root2->pRight)
            bool r = AreIdentical(root1->pRight, root2->pRight);
        if (root2->pLeft)
            bool l = AreIdentical(root1->pLeft, root2->pLeft);
    }
    return false;
}
bool isSubtree(TREE root2, TREE root1)
{
    if (root2 == NULL)
        return true;
    TNODE *p = Search(root1, root2->key);
    return AreIdentical(p, root2);
}

int main()
{
    TNODE *S, *T;
    S = NULL;
    T = NULL;

    CreateTree(S);
    CreateTree(T);

    cout << boolalpha << isSubtree(S, T);

    return 0;
}