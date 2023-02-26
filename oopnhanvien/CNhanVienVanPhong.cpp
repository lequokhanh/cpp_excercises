#include "CNhanVienVanPhong.h"

CNhanVienVanPhong::CNhanVienVanPhong() {}
CNhanVienVanPhong::CNhanVienVanPhong(string sHoTen, string sNgaySinh, int iSoNgayLamViec) : CNhanVien(sHoTen, sNgaySinh), iSoNgayLamViec(iSoNgayLamViec) {}

int CNhanVienVanPhong::TinhLuong()
{
    return iSoNgayLamViec * 100000;
}
void CNhanVienVanPhong::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap So Ngay Lam Viec: ";
    cin >> iSoNgayLamViec;
}
void CNhanVienVanPhong::Xuat()
{
    CNhanVien::Xuat();
    cout << "So ngay lam viec: " << iSoNgayLamViec << "\n";
    cout << "Luong: " << TinhLuong() << "\n";
}