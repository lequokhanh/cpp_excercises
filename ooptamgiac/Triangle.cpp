#include "Triangle.h"
#include <iostream>
#include <math.h>
using namespace std;

Triangle::Triangle() {}

Triangle::Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {}

void Triangle::Input () {
    "Diem a:\n";
    a.Input();
    cout << "Diem b:\n";
    b.Input();
    cout << "Diem c:\n";
    c.Input();
}

void Triangle::Output() {
    cout << "Diem a:\n";
    a.Output();
    cout << "Diem b:\n";
    b.Output();
    cout << "Diem c:\n";
    c.Output();
}

void Triangle::Translate (int x, int y) {
    a.Translate(x, y);
    b.Translate(x, y);
    c.Translate(x, y);
}

void Triangle::Rotate (float d) {
    a.Rotate(d);
    b.Rotate(d);
    c.Rotate(d);
}

void Triangle::Scale (float k) {
    a = Point(a.GetX() * k, a.GetY() * k);
    b = Point(b.GetX() * k, b.GetY() * k);
    c = Point(c.GetX() * k, c.GetY() * k);
}

