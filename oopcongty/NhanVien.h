#pragma once
#include <iostream>
#include <string.h>

using namespace std;
class NhanVien
{
protected:
    string MaNV;
    string HoTen;
    int Tuoi;
    string SDT;
    string Email;
    int LuongCoBan;

public:
    virtual void Nhap();
    virtual void Xuat();
    virtual int TinhLuong() = 0;
};