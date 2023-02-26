#include "NhanVien.h"

void NhanVien::Nhap()
{
    cout << "Nhap ma nhan vien: ";
    cin >> MaNV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap tuoi: ";
    cin >> Tuoi;
    cout << "Nhap SDT: ";
    cin >> SDT;
    cout << "Nhap email: ";
    cin >> Email;
    cout << "Nhap luong co ban: ";
    cin >> LuongCoBan;
}

void NhanVien::Xuat()
{
    cout << "Ma nhan vien: " << MaNV << "\n";
    cout << "Ho ten: " << HoTen << "\n";
    cout << "Tuoi: " << Tuoi << "\n";
    cout << "SDT: " << SDT << "\n";
    cout << "Email: " << Email << "\n";
    cout << "Luong co ban: " << LuongCoBan << "\n";
}