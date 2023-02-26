#include <iostream>
#define MAXN 150000

using namespace std;
void NhapMang(int A[], int &N)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
}

void Heapify(int *a, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        Heapify(a, largest, n);
    }
}

void BuildHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, i, n);
}

void HeapSort(int a[], int n)
{
    BuildHeap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, 0, i);
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    HeapSort(a, n);

    XuatMang(a, n);

    return 0;
}