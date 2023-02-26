#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix() {}

Matrix::~Matrix() {
    if (elements != NULL) {
        for (int i = 0; i < n; i++) {
            delete []elements[i];
        }
        delete []elements;
    }
}

Matrix::Matrix(const Matrix & a) {
    int m = a.m;
    int n = a.n;
    elements = new double *[m];
    for (int i = 0; i < m; i++) {
        elements[i] = new double[n];
        for (int j = 0; j < n; j++)
            elements[i][j] = a.elements[i][j];
    }
}

void Matrix::Nhap() {
    cout << "Nhap dong: ";
    cin >> m;
    cout << "Nhap cot: ";
    cout << n;
    elements = new double *[m];
    for (int i = 0; i < m; i++) {
        *(elements + i) = new double [n];
        for (int j = 0; j < n; j++)
            cin >> *(*(elements + i) + j);
    }
}

void Matrix::Xuat() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            cout << elements[i][j] << " ";
        cout << endl;
    }
}

int Matrix::Cong(const Matrix & a) {
    if (n == a.n && m == a.m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                elements[i][j] += a.elements[i][j];
            }
        }
        return 1;
    }
    return 0;
}

void Matrix::Nhan(const double & k) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            elements[i][j] *= k;
}

int Matrix::Nhan(const Matrix & a) {
    
}
