#include <iostream>
#include "Triangle.h"
#include "Point.h"

using namespace std;

int main() {
    Triangle a;
    a.Input();
    a.Translate(2, 3);
    a.Rotate(34);
    a.Scale(2);
    a.Output();
    return 0;
}