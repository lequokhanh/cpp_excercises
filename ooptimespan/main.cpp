#include <iostream>
#include "CTimeSpan.h"
#include "CTime.h"
using namespace std;
CTimeSpan operator-(CTime a, CTime b)
{
    int h = a.h - b.h, m = a.m - b.m, s = a.s - b.s;
    if (s < 0)
    {
        m -= 1;
        s += 60;
    }
    if (m < 0)
    {
        h -= 1;
        m += 60;
    }
    return {h, m, s};
}

CTime operator+(CTime a, CTimeSpan b)
{
    int hnew = a.h + b.h, mnew = a.m + b.m, snew = a.s + b.s;
    if (snew >= 60)
        mnew += snew / 60, snew = snew % 60;
    if (mnew >= 60)
        hnew += mnew / 60, mnew = mnew % 60;
    if (hnew >= 24)
        hnew = hnew % 24;
    return {hnew, mnew, snew};
}
int main()
{
    CTime a, b;
    cin >> a >> b;
    CTimeSpan c;
    cin >> c;
    cout << a + c << endl;
    return 0;
}