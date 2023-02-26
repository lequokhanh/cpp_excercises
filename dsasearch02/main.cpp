#include <iostream>

using namespace std;

int lower_bound(int *a, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int upper_bound(int *a, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int n, t;
    cin >> n >> t;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (t--) {
        int x;
        cin >> x;
        int begin = lower_bound(a, n, x);
        int end = upper_bound(a, n, x);
        if (end - begin > 0) {
            cout << end - begin << " " << begin + 1 << " " << end << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

