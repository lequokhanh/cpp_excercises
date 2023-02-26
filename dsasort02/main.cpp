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
        for (int i = 1; i < n; i++)
        {
            int j = i;
            while (j > 0 && a[j - 1] < a[j])
            {
                swap(a[j], a[j - 1]);
                j--;
            }
            cout << "Vi tri chen cua a[" << i << "] la " << j << endl;
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