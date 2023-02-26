#include <iostream>
#include <cmath>
#include "DonThuc.h"

using namespace std;

DonThuc::DonThuc(int a, int n) : a(a), n(n) {}

int DonThuc::Calc(int x)
{
    return a * pow(x, n);
}
int DonThuc::GetA()
{
    return a;
}
int DonThuc::GetN()
{
    return n;
}