#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class SoPhuc
{
private:
    float fThuc, fAo;

public:
    SoPhuc(float = 0, float = 0);
    friend istream &operator>>(istream &, SoPhuc &);
    friend ostream &operator<<(ostream &, const SoPhuc &);
    friend SoPhuc operator+(SoPhuc, SoPhuc);
    friend SoPhuc operator-(SoPhuc, SoPhuc);
    friend SoPhuc operator*(SoPhuc, SoPhuc);
    friend SoPhuc operator/(SoPhuc, SoPhuc);
    friend float abs(SoPhuc);
};