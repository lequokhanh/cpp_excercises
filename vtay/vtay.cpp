#include <bits/stdc++.h>

using namespace std;
int n;
main()
{
    cin >> n;
    if ((n / 7) % 2 == 1) {
        cout << n % 7 << "\n" << 7 - n % 7;
    }
    else {
        cout << 7 - n % 7 << "\n" << n % 7;
    }
    return 0;
}