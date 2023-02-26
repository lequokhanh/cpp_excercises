#include "standard.h"

void standard::input()
{
    ticket::input();
    cout << "Enter the number of extra service: ";
    cin >> services;
}
long standard::GetExtraServices()
{
    return services;
}
long standard::price()
{
    return 1800000 + services * 600000;
}
bool standard::isPractice()
{
    return 0;
}
bool standard::isStandard()
{
    return 1;
}
void standard::output()
{
    ticket::output();
    cout << "Price: " << price() << endl;
}