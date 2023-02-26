#include <iostream>

using namespace std;

struct Node {
    int iData;
    Node* pNext;
};

struct Stack {
    Node *pTop;
};

void CreateStack(Stack &s) {
    s.pTop = NULL;
}

Node *createNode(int iData) {
    Node *p = new Node;
    p->iData = iData;
    p->pNext = NULL;
    return p;
}

void Push(Stack &st, Node *p) {
    if (st.pTop == NULL)
        st.pTop = p;
    else {
        p->pNext = st.pTop;
        st.pTop = p;
    }
}

void Pop(Stack &st) {
    if (st.pTop == NULL)
        return;
    else 
        st.pTop = st.pTop->pNext;
}

bool isEmpty(Stack st) {
    if (st.pTop == NULL)
        return true;
    return false;
}

Node *FindInStack(Stack st, int iData) {
    Node *p = st.pTop;
    while (p != NULL) {
        if (p->iData == iData)
            return p;
        p = p->pNext;
    }
    return NULL;
}

void Nhap(Stack &st) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (FindInStack(st, x) == NULL)
            Push(st, createNode(x));
    }
}

int CountElementSmallerThanM (Stack st, int m) {
    int res = 0;
    while(!isEmpty(st)) {
        if (st.pTop->iData < m)
            res++;
        Pop(st);
    }
    return res;
}

void Pop5Element(Stack &st) {
    int i = 0;
    while (i < 5) {
        Pop(st);
        i++;
    }
}

int main() {
    
    return 0;
}