#include<iostream>
#include "Point.cpp"
#include "Triangle.cpp"

using namespace std;

int main() {
	Point vertice1(1, 3);
	Point vertice2(2, 3);
	Point vertice3(4, 2);
	Triangle triangle1(vertice1, vertice2, vertice3);
	Triangle triangle2(4, 5, 2, 6, 3, 7);
	cout << triangle1.getPerimeter() << endl;
	cout << triangle2.getPerimeter() << endl;
	return 0;
}