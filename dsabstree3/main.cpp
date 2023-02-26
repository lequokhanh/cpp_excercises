#include <iostream>

using namespace std;
struct Node
{
    float data;
    Node *pLeft;
    Node *pRight;
};

typedef Node *Tree;

// insert node in bst
Node *CreateNode(float data)
{
    Node *node = new Node;
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}
bool Insert(Tree &root, float x)
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
float Input(Tree &root, int n)
{
    float avg = 0;
    for (float i = 0; i < n; i++)
    {
        float x;
        cin >> x;
        avg += x;
        Insert(root, x);
    }
    return avg / n;
}
bool Find(Tree root, float x)
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
void LNR(Tree root)
{
    if (root)
    {
        LNR(root->pLeft);
        cout << root->data << " ";
        LNR(root->pRight);
    }
}
int main()
{
    Tree root = NULL;
    float n;
    cin >> n;
    float avg = Input(root, n);
    cout << Find(root, avg) << endl;
    LNR(root);
    return 0;
}