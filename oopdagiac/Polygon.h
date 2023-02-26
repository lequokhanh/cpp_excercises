#include "Point.h"
#pragma once

class Polygon {
    private:
        Point *points;
        int iSize;
    public:
        Polygon();
        Polygon(int);
        Polygon(const Polygon&);
        Polygon(Point*, int);
        ~Polygon();
        void Input();
        void Output();
        void Translate(int ,int);
        void Rotate(float);
        void Scale(float);
        void operator= (const Polygon&);
};