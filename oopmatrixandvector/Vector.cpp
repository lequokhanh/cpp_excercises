#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector() {}

Vector::Vector(int N, double x) {
    n = N;
    coords = new double[n];
    for (int i = 0; i < n; i++) {
        coords[i] = x;
    }
}

Vector::Vector(const Vector &a) {
    n = a.n;
    coords = new double[n];
    for (int i = 0; i < n; i++) 
        coords[i] = a.coords[i];
}

Vector::~Vector() {
    if (coords != NULL)
        delete []coords;
}

void Vector::Nhap() {
    cout << "Nhap chieu dai vector: ";
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> coords[i];
}

void Vector::Xuat() {
    for (int i = 0; i < n; i++)
        cout << coords[i] << " "; 
}

int Vector::Cong(const Vector &a) {
    if (n == a.n) {
        for (int i = 0; i < n; i++) 
            coords[]
    }
}

void Vector::NhanK(const double &k) {

}

int Vector::Tru(Vector a) {

}

double Vector::TichVoHuong(const Vector &a) {

}

Vector multiply(const Matrix &a, const Vector &b) {

}