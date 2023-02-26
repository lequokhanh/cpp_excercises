#include "Point.h"
#include <iostream>
#include <math.h>

using namespace std;

Point::Point(int x = 0, int y = 0) : x(x), y(y) {}

void Point::SetX(int x) {
    this->x = x;
}

void Point::SetY(int y) {
    this->y = y;
}

int Point::GetX() {
    return x;
}

int Point::GetY() {
    return y;
}

void Point::Translate(int x, int y) {
    this->x += x;
    this->y += y;
}

void Point::Input() {
    cout << "Nhap hoanh do: ";
    cin >> x;
    cout << "Nhap tung do: ";
    cin >> y;
}

void Point::Output() {
    cout << "Hoanh do la: " << x << "\nTung do la: " << y;
}

float Distance(Point p1, Point p2) {
    return sqrt ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
