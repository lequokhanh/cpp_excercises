#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string *times = new string[n];
    for (int i = 0; i < n; i++)
        cin >> times[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (times[i] > times[j])
                swap(times[i], times[j]);
    for (int i = 0; i < n; i++)
        cout << times[i] << "\n";
    return 0;
}