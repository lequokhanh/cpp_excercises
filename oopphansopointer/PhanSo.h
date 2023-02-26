#pragma once
#include <iostream>

using namespace std;
class PhanSo
{
private:
    int *iTuSo, *iMauSo;

public:
    PhanSo();
    PhanSo(int iTuSo);
    PhanSo(int iTuSo, int iMauSo);
    void Nhap();
    void Xuat();
    friend PhanSo operator+(PhanSo, PhanSo);
    friend PhanSo operator-(PhanSo, PhanSo);
    friend PhanSo operator*(PhanSo, PhanSo);
    friend PhanSo operator/(PhanSo, PhanSo);
    friend istream &operator>>(istream &, PhanSo &);
    friend ostream &operator<<(ostream &, const PhanSo &);
    // operator float();
    void format();
    friend PhanSo RutGon(PhanSo);
};