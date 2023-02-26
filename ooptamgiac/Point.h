#pragma once
class Point {
    private:
        int x, y;
    public:
        Point();
        Point(int, int);
        void SetX(int);
        void SetY(int);
        int GetX();
        int GetY();
        void Translate(int, int);
        void Rotate(float);
        void Input();
        void Output();
};