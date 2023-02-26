#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ve
{
protected:
    string sMaVe;
    string sTen;
    int iNamSinh;
    int iSoTroChoi;

public:
    void Nhap();
    void Xuat();
    virtual int loai() = 0;
    virtual int tinhTien() = 0;
};