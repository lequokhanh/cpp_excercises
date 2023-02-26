#include <iostream>
#include <stack>
using namespace std;

void QuickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pivot = a[(high + low) / 2];
        int l = low, r = high;
        while (true)
        {
            while (l <= r && a[l] < pivot)
                l++;
            while (l <= r && a[r] > pivot)
                r--;
            if (l > r)
                break;
            swap(a[l], a[r]);
            l++;
            r--;
        }
        QuickSort(a, low, r);
        QuickSort(a, l, high);
    }
}
// void QuickSortNonRecursive(int *a, int l, int r)
// {
//     stack<int> s;
//     s.push(l);
//     s.push(r);
//     while (!s.empty())
//     {
//         r = s.top();
//         s.pop();
//         l = s.top();
//         s.pop();
//         int mid = Partition(a, l, r);
//         if (mid - 1 > l)
//         {
//             s.push(l);
//             s.push(mid - 1);
//         }

//         if (mid + 1 < r)
//         {
//             s.push(mid + 1);
//             s.push(r);
//         }
//     }
// }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << "\n";
    return 0;
}