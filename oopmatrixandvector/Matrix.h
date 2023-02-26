#pragma once
#include "Vector.h"

class Matrix
{
private:
    int m; // dòng
    int n; // cột
    double **elements; 
public:
    Matrix();
    ~Matrix();
    Matrix(const Matrix & a);
    void Nhap();
    void Xuat();
    int Cong(const Matrix & a); // return 1 nếu cộng được
    void Nhan(const double & k);// Nhân với 1 số K
    int Nhan(const Matrix & a);// Nhân với 1 CMatrix, return 1 nếu nhân được
    friend Vector multiply(const Matrix &a, const Vector &b);
};
