#include "PhanSo.h"

using namespace std;

int main()
{
    PhanSo a, b;
    cin >> a >> b;
    // cout << sqrt(a) << endl;
    // b(a);
    cout << "Cong: " << a + 1 << endl;
    cout << "Tru: " << a - b << endl;
    cout << "Nhan: " << a * b << endl;
    cout << "Chia: " << a / b;
    int c = 5;
    int d(c);
    cout << d;
    return 0;
}