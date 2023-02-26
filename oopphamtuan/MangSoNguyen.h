#pragma once

class MangSoNguyen
{
    int *SoNguyen;
    int kichthuoc;

public:
    MangSoNguyen();
    MangSoNguyen(int, int[]);
    MangSoNguyen &operator=(const MangSoNguyen &);
    MangSoNguyen *operator+(const MangSoNguyen &); // a+b
    friend istream &operator>>(istream &, MangSoNguyen &);
    friend ostream &operator<<(ostream &, const MangSoNguyen &);
};