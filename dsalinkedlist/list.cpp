#include <iostream>

using namespace std;

struct Node {
    int iData;
    Node *pNext;
};

struct List {
    Node *pHead;
    Node *pTail;
};

//Init a list
void createList(List &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* createNode(int iData) {
    Node *newNode = new Node;
    newNode->iData = iData;
    newNode->pNext = NULL;
    return newNode;
}
void addHead(List &l, Node *p) {
    if (l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        p->pNext = l.pHead;
        l.pHead = p;
    }                                                   
}

// add node p to the tail of list l
void addTail(List &l, Node *p) {
    if (l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void insertAfterQ(List &l, Node *p, Node *q) {
    if (q != NULL) {
        p->pNext = q->pNext;
        q->pNext = p;
        if (l.pTail == q)
            l.pTail = p;
    } else
        addHead(l, q);
}
void input(List &l) {
    int iData;
    while (true) {
        cin >> iData;
        if (iData <= 0)
            return;
        Node *newNode = createNode(iData);
        addHead(l, newNode);
    }
}
void output(List l) {
    Node *p = l.pHead;
    while (p != NULL) {
        cout << p->iData << " ";
        p = p->pNext;
    }
    cout << endl;
}

void InsertDecreasing (List &l, Node *p) {
    Node *q = l.pHead;
    while (q != NULL && q->iData < p->iData) {
        q = q->pNext;
    }
    insertAfterQ(l, p, q);
}

Node* search(List l, int iData) {
    Node *p = l.pHead;
    while (p != NULL) {
        if (p->iData == iData)
            return p;
        p = p->pNext;
    }
    return NULL;
}
int main() {
    List l;
    createList(l);
    input(l);
    output(l);
    return 0;
}
