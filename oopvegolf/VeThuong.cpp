#include "VeThuong.h"

void VeThuong::Nhap()
{
    Ve::Nhap();
    cout << "Nhap so dich vu: ";
    cin >> iSoDichVu;
}

void VeThuong::Xuat()
{
    Ve::Xuat();
    cout << "So dich vu: " << iSoDichVu << endl;
}

int VeThuong::loai()
{
    return 2;
}

int VeThuong::tinhTien()
{
    return 1800000 + 600000 * iSoDichVu;
}

int VeThuong::GetSoDichVu()
{
    return iSoDichVu;
}