#include <iostream>
#include <string>
#include "Ticket.h"
using namespace std;

int CalcTotalTickets(Ticket *t, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += t[i].getPriceTicket() + t[i].getPriceGame() * t[i].getGames();
    }
    return total;
}

Ticket *Input (int &n) {
    cout << "Nhap so ve: ";
    cin >> n;
    Ticket *t = new Ticket[n];
    for (int i = 0; i < n; i++) {
        cout << "---\nVe thu " << i + 1 << endl;
        t[i].Input();
    }
    return t;
}

int main() {
    int n;
    Ticket *t = Input(n);
    cout << "Tong tien ve: " << CalcTotalTickets(t, n);
    return 0;
}