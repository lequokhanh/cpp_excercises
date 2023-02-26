#include <bits/stdc++.h>
#define int long long
#define maxN 1000
using namespace std;
struct fibo {
    int x[2][2];
    fibo(){
        x[0][0] = 0;
        x[0][1] = 1;
        x[1][0] = 1;
        x[1][1] = 1;
    }
};
int n;
fibo operator * (fibo a, fibo b) {
    fibo result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.x[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result.x[i][j] = result.x[i][j] + a.x[i][k] * b.x[k][j];
            }
        }
    }
    return result;
}

fibo powermod (fibo a, long long n) {
    if (n==1) return a;
    if (n % 2 == 1) return powermod(a, n / 2) * powermod(a, n / 2) * a;
    return powermod(a, n / 2) * powermod(a, n / 2);
}
main()
{
    cin >> n;
    fibo a;
    a = powermod (a, n);
    cout << a.x[0][1];
    return 0;
}