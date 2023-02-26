#include "Ve.h"

void Ve::Nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, sHoTen);
    cout << "Nhap ngay: ";
    getline(cin, sNgay);
}

void Ve::Xuat()
{
    cout << "Ho ten: " << sHoTen << endl;
    cout << "Ngay: " << sNgay << endl;
}
