#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void QuickSort(long long a[], long long left, long long right, vector<pair<long long, long long>> &v)
{
    long long i, j, x;
    x = a[(left + right) / 2];
    i = left;
    j = right;
    while (i <= j)
    {
        while (a[i] > x)
            i++;
        while (a[j] < x)
            j--;
        if (i <= j)
        {
            if (i != j)
                v.push_back(make_pair(i, j));
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(a, left, j, v);
    if (i < right)
        QuickSort(a, i, right, v);
}
int main()
{
    vector<pair<long long, long long>> v;
    long long n;
    cin >> n;
    long long *a = new long long[n];
    long long *b = new long long[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i];
    cout << "Day truoc khi sap xep: ";
    for (long long i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    QuickSort(a, 0, n - 1, v);
    cout << "Day sau khi sap xep: ";
    for (long long i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Cac hoan vi duoc thuc hien trong Quick Sort:\n";
    for (long long i = 0; i < v.size(); i++)
        cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
    return 0;
}