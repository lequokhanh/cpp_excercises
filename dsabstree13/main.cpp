#include <iostream>

using namespace std;
struct Node
{
    int data;
    int quantity;
    Node *pLeft;
    Node *pRight;
};

typedef Node *Tree;

// insert node in bst
Node *CreateNode(int data)
{
    Node *node = new Node;
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
void Input(Tree &root)
{
    int x;
    cin >> x;
    while (x != 0)
    {
        Insert(root, x);
        cin >> x;
    }
}
int DeleteLargest(Tree &root)
{
    if (root)
    {
        if (root->pRight)
            return DeleteLargest(root->pRight);
        else
        {
            int temp = root->data;
            root->quantity--;
            if (root->quantity == 0)
                root = root->pLeft;
            return temp;
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Tree root = NULL;
    while (true)
    {
        char c;
        cin >> c;
        if (c == 'U')
        {
            int x;
            cin >> x;
            Insert(root, x);
        }
        else if (c == 'O')
        {
            int res = DeleteLargest(root);
            if (res == -1)
                cout << "NULL";
            else
                cout << res;
            cout << "\n";
        }
        else if (c == 'E')
        {
            break;
        }
    }
    return 0;
}