#include "Ticket.h"

using namespace std;

Ticket::Ticket() {} 
Ticket::Ticket(int price_ticket, int price_game, int games, string date): price_ticket(price_ticket), price_game(price_game), games(games), date(date){}

void Ticket::Input() {
    cout << "Nhap gia ve: ";
    cin >> price_ticket;
    cout << "Nhap gia game: ";
    cin >> price_game;
    cout << "Nhap so game: ";
    cin >> games;
    cout << "Nhap ngay: ";
    cin >> date;
}

void Ticket::Output() {
    cout << "Gia ve: " << price_ticket << endl;
    cout << "Gia game: " << price_game << endl;
    cout << "So game: " << games << endl;
    cout << "Ngay: " << date << endl;
}

int Ticket::getPriceTicket() {
    return price_ticket;
}

int Ticket::getPriceGame() {
    return price_game;
}

int Ticket::getGames() {
    return games;
}