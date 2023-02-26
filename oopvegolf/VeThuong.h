#include "Ve.h"
#include <iostream>

using namespace std;

class VeThuong : public Ve
{
private:
    int iSoDichVu;

public:
    void Nhap();
    void Xuat();
    int loai();
    int tinhTien();
    int GetSoDichVu();
};