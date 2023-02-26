#pragma once
#include "Matrix.h"

class Vector
{
private:
    double *coords;
    int n;
public:
    Vector();
    Vector(int N, double x); // tạo vector có N chiều, mỗi ô có giá trị x
    Vector(const Vector &a);
    ~Vector();
    void Nhap();
    void Xuat();
    int Cong(const Vector &a); // return 1 nếu cộng được
    void NhanK(const double &k);
    int Tru(Vector a); // return 1 nếu trừ được
    double TichVoHuong(const Vector &a);
    friend Vector multiply(const Matrix &a, const Vector &b);
};
