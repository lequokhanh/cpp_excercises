#include "Ve.h"

void Ve::Nhap()
{
    cout << "Nhap ma ve: ";
    cin >> sMaVe;
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, sTen);
    cout << "Nhap nam sinh: ";
    cin >> iNamSinh;
    cout << "Nhap so tro choi: ";
    cin >> iSoTroChoi;
}

void Ve::Xuat()
{
    cout << "Ma ve: " << sMaVe << "\n";
    cout << "Ten: " << sTen << "\n";
    cout << "Nam sinh: " << iNamSinh << "\n";
    cout << "So tro choi: " << iSoTroChoi << "\n";
}