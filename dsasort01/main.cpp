#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n <= 0)
    {
        cout << "Mang rong.";
    }
    else
    {
        cout << "Mang truoc khi sap xep la: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < n - 1; i++)
        {
            int mx = i;
            for (int j = i + 1; j < n; j++)
                if (a[mx] < a[j])
                    mx = j;
            cout << "i=" << i << ":" << endl;
            cout << "Max = a[" << mx << "] = " << a[mx] << endl;
            swap(a[i], a[mx]);
            cout << "Mang sau khi sap xep " << i + 1 << " phan tu dau tien la: ";
            for (int j = 0; j < n; j++)
                cout << a[j] << " ";
            cout << endl;
        }
        cout << "Mang sau khi sap xep la: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}