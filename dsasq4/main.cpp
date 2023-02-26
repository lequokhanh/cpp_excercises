
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Node {
    int data;
    Node *pNext;
};

struct Stack {
    Node *pTop;
};

void CreateStack (Stack &st) {
    st.pTop = NULL;
}

Node* CreateNode (int data) {
    Node *p = new Node;
    p->data = data;
    p->pNext = NULL;
    return p;
}

void Push (Stack &st, Node *p) {
    if (st.pTop == NULL) 
        st.pTop = p;
    else {
        p->pNext = st.pTop;
        st.pTop = p;
    }
}

void Pop (Stack &st) {
    if (st.pTop != NULL) {
        Node *p = st.pTop;
        st.pTop = p->pNext;
        delete p;
    }
}

bool IsEmpty (Stack st) {
    return st.pTop == NULL;
}

void Xuat (Stack st) {
    Node *p = st.pTop;
    while (p != NULL) {
        cout << p->data;
        p = p->pNext;
    }
}

int main() {
    Stack st;
    CreateStack(st);
    string s;
    cin >> s;
    int x;
    cin >> x;
    if (x == 0)
        cout << 0;
    else {
        int rem = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            Push(st, CreateNode(((s[i] - '0') * x + rem) % 10));
            rem = ((s[i] - '0') * x + rem) / 10;
        }
        if (rem != 0)
            Push(st, CreateNode(rem));
        Xuat(st);
    }
    return 0;
}