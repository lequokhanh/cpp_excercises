#include "KiemChungVien.h"

int KiemChungVien::TinhLuong()
{
    return LuongCoBan + SoLoi * 50000;
}
void KiemChungVien::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so loi: ";
    cin >> SoLoi;
}
void KiemChungVien::Xuat()
{
    NhanVien::Xuat();
    cout << "So loi: " << SoLoi << "\n";
    cout << "Luong: " << TinhLuong() << "\n";
}