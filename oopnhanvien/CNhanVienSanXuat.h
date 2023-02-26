#pragma once
#include "CNhanVien.h"

using namespace std;
class CNhanVienSanXuat : public CNhanVien
{
private:
    int iLuongCanBan, iSoSanPham;

public:
    CNhanVienSanXuat();
    CNhanVienSanXuat(string, string, int, int);
    void Nhap();
    void Xuat();
    int TinhLuong();
};