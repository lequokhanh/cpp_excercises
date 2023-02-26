#pragma once
#include "NhanVien.h"

using namespace std;
class LapTrinhVien : public NhanVien
{
private:
    int SoGioLamThem;

public:
    void Nhap();
    void Xuat();
    int TinhLuong();
};