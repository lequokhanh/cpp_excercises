#pragma once
#include "DonThuc.h"
#include <iostream>
using namespace std;
class DaThuc
{
private:
    int size;
    DonThuc *a;

public:
    DaThuc(int = 0);
    DaThuc(DonThuc);
    int Calc(int);
    friend istream &operator>>(istream &cin, DaThuc &a);
    friend ostream &operator<<(ostream &cout, const DaThuc &a);
    friend DaThuc operator+(DaThuc, DaThuc);
    friend DaThuc operator-(DaThuc, DaThuc);
};