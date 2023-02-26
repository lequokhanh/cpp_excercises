#include <bits/stdc++.h>

using namespace std;
int n, a[1000000];
main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                a[i] = a[j] + a[i];
                a[j] = a[i] - a[j];
                a[i] = a[i] - a[j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}