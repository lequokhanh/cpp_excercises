#include "CNhanVien.h"

CNhanVien::CNhanVien() {}
CNhanVien::CNhanVien(string sHoTen, string sNgaySinh) : sHoTen(sHoTen), sNgaySinh(sNgaySinh) {}
string CNhanVien::getHoTen()
{
    return sHoTen;
}
string CNhanVien::getNgaySinh()
{
    return sNgaySinh;
}
void CNhanVien::Nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, sHoTen);
    cout << "Nhap ngay sinh: ";
    cin >> sNgaySinh;
}

void CNhanVien::Xuat()
{
    cout << "Ho Ten: " << sHoTen << "\n";
    cout << "Ngay Sinh: " << sNgaySinh << "\n";
}

int CNhanVien::TinhLuong()
{
    return 0;
}