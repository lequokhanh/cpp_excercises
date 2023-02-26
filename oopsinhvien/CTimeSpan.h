#pragma once
#include <iostream>

using namespace std;
class CTime;
class CTimeSpan
{
private:
    int h, m, s;

public:
    CTimeSpan(int = 0, int = 0, int = 0);
    friend istream &operator>>(istream &, CTimeSpan &);
    friend ostream &operator<<(ostream &, const CTimeSpan &);
    friend CTimeSpan operator+(CTimeSpan, CTimeSpan);
    friend CTimeSpan operator-(CTimeSpan, CTimeSpan);
    friend bool operator==(CTimeSpan, CTimeSpan);
    friend bool operator>(CTimeSpan, CTimeSpan);
    friend bool operator<(CTimeSpan, CTimeSpan);
    friend bool operator>=(CTimeSpan, CTimeSpan);
    friend bool operator<=(CTimeSpan, CTimeSpan);
    friend bool operator!=(CTimeSpan, CTimeSpan);
    friend CTime operator+(CTime, CTimeSpan);
    friend CTimeSpan operator-(CTime, CTime);
};