#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void Merge(long long *a, long long l, long long m, long long r)
{
    long long sizel = m - l + 1;
    long long sizer = r - m;
    long long *L = new long long[sizel];
    long long *R = new long long[sizer];
    for (long long i = 0; i < sizel; i++)
        L[i] = a[l + i];
    for (long long i = 0; i < sizer; i++)
        R[i] = a[m + i + 1];
    long long pos = l;
    for (long long i = 0, j = 0; i < sizel || j < sizer;)
    {
        if (i == sizel)
            while (j < sizer)
                a[pos++] = R[j++];
        else if (j == sizer)
            while (i < sizel)
                a[pos++] = L[i++];
        while (i < sizel && L[i] >= R[j])
            a[pos++] = L[i++];
        while (j < sizer && R[j] >= L[i])
            a[pos++] = R[j++];
    }
    delete[] L;
    delete[] R;
}
void MergeSort(long long *a, long long l, long long r, vector<vector<long long>> &v, long long k)
{
    v[k].push_back(l);
    v[k].push_back(r);
    if (l == r)
    {
        v[k + 1].push_back(l);
        v[k + 1].push_back(r);
    }
    if (l < r)
    {
        long long m = l + (r - l) / 2;
        MergeSort(a, l, m, v, k + 1);
        MergeSort(a, m + 1, r, v, k + 1);
    }
}
void OutputArray(long long *a, long long l, long long r)
{
    cout << "[";
    for (long long i = l; i <= r; i++)
    {
        cout << a[i];
        if (i != r)
            cout << ",";
    }
    cout << "]";
}

int LamTron(float x)
{
    int y = (int)x;
    if (x - y > 0)
        return y + 1;
    else
        return y;
}

int main()
{
    long long n;
    freopen("output.txt", "w", stdout);
    cin >> n;
    long long *a = new long long[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<long long>> v(n);
    MergeSort(a, 0, n - 1, v, 0);
    v[LamTron(log2(n)) + 1].clear();
    long long k = 1;
    for (long long i = 1; i <= LamTron(log2(n)); i++)
    {
        cout << "k=" << k++ << endl;
        cout << "[";
        for (long long j = 0; j < v[i].size(); j += 2)
        {
            OutputArray(a, v[i][j], v[i][j + 1]);
            if (j != v[i].size() - 2)
                cout << ",";
        }
        cout << "]" << endl;
    }
    for (long long i = LamTron(log2(n)) - 1; i >= 0; i--)
    {
        cout << "k=" << k++ << endl;
        cout << "[";
        for (long long j = 0; j < v[i].size(); j += 2)
        {
            Merge(a, v[i][j], v[i][j] + (v[i][j + 1] - v[i][j]) / 2, v[i][j + 1]);
            OutputArray(a, v[i][j], v[i][j + 1]);
            if (j != v[i].size() - 2)
                cout << ",";
        }
        cout << "]" << endl;
    }
    delete[] a;
    return 0;
}