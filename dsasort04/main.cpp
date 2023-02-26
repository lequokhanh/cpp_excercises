#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void Heapify(long long *a, long long i, long long n, vector<pair<long long, long long>> &v)
{
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;
    long long lowest = i;
    if (l < n && a[l] < a[lowest])
        lowest = l;
    if (r < n && a[r] < a[lowest])
        lowest = r;
    if (lowest != i)
    {
        v.push_back(make_pair(i, lowest));
        swap(a[i], a[lowest]);
        Heapify(a, lowest, n, v);
    }
}
void Heapify(long long *a, long long i, long long n)
{
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;
    long long lowest = i;
    if (l < n && a[l] < a[lowest])
        lowest = l;
    if (r < n && a[r] < a[lowest])
        lowest = r;
    if (lowest != i)
    {
        swap(a[i], a[lowest]);
        Heapify(a, lowest, n);
    }
}

void BuildHeap(long long a[], long long n, vector<pair<long long, long long>> &v)
{
    for (long long i = n / 2 - 1; i >= 0; i--)
        Heapify(a, i, n, v);
}

void HeapSort(long long a[], long long n, vector<pair<long long, long long>> &v)
{
    BuildHeap(a, n, v);
    for (long long i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, 0, i);
    }
}

int main()
{
    vector<pair<long long, long long>> v;
    long long n;
    cin >> n;
    if (n > 0)
    {
        long long *a = new long long[n];
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        cout << "Day truoc khi sap xep: ";
        for (long long i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        HeapSort(a, n, v);
        cout << "Day sau khi sap xep: ";
        for (long long i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "Cac hoan vi duoc thuc hien trong heap: \n";
        for (long long i = 0; i < v.size(); i++)
            cout << v[i].first << " " << v[i].second << endl;
        return 0;
    }
}