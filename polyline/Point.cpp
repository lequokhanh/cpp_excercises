#pragma once

class Point {
private:
    int x, y;
public:
    Point(){}
    Point(int x, int y):x(x), y(y) {}
    void setX(int x) {
        this->x = x;
    }        
    void setY(int y) {
        this->y = y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};