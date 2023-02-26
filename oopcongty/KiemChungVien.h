#pragma once
#include "NhanVien.h"

using namespace std;
class KiemChungVien : public NhanVien
{
private:
    int SoLoi;

public:
    void Nhap();
    void Xuat();
    int TinhLuong();
};