#include "Ve.h"
#include <iostream>

using namespace std;

class VeTap : public Ve
{
private:
    int iSoGioTap;

public:
    void Nhap();
    void Xuat();
    int loai();
    int tinhTien();
};