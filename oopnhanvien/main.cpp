#include <iostream>
#include "CNhanVien.h"
#include "CNhanVienSanXuat.h"
#include "CNhanVienVanPhong.h"
#include "CCongTy.h"
using namespace std;
int main()
{

    CCongTy a;
    a.Nhap();
    cout << "Danh sach nhan vien la:\n";
    a.Xuat();
    cout << "Tong Luong: " << a.TongLuong();
    cout << "Nhan vien co luong thap nhat:\n";
    a.MinLuong()->Xuat();
    cout << "Nhan vien co luong lon nhat:\n";
    a.MaxLuong()->Xuat();
    a.SapXep();
    cout << "Danh sach nhan vien sau sap xep la:\n";
    a.Xuat();
    return 0;
}