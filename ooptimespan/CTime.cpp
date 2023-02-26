#include "CTime.h"
CTime::CTime(int h, int m, int s) : h(h), m(m), s(s) {}

CTime CTime::operator++()
{
    s++;
    if (s >= 60)
        m++, s = 0;
    if (m >= 60)
        h++, m = 0;
    if (h >= 24)
        h = 0;
    return *this;
}

CTime CTime::operator++(int i)
{
    CTime a = *this;
    s++;
    if (s >= 60)
        m++, s = 0;
    if (m >= 60)
        h++, m = 0;
    if (h >= 24)
        h = 0;
    return a;
}

CTime CTime::operator--()
{
    s--;
    if (s == -1)
        m--, s = 59;
    if (m == -1)
        h--, m = 59;
    if (h == -1)
        h = 23;
    return *this;
}

CTime CTime::operator--(int i)
{
    CTime a = *this;
    s--;
    if (s == -1)
        m--, s = 59;
    if (m == -1)
        h--, m = 59;
    if (h == -1)
        h = 23;
    return a;
}

istream &operator>>(istream &cin, CTime &a)
{
    cin >> a.h >> a.m >> a.s;
    return cin;
}

ostream &operator<<(ostream &cout, const CTime &a)
{
    if (a.h < 10)
        cout << 0;
    cout << a.h << ":";
    if (a.m < 10)
        cout << 0;
    cout << a.m << ":";
    if (a.s < 10)
        cout << 0;
    cout << a.s;
    return cout;
}

CTime operator-(CTime a, int i)
{
    a.s -= i;
    if (a.s < 0)
        a.m += a.s / 60, a.s = 60 + a.s % 60;
    if (a.m < 0)
        a.h += a.m / 60, a.m = 60 + a.m % 60;
    if (a.h < 0)
        a.h = 60 + a.h % 24;
    return a;
}

CTime operator+(CTime a, int i)
{
    a.s += i;
    if (a.s >= 60)
        a.m += a.s / 60, a.s = a.s % 60;
    if (a.m >= 60)
        a.h += a.m / 60, a.m = a.m % 60;
    if (a.h >= 24)
        a.h = a.h % 24;
    return a;
}
