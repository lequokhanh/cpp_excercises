#include "Point.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    Point *a = new Point[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap diem " << i << " :\n";
        a[i].Input();
    }
    for (int i = 0; i < n; i++) {
        cout << "Diem " << i << " :\n";
        a[i].Output();
    }
    float minDis = Distance(a[0], a[1]), maxDis = Distance(a[0], a[1]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            minDis = min(minDis, Distance(a[i], a[j]));
            maxDis = max(maxDis, Distance(a[i], a[j]));
        }
    }
    int v1, v2;
    cin >> v1 >> v2;
    for (int i = 0; i < n; i++) {
        a[i].Translate(v1, v2);
        a[i].Output();
    }
    return 0;
}