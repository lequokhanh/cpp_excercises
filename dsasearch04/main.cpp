#include <iostream>

using namespace std;

struct PhanSo {
    int64_t iTuSo, iMauSo;
};

bool operator== (PhanSo a, PhanSo b) {
    return (long double)a.iTuSo/a.iMauSo == (long double)b.iTuSo/b.iMauSo;
}

bool operator< (PhanSo a, PhanSo b) {
    return (long double)a.iTuSo/a.iMauSo < (long double)b.iTuSo/b.iMauSo;
}

bool operator> (PhanSo a, PhanSo b) {
    return (long double)a.iTuSo/a.iMauSo > (long double)b.iTuSo/b.iMauSo;
}

bool operator>= (PhanSo a, PhanSo b) {
    return a > b || a == b;
}

bool operator<= (PhanSo a, PhanSo b) {
    return a < b || a == b;
}

bool operator!= (PhanSo a, PhanSo b) {
    return !(a == b);
}

istream &operator>>(istream &cin, PhanSo &a) {
    cin >> a.iTuSo >> a.iMauSo;
    return cin;
}

ostream &operator<<(ostream &cout, PhanSo a) {
    cout << a.iTuSo << "/" << a.iMauSo;
    return cout;
}

void OutputSectionSort(PhanSo *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minn = i;
        for (int j = i + 1; j < n; j++)
            if (a[minn] > a[j])
                minn = j;
        swap (a[i], a[minn]);
        cout << "#STEP " << i + 1 << ":\n";
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << endl;
    }
}

void OutputBinarySearch (PhanSo *a, int n, PhanSo x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "[Left=" << left + 1 << ", Mid=" << mid + 1 << ", Right=" << right + 1 << "]\n";
        if (a[mid] < x) 
            left = mid + 1; 
        else
            right = mid - 1;
    }
    if (a[left] == x)
        cout << "Tim thay phan so bang X tai vi tri be nhat la: " << left + 1;
    else
        cout << "Khong tim thay phan so bang X";
}

int main() {
    int n;
    cin >> n;
    PhanSo *a = new PhanSo[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    PhanSo x;
    cin >> x;
    OutputSectionSort(a, n);
    OutputBinarySearch(a, n, x);
    return 0;
}

