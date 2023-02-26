
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
        cout << p->data << " ";
        p = p->pNext;
    }
}

int main() {
    Stack s;
    CreateStack(s);
    int x;
    cin >> x;
    while (true) {
        int a;
        cin >> a;
        if (a == 0)
            break;
        else if (a != x) {
            Push (s, CreateNode(a));
        } else {
            if (!IsEmpty(s))
                Pop(s);
            else
                cout << "Stack rong.\n";
        }
    }
    if (IsEmpty(s))
        cout << "Stack rong.\n";
    else {
        cout << "Cac gia tri co trong stack la: ";
        Xuat(s);
    }
    return 0;
}