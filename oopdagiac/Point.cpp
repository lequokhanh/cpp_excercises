#include "Point.h"
#include <iostream>
#include <math.h>

using namespace std;

Point::Point() {}

Point::Point(int x, int y) : x(x), y(y) {}

void Point::SetX(int x)
{
    this->x = x;
}

void Point::SetY(int y)
{
    this->y = y;
}

int Point::GetX()
{
    return x;
}

int Point::GetY()
{
    return y;
}

void Point::Translate(int x, int y)
{
    this->x += x;
    this->y += y;
}

void Point::Rotate(float d)
{
    float r = d * 3.14 / 180;
    int tempX = this->x, tempY = this->y;
    this->x = tempX * cos(r) - tempY * sin(r);
    this->y = tempX * sin(r) - tempY * cos(r);
}

void Point::Input()
{
    cout << "X = ";
    cin >> x;
    cout << "Y = ";
    cin >> y;
}

void Point::Output()
{
    cout << "(" << x << "," << y << ")";
}
