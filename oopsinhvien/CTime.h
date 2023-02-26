#pragma once
#include <iostream>

using namespace std;
class CTimeSpan;
class CTime
{
private:
    int h, m, s;

public:
    CTime(int = 0, int = 0, int = 0);
    CTime operator++();
    CTime operator++(int i);
    CTime operator--();
    CTime operator--(int i);
    friend istream &operator>>(istream &cin, CTime &a);
    friend ostream &operator<<(ostream &cout, const CTime &a);
    friend CTime operator-(CTime, int);
    friend CTime operator+(CTime, int);
    friend CTimeSpan operator-(CTime, CTime);
    friend CTime operator+(CTime, CTimeSpan);
};