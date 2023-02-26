#include "VeTap.h"

void VeTap::Nhap()
{
    Ve::Nhap();
    cout << "Nhap so gio tap: ";
    cin >> iSoGioTap;
}

void VeTap::Xuat()
{
    Ve::Xuat();
    cout << "So gio tap: " << iSoGioTap << endl;
}

int VeTap::loai()
{
    return 3;
}

int VeTap::tinhTien()
{
    return 1700000 * iSoGioTap;
}