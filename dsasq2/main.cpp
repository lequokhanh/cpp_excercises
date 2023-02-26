/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
template
###End banned keyword*/
#include <string>
#include <iostream>
using namespace std;
struct node {
    char info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l);
node* CreateNode(char c);
void AddTail(List& l, node* p);
void Xuat(List l);
void enqueue(List& l, char c);
int dequeue(List& l);
bool isEmpty(List l);
int main()
{
    char c;
    cin >> c;
    string s = "";
    cin >> s;
    List queue;
    CreateList(queue);
//###INSERT CODE HERE -
    if (!s.size())
        cout << "Chuoi rong.";
    else {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                if (queue.pHead != NULL) {
                    cout << queue.pHead->info;
                    dequeue(queue);
                }
            } else {
                enqueue(queue, s[i]);
            }
        }
        cout << endl;
        if (queue.pHead != NULL) {
            cout << "Cac gia tri co trong hang doi la: ";
            Xuat(queue);
        }
        else
            cout << "Hang doi rong.";
    }
    return 0;
}

void CreateList (List &q) {
    q.pHead =  q.pTail = NULL;
}

node* CreateNode (char data) {
    node *p = new node;
    p->info = data;
    p->pNext = NULL;
    return p;
}

void AddTail (List &l, node *p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void enqueue (List &l, char x) {
    AddTail(l, CreateNode(x));
}

int dequeue (List &l) {
    if (l.pHead != NULL) {
        node *p = l.pHead;
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
        return 1;
    }
    return 0;
}

void Xuat (List q) {
    node *p = q.pHead;
    while (p != NULL) {
        cout << p->info;
        p = p->pNext;
    }
}
