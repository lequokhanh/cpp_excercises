#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket{
    private:
        int games, price_ticket, price_game;
        string date;
    public:
        Ticket();
        Ticket(int, int, int, string);
        void Input();
        void Output();
        int getPriceTicket();
        int getPriceGame();
        int getGames();
};