#include <iostream>
#include "CTimeSpan.h"

using namespace std;

// CTimeSpan::CTimeSpan() {}

CTimeSpan::CTimeSpan(int h, int m, int s) : h(h), m(m), s(s) {}

CTimeSpan operator+(CTimeSpan a, CTimeSpan b)
{
    int hnew = a.h + b.h, mnew = a.m + b.m, snew = a.s + b.s;
    if (snew > 60)
    {
        mnew += snew / 60;
        snew %= 60;
    }
    if (mnew > 60)
    {
        hnew += mnew / 60;
        mnew %= 60;
    }
    return {hnew, mnew, snew};
}

CTimeSpan operator-(CTimeSpan a, CTimeSpan b)
{
    int hnew = a.h - b.h, mnew = a.m - b.m, snew = a.s - b.s;
    if (snew < 0)
    {
        mnew -= 1;
        snew += 60;
    }
    if (mnew < 0)
    {
        hnew -= 1;
        mnew += 60;
    }
    return {hnew, mnew, snew};
}

bool operator==(CTimeSpan a, CTimeSpan b)
{
    return a.h == b.h && a.m == b.m && a.s == b.s;
}

bool operator>(CTimeSpan a, CTimeSpan b)
{
    return a.h > b.h || (a.h == b.h && a.m > b.m) || (a.h == b.h && a.m == b.m && a.s > b.s);
}

bool operator>=(CTimeSpan a, CTimeSpan b)
{
    return a == b || a > b;
}

bool operator<(CTimeSpan a, CTimeSpan b)
{
    return !(a >= b);
}

bool operator<=(CTimeSpan a, CTimeSpan b)
{
    return a == b || a < b;
}

bool operator!=(CTimeSpan a, CTimeSpan b)
{
    return !(a == b);
}
istream &operator>>(istream &cin, CTimeSpan &a)
{
    cin >> a.h >> a.m >> a.s;
    return cin;
}

ostream &operator<<(ostream &cout, const CTimeSpan &a)
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