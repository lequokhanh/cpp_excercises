#pragma once
#include <vector>
#include <stack>
#include <math.h>
#include "Point.cpp"

using namespace std;

class PolyLine{
private:
    vector<Point> points;
public:
    PolyLine(){}

    PolyLine(vector<Point> points): points(points) {}

    void appendPoint(Point point){
        points.push_back(point);
    }

    void appendPoint(int x, int y){
        points.push_back(Point(x,y));
    }

    double getLength(){
        stack<Point> st;
        double res = 0;
        for(Point point : points){
            if(st.empty())
                st.push(point);
            else{
                int x1 = st.top().getX();
                int y1 = st.top().getY();
                int x2 = point.getX();
                int y2 = point.getY();
                res += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            }
        }
        return res;
    }
};