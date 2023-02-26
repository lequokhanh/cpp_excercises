#include <bits/stdc++.h>

using namespace std;
int n, a;
main()
{
    cin >> n; //29
    while (n / 10) { // 11
        while (n) { // 11
            a = a + n % 10; // a = 2
            n = n / 10; // 0
        }
        n = a;// 2
        a = 0;//
    }
    cout << n << endl;
    return 0;
}