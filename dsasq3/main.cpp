/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
template
###End banned keyword*/
#include <iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct List
{
	node* pHead;
};
void CreateList(List& l)
{
	l.pHead = NULL;
}
node* CreateNode(int x);
void AddHead(List& l, node* p);
void enstack(List& l, int x);
void destack(List& l);
bool isEmpty(List l);
int main()
{
	List st;
	CreateList(st);
	long long x;
	cin >> x;
//###INSERT CODE HERE -
	while (x) {
        enstack(st, x % 2);
        x = x / 2;
    }
    node *p = st.pHead;
    while (p != NULL) {
        cout << p->info;
        p = p->pNext;
    }
}

node* CreateNode (int data) {
    node *p = new node;
    p->info = data;
    p->pNext = NULL;
    return p;
}

void AddHead (List &l, node *p) {
    if (l.pHead == NULL)
        l.pHead = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void enstack (List &l, int x) {
    AddHead(l, CreateNode(x));
}

void destack (List &l) {
    if (l.pHead != NULL) {
        node *p = l.pHead;
        l.pHead = p->pNext;
        delete p;
    }
}