#include "CNhanVienSanXuat.h"

CNhanVienSanXuat::CNhanVienSanXuat() {}
CNhanVienSanXuat::CNhanVienSanXuat(string sHoTen, string sNgaySinh, int iLuongCanBan, int iSoSanPham) : CNhanVien(sHoTen, sNgaySinh), iLuongCanBan(iLuongCanBan), iSoSanPham(iSoSanPham) {}

int CNhanVienSanXuat::TinhLuong()
{
    return iLuongCanBan + iSoSanPham * 5000;
}
void CNhanVienSanXuat::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    cin >> iLuongCanBan;
    cout << "Nhap so san pham ";
    cin >> iSoSanPham;
}
void CNhanVienSanXuat::Xuat()
{
    CNhanVien::Xuat();
    cout << "Luong can ban: " << iLuongCanBan << "\n";
    cout << "So san pham: " << iSoSanPham << "\n";
    cout << "Luong: " << TinhLuong() << "\n";
}