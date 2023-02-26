#include <iostream>
#include <math.h>
#include "PhanSo.h"

using namespace std;
PhanSo::PhanSo() {}
PhanSo::PhanSo(int iTuSo) : iTuSo(iTuSo), iMauSo(1) {}
PhanSo::PhanSo(int iTuSo, int iMauSo) : iTuSo(iTuSo), iMauSo(iMauSo) {}

void PhanSo::Nhap()
{
    cout << "Nhap tu so: ";
    cin >> iTuSo;
    cout << "Nhap mau so: ";
    cin >> iMauSo;
}

void PhanSo::Xuat()
{
    cout << iTuSo << "/" << iMauSo;
}

PhanSo operator+(PhanSo x, PhanSo y)
{
    return {x.iTuSo * y.iMauSo + y.iTuSo * x.iMauSo, x.iMauSo * y.iMauSo};
}

PhanSo operator-(PhanSo x, PhanSo y)
{
    return {x.iTuSo * y.iMauSo - y.iTuSo * x.iMauSo, x.iMauSo * y.iMauSo};
}

PhanSo operator*(PhanSo x, PhanSo y)
{
    return {x.iTuSo * y.iTuSo, x.iMauSo * y.iMauSo};
}

PhanSo operator/(PhanSo x, PhanSo y)
{
    return {x.iTuSo * y.iMauSo, x.iMauSo * y.iTuSo};
}

// float sqrt(PhanSo x) {
//     return sqrt(x.iTuSo)/ sqrt(x.iMauSo);
// }
PhanSo::operator float()
{
    return float(iTuSo) / float(iMauSo);
}

istream &operator>>(istream &cin, PhanSo &a)
{
    cin >> a.iTuSo >> a.iMauSo;
    return cin;
}

ostream &operator<<(ostream &cout, const PhanSo &a)
{
    cout << a.iTuSo << "/" << a.iMauSo;
    return cout;
}

void PhanSo::format()
{
    if (iMauSo < 0)
    {
        iTuSo *= -1;
        iMauSo *= -1;
    }
}

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

void PhanSo::RutGon()
{
    int ucln = UCLN(iTuSo, iMauSo);
    iTuSo /= ucln;
    iMauSo /= ucln;
}