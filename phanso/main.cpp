#include <iostream>

using namespace std;

int UCLN (int a, int b) 
{
    if (a == 0) 
        return b;
    return UCLN(b % a, a);
}

struct PhanSo 
{
    int iTuSo, iMauSo;
    PhanSo () 
    {
        if (iMauSo < 0) 
        {
            iTuSo = -iTuSo;
            iMauSo = -iMauSo;
        }
    }
};

void RutGon (PhanSo &a)
{
    int iUCLN = UCLN(a.iTuSo, a.iMauSo);
    a.iTuSo /= iUCLN;
    a.iMauSo /= iUCLN;
}

PhanSo operator+(PhanSo a, PhanSo b) 
{
    PhanSo c;
    c.iTuSo = a.iTuSo * b.iMauSo + b.iTuSo * a.iMauSo;
    c.iMauSo = a.iMauSo * b.iMauSo;
    RutGon(c);
    return c;
}

PhanSo operator-(PhanSo a, PhanSo b) 
{
    PhanSo c;
    c.iTuSo = a.iTuSo * b.iMauSo - b.iTuSo * a.iMauSo;
    c.iMauSo = a.iMauSo * b.iMauSo;
    RutGon(c);
    return c;
}

PhanSo operator*(PhanSo a, PhanSo b) 
{
    PhanSo c;
    c.iTuSo = a.iTuSo * b.iTuSo;
    c.iMauSo = a.iMauSo * b.iMauSo;
    RutGon(c);
    return c;
}

PhanSo operator/(PhanSo a, PhanSo b) 
{
    PhanSo c;
    c.iTuSo = a.iTuSo * b.iMauSo;
    c.iMauSo = a.iMauSo * b.iTuSo;
    RutGon(c);
    return c;
}

istream &operator>>(istream &cin, PhanSo &a) 
{
    cin >> a.iTuSo >> a.iMauSo;
    return cin;
}

ostream &operator<<(ostream &cout, PhanSo a) 
{
    cout << a.iTuSo << "/" << a.iMauSo;
    return cout;
}

void SoSanh (PhanSo a, PhanSo b)
{
    PhanSo temp1 = a;
    PhanSo temp2 = b;
    RutGon(temp1);
    RutGon(temp2);
    if (temp1.iTuSo * temp2.iMauSo > temp2.iTuSo * temp1.iMauSo)
        cout << "Phan so " << a.iTuSo << "/" << a.iMauSo << " lon hon phan so " << b.iTuSo << "/" << b.iMauSo << endl;
    else if (temp1.iTuSo * temp2.iMauSo < temp2.iTuSo * temp1.iMauSo)
        cout << "Phan so " << a.iTuSo << "/" << a.iMauSo << " nho hon phan so " << b.iTuSo << "/" << b.iMauSo << endl;
    else
        cout << "Phan so " << a.iTuSo << "/" << a.iMauSo << " bang phan so " << b.iTuSo << "/" << b.iMauSo << endl;
        
}

void Nhap (PhanSo &a, PhanSo &b)
{
    cout << "Nhap phan so thu nhat:";
    cin >> a;
    cout << "Nhap phan so thu hai:";
    cin >> b;
}

void Xuat (PhanSo a, PhanSo b)
{
    cout << "Cong: " << a + b << endl;
    cout << "Tru: " << a - b << endl;
    cout << "Nhan: " << a * b << endl;
    cout << "Chia: " << a / b << endl;
}

int main() 
{
    PhanSo a, b;
    Nhap(a, b);
    Xuat(a, b);
    return 0;
}