#include <bits/stdc++.h>

using namespace std;
int n;
int getbit(int n, int pos) {
    return n & (1 << pos - 1);
}
int main() {
    cin >> n;
    for (int i = 4; i >= 1; i--) {
        if (getbit(n, i) == 0)
            cout << 0;
        else
            cout << 1;
    }
}