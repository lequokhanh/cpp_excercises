#pragma once
#include <iostream>
#include <string.h>

using namespace std;
class CNhanVien
{
private:
    string sHoTen;
    string sNgaySinh;

public:
    CNhanVien();
    CNhanVien(string, string);
    string getHoTen();
    string getNgaySinh();
    virtual void Nhap();
    virtual void Xuat();
    virtual int TinhLuong();
};