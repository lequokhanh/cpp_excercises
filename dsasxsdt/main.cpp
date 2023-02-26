#include <iostream>

using namespace std;

int compare(const char *a, const char *b, int i)
{
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return -1;
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0')
        return 0;
    else if (a[i] == '\0')
        return -1;
    else
        return 1;
}

int Partition(char **a, int low, int high)
{
    char *pivot = a[(high + low) / 2];
    int l = low, r = high;
    while (true)
    {
        while (l <= r && compare(*(a + l), pivot, 3) < 0)
            l++;
        while (l <= r && compare(*(a + r), pivot, 3) > 0)
            r--;
        if (l > r)
            break;
        swap(a[l], a[r]);
        l++;
        r--;
    }
    return l;
}

void QuickSort(char **a, int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(a, low, high);
        QuickSort(a, low, pivot - 1);
        QuickSort(a, pivot, high);
    }
}
int main()
{
    char **ds = new char *[9999999];
    int n = 0;
    while (true)
    {
        ds[n] = new char[10];
        cin >> ds[n];
        if (compare(ds[n], "0", 0) == 0)
            break;
        else
            n++;
    }
    QuickSort(ds, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << ds[i] << endl;
    return 0;
}