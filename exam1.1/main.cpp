/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[
]
template
###End banned keyword*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct ns
{
    int ngay;
    char thang[20];
    int nam;
};
struct nhancong
{
    char ten[250];
    char birthplace[250];
    float bacluong;
    ns ngaysinh;
};
struct node
{
    nhancong info;
    node *pnext;
};
struct list
{
    node *phead;
    node *ptail;
};

void CreateList(list &l)
{
    l.phead = l.ptail = NULL;
}

node *CreateNode(nhancong info)
{
    node *newNode = new node;
    newNode->info = info;
    newNode->pnext = NULL;
    return newNode;
}

void AddTail(list &l, node *p)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        l.ptail->pnext = p;
        l.ptail = p;
    }
}
void AddHead(list &l, node *p)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        p->pnext = l.phead;
        l.phead = p;
    }
}
void Input(ns &ngaysinh)
{
    cin >> ngaysinh.ngay;
    cin.ignore();
    cin.getline(ngaysinh.thang, 20);
    cin >> ngaysinh.nam;
}

void Input(nhancong &x)
{
    cin.getline(x.ten, 250);
    cin.getline(x.birthplace, 250);
    cin >> x.bacluong;
    Input(x.ngaysinh);
}

void Input(list &l)
{
    char choice;
    cin >> choice;
    while (choice == 'I')
    {
        cin.ignore();
        nhancong x;
        Input(x);
        AddTail(l, CreateNode(x));
        cin >> choice;
    }
}
void Output(ns ngaysinh)
{
    cout << ngaysinh.ngay << "\n"
         << ngaysinh.thang << "\n"
         << ngaysinh.nam << "\n";
}
void Output(nhancong x)
{
    cout << x.ten << "\n"
         << x.birthplace << "\n"
         << x.bacluong << "\n";
    Output(x.ngaysinh);
}
void Output(list &l, node *p)
{
    while (p)
    {
        Output(p->info);
        p = p->pnext;
    }
}
void Quicksort(list &l)
{
    if (l.phead == l.ptail)
        return;
    list l1, l2;
    CreateList(l1);
    CreateList(l2);
    node *pivot, *p;
    pivot = l.phead;
    l.phead = l.phead->pnext;
    pivot->pnext = NULL;
    while (l.phead)
    {
        p = l.phead;
        l.phead = l.phead->pnext;
        p->pnext = NULL;
        if (p->info.ngaysinh.nam <= pivot->info.ngaysinh.nam)
            AddHead(l1, CreateNode(p->info));
        else
            AddHead(l2, CreateNode(p->info));
    }
    Quicksort(l1);
    Quicksort(l2);
    if (l1.phead != NULL)
    {
        l.phead = l1.phead;
        l1.ptail->pnext = pivot;
    }
    else
        l.phead = pivot;
    pivot->pnext = l2.phead;
    if (l2.ptail != NULL)
        l.ptail = l2.ptail;
    else
        l.ptail = pivot;
}

void DeleteNodeSame(list &l, node *&res)
{
    int maxFreq = 0;
    node *prev = NULL;
    node *p = l.phead;
    while (p)
    {
        node *q = p;
        int freq = 0;
        while (q->pnext)
        {
            if (q->pnext->info.bacluong == p->info.bacluong)
            {
                freq++;
                node *temp = q->pnext;
                q->pnext = temp->pnext;
                delete temp;
            }
            q = q->pnext;
        }
        if (freq > maxFreq)
        {
            maxFreq = freq;
            res = p;
        }
        else if (freq < maxFreq)
        {
            node *temp = prev->pnext;
            prev->pnext = temp->pnext;
            delete temp;
        }
        prev = p;
        p = p->pnext;
    }
}

int main()
{
    list l;
    CreateList(l);
    Input(l);
    if (l.phead == NULL)
        cout << "Danh sach rong";
    else
    {
        Quicksort(l);
        node *res = l.phead;
        DeleteNodeSame(l, res);
        Output(l, res);
    }
}
//###INSERT CODE HERE -
