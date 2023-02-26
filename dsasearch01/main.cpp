#include <iostream>

using namespace std;

int BinarySearch (int *a, int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x)
            r = mid;
        else 
            l = mid + 1;
    }
    if (a[l] == x)
        return l;
    return -1;
}    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, t;
    cin >> n >> t;
    long long *a = new long long[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    while (t--) {
        long long x;
        cin >> x;
        long long pos = BinarySearch(a, n, x);
        cout << n - pos << endl;
    }
    return 0;
}
}