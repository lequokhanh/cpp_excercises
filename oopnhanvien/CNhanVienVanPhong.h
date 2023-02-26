#pragma once
#include "CNhanVien.h"

using namespace std;
class CNhanVienVanPhong : public CNhanVien
{
private:
    int iSoNgayLamViec;

public:
    CNhanVienVanPhong();
    CNhanVienVanPhong(string, string, int);
    void Nhap();
    void Xuat();
    int TinhLuong();
};