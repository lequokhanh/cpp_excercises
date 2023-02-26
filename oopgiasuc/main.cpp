#include <iostream>
#include "CBo.h"
#include "CDe.h"
#include "CCuu.h"
#include "CGiaSuc.h"

using namespace std;

CGiaSuc **Nhap(int &n)
{
    cout << "Nhap so luong gia suc: ";
    cin >> n;
    CGiaSuc **NongTrai = new CGiaSuc *[n];
    for (int i = 0; i < n; i++)
    {
        int loai;
        cout << "Nhap loai gia suc (1: Bo, 2: De, 3: Cuu):";
        cin >> loai;
        while (loai != 1 && loai != 2 && loai != 3)
        {
            cout << "Nhap lai loai gia suc: ";
            cin >> loai;
        }
        if (loai == 1)
            NongTrai[i] = new CBo;
        else if (loai == 2)
            NongTrai[i] = new CDe;
        else if (loai == 3)
            NongTrai[i] = new CCuu;
    }
    return NongTrai;
}
int Tong(CGiaSuc **NongTrai, int n, string loai)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (NongTrai[i]->GetLoai() == loai)
            res++;
    }
    return res;
}
int TongCon(CGiaSuc **NongTrai, int n, string loai)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (NongTrai[i]->GetLoai() == loai)
            res += NongTrai[i]->Sinh();
    }
    return res;
}
void Keu(CGiaSuc **NongTrai, int n)
{
    for (int i = 0; i < n; i++)
        NongTrai[i]->Keu(), cout << "\n";
}
int TongSua(CGiaSuc **NongTrai, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res += NongTrai[i]->Sua();
    return res;
}
void Xuat(CGiaSuc **NongTrai, int n)
{
    Keu(NongTrai, n);
    cout << "So luong gia suc trong nong trai truoc khi sinh con la: " << endl;
    cout << "Bo: " << Tong(NongTrai, n, "Bo") << endl;
    cout << "De: " << Tong(NongTrai, n, "De") << endl;
    cout << "Cuu: " << Tong(NongTrai, n, "Cuu") << endl;
    cout << "So luong gia suc trong nong trai sau khi sinh con la: " << endl;
    cout << "Bo: " << Tong(NongTrai, n, "Bo") + TongCon(NongTrai, n, "Bo") << endl;
    cout << "De: " << Tong(NongTrai, n, "De") + TongCon(NongTrai, n, "De") << endl;
    cout << "Cuu: " << Tong(NongTrai, n, "Cuu") + TongCon(NongTrai, n, "Cuu") << endl;
    cout << "Tong so lit sua: " << TongSua(NongTrai, n);
}
int main()
{
    int n;
    CGiaSuc **NongTrai = Nhap(n);
    Xuat(NongTrai, n);
    return 0;
}