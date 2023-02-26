#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main() {
    SoPhuc a, b;
    int c = 5;
    cin >> a >> b;
    cout << "Cong: " << a + b << endl;
    cout << "Tru: " << a - b << endl;
    cout << "Nhan: " << a * b << endl;
    cout << "Chia: " << a / b << endl;
    return 0;
}