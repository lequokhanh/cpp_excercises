#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int64_t iTuSo, iMauSo;
};

struct Node {
    PhanSo data;
    Node *pNext;
};

struct List {
    Node *pHead;
    Node *pTail;
};

void CreateList (List &l) {
    l.pHead = l.pTail = NULL;
}

Node *CreateNode (PhanSo x) {
    Node *p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void AddTail (List &l, Node *p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

bool operator== (PhanSo a, PhanSo b) {
    return (long double)a.iTuSo/a.iMauSo == (long double)b.iTuSo/b.iMauSo;
}

istream &operator>>(istream &cin, PhanSo &a) {
    cin >> a.iTuSo >> a.iMauSo;
    return cin;
}

ostream &operator<<(ostream &cout, PhanSo a) {
    cout << a.iTuSo << "/" << a.iMauSo;
    return cout;
}

void Input (List &l) {
    PhanSo x;
    while (true) {
        cin >> x;
        if (x.iMauSo == 0) break;
        Node *p = CreateNode(x);
        AddTail(l, p);
    }
}

Node *Search (List l, Node *p, PhanSo x) {
    while (p != NULL) {
        if (p->data == x)
            return p;
        p = p->pNext;
    }
    return p;
}

void Output (List l, PhanSo x) {
    Node *p = l.pHead;
    cout << "Danh sach vua nhap la: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
    p = Search(l, l.pHead, x);
    if (p != NULL) {
        cout << "Cac phan so bang " << x << " co trong danh sach la: ";
        while (p != NULL) {
            cout << p->data << " ";
            p = Search(l, p->pNext, x);
        } 
    } else
        cout << "Khong co phan so nao bang " << x << " trong danh sach.";
}

int main() {
    List l;
    CreateList(l);
    Input(l);
    if (l.pHead == NULL) 
        cout << "Danh sach rong.";
    else {
        PhanSo x;
        cin >> x;
        Output(l, x);
    }
    return 0;
}

