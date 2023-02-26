#include "Polygon.h"
#include <iostream>
#include <math.h>
using namespace std;

Polygon::Polygon() {}

Polygon::Polygon(int iSize) : iSize(iSize)
{
    points = new Point[iSize];
}

Polygon::Polygon(const Polygon &x)
{
    iSize = x.iSize;
    points = new Point[iSize];

    for (int i = 0; i < iSize; i++)
        points[i] = x.points[i];
}

Polygon::~Polygon()
{
    if (points != NULL)
        delete[] points;
}

Polygon::Polygon(Point *points, int iSize)
{
    this->iSize = iSize;
    this->points = new Point[iSize];

    for (int i = 0; i < iSize; i++)
        this->points[i] = points[i];
}

void Polygon::Input()
{
    do
    {
        cin >> iSize;
    } while (iSize < 3);
    points = new Point[iSize];
    for (int i = 0; i < iSize; i++)
    {
        cout << "Dinh " << i + 1 << endl;
        points[i].Input();
    }
}

void Polygon::Output()
{
    cout << "{";
    for (int i = 0; i < iSize; i++)
    {
        points[i].Output();
        if (i + 1 != iSize)
            cout << ",";
    }
    cout << "}";
}

void Polygon::Translate(int x, int y)
{
    for (int i = 0; i < iSize; i++)
        points[i].Translate(x, y);
}

void Polygon::Rotate(float d)
{
    for (int i = 0; i < iSize; i++)
        points[i].Rotate(d);
}

void Polygon::Scale(float k)
{
    for (int i = 0; i < iSize; i++)
        points[i] = Point(points[i].GetX() * k, points[i].GetY() * k);
}

void Polygon::operator=(const Polygon &x)
{
    iSize = x.iSize;
    points = new Point[iSize];

    for (int i = 0; i < iSize; i++)
        points[i] = x.points[i];
}
