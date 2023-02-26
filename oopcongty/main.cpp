#include <iostream>
#include "CongTy.h"
using namespace std;
int main()
{

    CongTy a;
    a.Nhap();
    cout << "Danh sach nhan vien la:\n";
    a.Xuat();
    cout << "Luong trung binh cua cong ty la: " << a.LuongTrungBinh() << endl;
    cout << "Danh sach nhan vien co luong thap hon luong trung binh la:\n";
    a.XuatLuongThapHonLuongTrungBinh();
    return 0;
}