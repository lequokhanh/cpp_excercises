#pragma once
class Point {
    private:
        int x, y;
    public:
        Point(int = 0, int = 0);
        void SetX(int);
        void SetY(int);
        int GetX();
        int GetY();
        void Translate(int, int);
        void Input();
        void Output();
        friend float Distance(Point, Point);
};