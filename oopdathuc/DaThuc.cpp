#include "DaThuc.h"

DaThuc::DaThuc(int size) : size(size)
{
    a = new DonThuc[size];
}

DaThuc::DaThuc(DonThuc a) : size(1)
{
    this->a = new DonThuc[1];
    this->a[0] = a;
}

int DaThuc::Calc(int x)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i].Calc(x);
    return sum;
}
istream &operator>>(istream &cin, DaThuc &a)
{
    for (int i = 0; i < a.size; i++)
        cin >> a[i];
    return cin;
}
ostream &operator<<(ostream &cout, const DaThuc &a)
{
    bool flag = 0, first = 0;
    for (int i = 0; i < a.size; i++)
    {
        if (a.a[i].GetA() != 0)
        {
            flag = 1;
            if (a.a[i].GetA() > 0 && first)
                cout << "+";
            first = 1;
            if (a.a[i].GetA() == -1 && a.a[i].GetN() != 0)
                cout << "-";
            if ((a.a[i].GetA() != 1 && a.a[i].GetA() != -1) || a.a[i].GetN() == 0)
                cout << a.a[i].GetA();
            if (a.a[i].GetN() != 0)
            {
                cout << "x";
                if (a.a[i].GetN() != 1)
                    cout << "^" << a.a[i].GetN();
            }
        }
    }
    if (!flag)
        cout << 0;
    return cout;
}
DaThuc operator+(DaThuc a, DaThuc b)
{
}
DaThuc operator-(DaThuc, DaThuc)
{
}