#pragma once
#include <iostream>
#include <string.h>
#include "CNhanVien.h"
#include "CNhanVienSanXuat.h"
#include "CNhanVienVanPhong.h"

using namespace std;
class CCongTy
{
private:
    int size;
    CNhanVien **DS;

public:
    ~CCongTy();
    void Nhap();
    void Xuat();
    CNhanVien *MinLuong();
    CNhanVien *MaxLuong();
    void SapXep();
    int TongLuong();
};