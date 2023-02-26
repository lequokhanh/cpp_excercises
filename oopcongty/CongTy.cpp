#include "CongTy.h"

CongTy::~CongTy()
{
    for (int i = 0; i < size; i++)
        delete DS[i];
    delete[] DS;
}

void CongTy::Nhap()
{
    cout << "Nhap tong so nhan vien: ";
    cin >> size;
    DS = new NhanVien *[size];
    for (int i = 0; i < size; i++)
    {
        int loai;
        cout << "Nhap loai nhan Vien (1: Lap Trinh Vien, 2: Kiem Chung Vien): ";
        cin >> loai;
        while (loai != 1 && loai != 2)
        {
            cout << "Nhap lai loai nhan vien: ";
            cin >> loai;
        }
        if (loai == 1)
        {
            DS[i] = new LapTrinhVien;
            DS[i]->Nhap();
        }
        else if (loai == 2)
        {
            DS[i] = new KiemChungVien;
            DS[i]->Nhap();
        }
    }
}
void CongTy::Xuat()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Nhan Vien So " << i + 1 << ":\n";
        DS[i]->Xuat();
    }
}
int CongTy::LuongTrungBinh()
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += DS[i]->TinhLuong();
    return sum / size;
}

void CongTy::XuatLuongThapHonLuongTrungBinh()
{
    int luongTB = LuongTrungBinh();
    for (int i = 0; i < size; i++)
        if (DS[i]->TinhLuong() < luongTB)
            DS[i]->Xuat();
}