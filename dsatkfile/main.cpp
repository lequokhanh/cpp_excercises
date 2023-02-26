#include <iostream>
#include <algorithm>
using namespace std;

int Search (string *s, int n, string x) {
    for (int i = 0; i < n; i++) 
        if (s[i] == x)
            return i;
    return -1;
}

int main() {
    int n;
    cin >> n;
    string *s = new string[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    string x;
    cin >> x;
    cout << Search(s, n, x);
    return 0;
}