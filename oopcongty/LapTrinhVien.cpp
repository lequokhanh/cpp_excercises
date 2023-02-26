#include "LapTrinhVien.h"

int LapTrinhVien::TinhLuong()
{
    return LuongCoBan + SoGioLamThem * 200000;
}
void LapTrinhVien::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so gio lam them: ";
    cin >> SoGioLamThem;
}
void LapTrinhVien::Xuat()
{
    NhanVien::Xuat();
    cout << "So gio lam them: " << SoGioLamThem << "\n";
    cout << "Luong: " << TinhLuong() << "\n";
}