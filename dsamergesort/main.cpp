#include <iostream>

using namespace std;

void Merge(int *a, int l, int m, int r)
{
    int sizel = m - l + 1;
    int sizer = r - m;
    int *L = new int[sizel];
    int *R = new int[sizer];
    for (int i = 0; i < sizel; i++)
        L[i] = a[l + i];
    for (int i = 0; i < sizer; i++)
        R[i] = a[m + i + 1];
    int pos = l;
    for (int i = 0, j = 0; i < sizel || j < sizer;)
    {
        if (i == sizel)
            while (j < sizer)
                a[pos++] = R[j++];
        else if (j == sizer)
            while (i < sizel)
                a[pos++] = L[i++];
        while (i < sizel && L[i] <= R[j])
            a[pos++] = L[i++];
        while (j < sizer && R[j] <= L[i])
            a[pos++] = R[j++];
    }
    delete[] L;
    delete[] R;
}

void MergeSortNonRecursive(int *a, int n)
{
    for (int i = 1; i < n; i *= 2)
    {
        for (int l = 0; l < n; l += 2 * i)
        {
            int m = min(l + i - 1, n - 1);
            int r = min(l + 2 * i - 1, n - 1);
            Merge(a, l, m, r);
        }
    }
}

void MergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}