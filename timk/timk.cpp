#include <bits/stdc++.h>
#define int int64_t
#define float double_t
#define ft first
#define sd second
#define oo LONG_LONG_MAX
#define elif else if
#define NAME "timk"

using namespace std;
typedef pair<int, int> ii;
map<int, int> am;
void pttsnt (int a, map<int, int> &m) {
    int c = 2;
    while (a != 1) {
        if (a % c == 0) {
            m[c]++;
            a /= c;
        }
        else 
            c++;
    }
}
int calc (int a, int i) {
    int res = 0;
    while (!(a % i)) {
        a /= i;
        res++;
    }
    return res;
}
main() {
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    pttsnt(m, am);
    int res = oo;
    for (auto i : am) {
        int temp = 0;
        int cnt = 1;
        for (int j = i.ft; j <= n; j += i.ft) {
            if (!(cnt++ % i.ft))
                temp += calc(j, i.ft);
            else 
                temp++;
        }
        res = min (res, temp / i.sd);
    }
    cout << res;
    return 0;
}