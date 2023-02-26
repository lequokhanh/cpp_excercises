
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

int kiemTraNhanhTrai(node *root, int x);
int kiemTraNhanhPhai(node *root, int x);

void inDanhSachGiamDan(node *TREE);

string chuyenNhiPhan(int x);

bool kiemTraDoiXung(string s);
void demSoChuoiDoiXung(node *TREE, int &cnt);

node *themPhanTuVaoCay(node *&root, int x);

int main()
{
    node *TREE = NULL;
    int x, cnt = 0;
    while (scanf("%d", &x))
    {
        if (x == 0)
        {
            inDanhSachGiamDan(TREE);
            cout << endl;
            demSoChuoiDoiXung(TREE, cnt);
            cout << "Co " << cnt << " node thoa de bai." << endl;
            break;
        }
        else
            themPhanTuVaoCay(TREE, x);
    }
}
void inDanhSachGiamDan(node *root)
{
    if (root)
    {
        inDanhSachGiamDan(root->right);
        cout << root->data << " ";
        inDanhSachGiamDan(root->left);
    }
}

string chuyenNhiPhan(int x)
{
    string s = "";
    while (x)
    {
        s = (x % 2 == 0 ? "0" : "1") + s;
        x /= 2;
    }
    return s;
}

bool kiemTraDoiXung(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void demSoChuoiDoiXung(node *root, int &k)
{
    if (root)
    {
        demSoChuoiDoiXung(root->left, k);
        if (kiemTraDoiXung(chuyenNhiPhan(root->data)))
            k++;
        demSoChuoiDoiXung(root->right, k);
    }
}
node *CreateNode(int data)
{
    node *p = new node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
node *themPhanTuVaoCay(node *&root, int x)
{
    if (root)
    {
        if (root->data > x)
            return themPhanTuVaoCay(root->left, x);
        else
            return themPhanTuVaoCay(root->right, x);
    }
    root = CreateNode(x);
    return root;
}