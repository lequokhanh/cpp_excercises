#include <iostream>
#include "Ve.h"
#include "VeTap.h"
#include "VeThuong.h"
#include "VeVip.h"
using namespace std;

Ve **Nhap(int &n)
{
    cout << "1. Nhap so luong ve: ";
    cin >> n;
    Ve **DS = new Ve *[n];
    for (int i = 0; i < n; i++)
    {
        int loai;
        cout << "Nhap loai ve (1: Ve Tap, 2: Ve Thuong, 3: Ve Vip): ";
        cin >> loai;
        while (loai < 1 || loai > 3)
        {
            cout << "Nhap lai loai ve (1: Ve Tap, 2: Ve Thuong, 3: Ve Vip): ";
            cin >> loai;
        }
        cin.ignore();
        if (loai == 1)
        {
            DS[i] = new VeTap;
            DS[i]->Nhap();
        }
        else if (loai == 2)
        {
            DS[i] = new VeThuong;
            DS[i]->Nhap();
        }
        else
        {
            DS[i] = new VeVip;
            DS[i]->Nhap();
        }
    }
    return DS;
}

int TongTienVeTap(Ve **DS, int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (DS[i]->loai() == 3)
        {
            tong += DS[i]->tinhTien();
        }
    }
    return tong;
}

int TrungBinhSoDichVuVeThuong(Ve **DS, int n)
{
    int tong = 0;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (DS[i]->loai() == 2)
        {
            tong += ((VeThuong *)DS[i])->GetSoDichVu();
            dem++;
        }
    }
    if (dem == 0)
        return 0;
    return tong / dem;
}

Ve *GiaVeThuongCaoNhat(Ve **DS, int n)
{
    int i = 0;
    while (i < n && DS[i]->loai() != 2)
    {
        i++;
    }
    if (i < n && DS[i]->loai() == 2)
    {

        int maxGia = i;
        for (; i < n; i++)
        {
            if (DS[i]->loai() == 2 && DS[i]->tinhTien() > DS[maxGia]->tinhTien())
                maxGia = i;
        }
        return DS[maxGia];
    }
    return NULL;
}

int main()
{
    int n;
    Ve **DS = Nhap(n);
    cout << "2. Tong tien ve da ban cho nguoi moi tap la: " << TongTienVeTap(DS, n) << endl;
    cout << "3. Trung binh so dich vu chon them cua ve thuong la: " << TrungBinhSoDichVuVeThuong(DS, n) << endl;
    Ve *max = GiaVeThuongCaoNhat(DS, n);
    if (max == NULL)
        cout << "4. Khong co ve thuong nao ca" << endl;
    else
    {
        cout << "4. Gia ve thuong co gia cao nhat la: " << endl;
        GiaVeThuongCaoNhat(DS, n)->Xuat();
        cout << "Gia ve: " << GiaVeThuongCaoNhat(DS, n)->tinhTien() << endl;
    }
    return 0;
}