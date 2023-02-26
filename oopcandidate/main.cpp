#include <iostream>
#include <string>
#include "Candidate.h"

using namespace std;  
Candidate* input(int &n) {
    cin >> n;
    Candidate *a = new Candidate[n];
    for (int i = 0; i < n; i++) {
        a[i].input(i + 1);
    }
    return a;
}

void output(int n, Candidate *a) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].tinhTong() >= 15) {
            a[i].output();
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "Khong co thi sinh co tong diem lon hon 15" << endl;
    }
}

int main() {
    int n;
    Candidate *a = input(n);  
    output(n, a);
    return 0;
}