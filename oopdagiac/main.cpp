#include "Polygon.h"
#include <iostream>

using namespace std;

int main() {
    Polygon a;
    a.Input();
    Polygon b;
    b = a;
    cout << "Da giac a la:\n";
    a.Output();
    cout << "\nDa giac b la:\n";
    b.Output();
    return 0;
}