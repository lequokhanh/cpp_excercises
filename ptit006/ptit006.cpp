#include <bits/stdc++.h>
using namespace std;
int n,a[1003][1003];
int main()
{
    cin>>n;
    int stage = 1, val = 1, col = n, row = n;
    while (stage <= (n+1)/2) {
        for (int i = stage; i <= col; i++) {
            a[stage][i] = val++;
        }
        for (int i = stage + 1; i <= row; i++) {
            a[col][i] = val++;
        }
        for (int i = col - 1; i >= stage; i--) {
            a[row][i] = val++;
        }
        for (int i = row - 1; i > stage; i--) {
            a[i][stage] = val++;
        }
        stage++, row--, col--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
