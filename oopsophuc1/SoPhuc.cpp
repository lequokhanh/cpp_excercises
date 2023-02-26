#include <iostream>
#include <cmath>
#include "SoPhuc.h"

using namespace std;

SoPhuc::SoPhuc() {}

SoPhuc::SoPhuc(float fThuc, float fAo): fThuc(fThuc), fAo(fAo) {}

void SoPhuc::Nhap () {
    cin >> fThuc >> fAo;
}
void SoPhuc::Xuat () {
    if (fAo == 0)
        cout << fThuc;
    else if (fAo == 1)
        cout << fThuc << " + i";
    else if (fAo == -1)
        cout << fThuc << " - i";
    else if (fAo > 0)
        cout << fThuc << " + " << fAo << "i";
    else
        cout << fThuc << " - " << abs(fAo) << "i";
}

SoPhuc SoPhuc::Cong (SoPhuc x) {
    return {fThuc + x.fThuc, fAo + x.fAo};
}
SoPhuc SoPhuc::Tru (SoPhuc x) {
    return {fThuc - x.fThuc, fAo - x.fAo};
}
SoPhuc SoPhuc::Nhan (SoPhuc x) {
    return {fThuc * x.fThuc - fAo * x.fAo, fThuc * x.fThuc + fAo * x.fAo};
}
SoPhuc SoPhuc::Chia (SoPhuc x) {
    return {(fThuc * x.fThuc + fAo * x.fAo) / (x.fThuc * x.fThuc + x.fAo * x.fAo), (fAo * x.fThuc - fThuc * x.fAo) / (x.fThuc * x.fThuc + x.fAo * x.fAo)};
}

float SoPhuc::gttd() {
    return sqrt(fThuc * fThuc + fAo * fAo);
}
