#pragma once
#include <iostream>
#include <string.h>
#include "NhanVien.h"
#include "LapTrinhVien.h"
#include "KiemChungVien.h"

using namespace std;
class CongTy
{
private:
    int size;
    NhanVien **DS;

public:
    ~CongTy();
    void Nhap();
    void Xuat();
    int LuongTrungBinh();
    void XuatLuongThapHonLuongTrungBinh();
};