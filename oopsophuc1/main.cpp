#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main()
{
    SoPhuc a, b;
    a.Nhap();
    b.Nhap();
    cout << "Cong: ";
    a.Cong(b).Xuat();
    cout << endl;
    cout << "Tru: ";
    a.Tru(b).Xuat();
    cout << endl;
    cout << "Nhan: ";
    a.Nhan(b).Xuat();
    cout << endl;
    cout << "Chia: ";
    a.Chia(b).Xuat();
    cout << endl;
    return 0;
}