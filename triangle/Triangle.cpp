#include<math.h>
#include"Point.cpp"

using namespace std;

class Triangle{
private:
    Point vertice1;
    Point vertice2;
    Point vertice3;
public:
    Triangle(Point vertice1, Point vertice2, Point vertice3): vertice1(vertice1), vertice2(vertice2), vertice3(vertice3) {}
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3): vertice1(Point(x1, y1)), vertice2(Point(x2, y2)), vertice3(Point(x3, y3)) {}
    double getPerimeter(){ 
        double d1 = sqrt((vertice1.getX() - vertice2.getX()) * (vertice1.getX() - vertice2.getX()) + (vertice1.getY() - vertice2.getY()) * (vertice1.getY() - vertice2.getY()));
        double d2 = sqrt((vertice3.getX() - vertice1.getX()) * (vertice3.getX() - vertice1.getX()) + (vertice3.getY() - vertice1.getY()) * (vertice3.getY() - vertice1.getY()));
        double d3 = sqrt((vertice2.getX() - vertice3.getX()) * (vertice2.getX() - vertice3.getX()) + (vertice2.getY() - vertice3.getY()) * (vertice2.getY() - vertice3.getY()));
        return d1 + d2 + d3;
    }
};