#pragma once
#include "Point.h"

class Triangle {
    private:
        Point a, b, c;
    public:
        Triangle();
        Triangle(Point a, Point b, Point c);
        void Input();
        void Output();
        void Translate(int ,int);
        void Rotate(float);
        void Scale(float);
};