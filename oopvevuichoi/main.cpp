#include <iostream>
#include "Ve.h"
#include "VeTronGoi.h"
#include "VeTungPhan.h"
using namespace std;

int main()
{
    int n;
    cout << "Nhap so luong ve: ";
    cin >> n;
    Ve **DS = new Ve *[n];
    for (int i = 0; i < n; i++)
    {
        int loai;
        cout << "Nhap loai ve: (1: Tron goi, 2: Tung phan) ";
        cin >> loai;
        while (loai != 1 && loai != 2)
        {
            cout << "Nhap loai ve: (1: Tron goi, 2: Tung phan) ";
            cin >> loai;
        }
        if (loai == 1)
        {
            DS[i] = new VeTronGoi;
            DS[i]->Nhap();
        }
        else
        {
            DS[i] = new VeTungPhan;
            DS[i]->Nhap();
        }
    }
    int iTongTien = 0;
    for (int i = 0; i < n; i++)
    {
        iTongTien += DS[i]->tinhTien();
    }
    cout << "Tong tien ma cong vien thu duoc la: " << iTongTien << endl;
    int iSoLuongVeTungPhan = 0;
    for (int i = 0; i < n; i++)
    {
        if (DS[i]->loai() == 2)
            iSoLuongVeTungPhan++;
    }
    cout << "So luong ve tung phan la: " << iSoLuongVeTungPhan << endl;
    return 0;
}