#include "SoPhuc.h"
#include <iostream>
#include <cmath>

using namespace std;

SoPhuc::SoPhuc(float fThuc, float fAo): fThuc(fThuc), fAo(fAo) {}

// SoPhuc::SoPhuc(int iThuc): fThuc(float(iThuc)) {}

istream &operator>>(istream& cin, SoPhuc& a) {
    cin >> a.fThuc >> a.fAo;
    return cin;
}
ostream &operator<<(ostream& cout, const SoPhuc& a) {
    if (a.fAo == 0)
        cout << a.fThuc;
    else if (a.fAo == 1)
        cout << a.fThuc << " + i";
    else if (a.fAo == -1)
        cout << a.fThuc << " - i";
    else if (a.fAo > 0)
        cout << a.fThuc << " + " << a.fAo << "i";
    else
        cout << a.fThuc << " - " << abs(a.fAo) << "i";
    return cout;
}

SoPhuc operator+ (SoPhuc a, SoPhuc b) {
    return {a.fThuc + b.fThuc, a.fAo + b.fAo};
}
SoPhuc operator- (SoPhuc a, SoPhuc b) {
    return {a.fThuc - b.fThuc, a.fAo - b.fAo};
}
SoPhuc operator* (SoPhuc a, SoPhuc b) {
    return {a.fThuc * b.fThuc - a.fAo * b.fAo, a.fThuc * b.fThuc + a.fAo * b.fAo};
}
SoPhuc operator/ (SoPhuc a, SoPhuc b) {
    return {(a.fThuc * b.fThuc + a.fAo * b.fAo) / (b.fThuc * b.fThuc + b.fAo * b.fAo), (a.fAo * b.fThuc - a.fThuc * b.fAo) / (b.fThuc * b.fThuc + b.fAo * b.fAo)};
}

float abs (SoPhuc a) {
    return sqrt(a.fThuc * a.fThuc + a.fAo * a.fAo);
}
