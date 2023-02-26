#pragma once

#include <iostream>
#include <string>

using namespace std;

class Ve
{
private:
    string sHoTen;
    string sNgay;

public:
    virtual void Nhap();
    virtual void Xuat();
    virtual int loai() = 0;
    virtual int tinhTien() = 0;
};