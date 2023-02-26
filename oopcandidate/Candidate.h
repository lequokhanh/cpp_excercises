#pragma once
#include <iostream>
#include <string>

using namespace std;
class Candidate {
private:
    int iSTT;
    string sMa, sHoTen, sNgaySinh;
    int iDiemToan, iDiemVan, iDiemAnh; 
public:
    void input(int iSTT);
    int tinhTong();
    void output();
};