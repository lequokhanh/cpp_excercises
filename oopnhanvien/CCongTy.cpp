#include "CCongTy.h"

CCongTy::~CCongTy()
{
    for (int i = 0; i <= size; i++)
        delete DS[i];
    delete[] DS;
}

void CCongTy::Nhap()
{
    cout << "Nhap tong so nhan vien: ";
    cin >> size;
    DS = new CNhanVien *[size];
    for (int i = 0; i < size; i++)
    {
        int loai;
        cout << "Nhap loai nhan Vien (1: Nhan vien san xuat, 2: Nhan vien van phong): ";
        cin >> loai;
        while (loai != 1 && loai != 2)
        {
            cout << "Nhap lai loai nhan vien: ";
            cin >> loai;
        }
        if (loai == 1)
        {
            cin.ignore();
            DS[i] = new CNhanVienSanXuat;
            DS[i]->Nhap();
        }
        else if (loai == 2)
        {
            cin.ignore();
            DS[i] = new CNhanVienVanPhong;
            DS[i]->Nhap();
        }
    }
}
void CCongTy::Xuat()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Nhan Vien So " << i + 1 << ":\n";
        DS[i]->Xuat();
    }
}
CNhanVien *CCongTy::MinLuong()
{
    int iMinLuong = 0;
    for (int i = 0; i < size; i++)
        if (DS[i]->TinhLuong() < DS[iMinLuong]->TinhLuong())
            iMinLuong = i;
    return DS[iMinLuong];
}
CNhanVien *CCongTy::MaxLuong()
{
    int iMaxLuong = 0;
    for (int i = 0; i < size; i++)
        if (DS[i]->TinhLuong() > DS[iMaxLuong]->TinhLuong())
            iMaxLuong = i;
    return DS[iMaxLuong];
}
void CCongTy::SapXep()
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (DS[i]->TinhLuong() < DS[j]->TinhLuong())
                swap(DS[i], DS[j]);
}
int CCongTy::TongLuong()
{
    int iTongLuong = 0;
    for (int i = 0; i < size; i++)
        iTongLuong += DS[i]->TinhLuong();
    return iTongLuong;
}