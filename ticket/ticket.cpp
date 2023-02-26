#include "ticket.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void ticket::input()
{
    cin.ignore();
    cout << "Enter ticket's id: ";
    getline(cin, id);
    cout << "Enter the name of ticket owner: ";
    getline(cin, name);
    cout << "Enter the year of owner's birth: ";
    getline(cin, namsinh);
}
void ticket::output()
{
    cout << "Ticket's id: " << id << endl;
    cout << "Ticket's name: " << name << endl;
    cout << "Ticket's year of birth: " << namsinh << endl;
}