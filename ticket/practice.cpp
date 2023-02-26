#include "practice.h"
#include <iostream>
using namespace std;
void practice::input()
{
    ticket::input();
    cout << "Enter the hour of practice: ";
    cin >> hour;
}
long practice::price()
{
    return hour * 1700000;
}
bool practice::isPractice()
{
    return 1;
}
bool practice::isStandard()
{
    return 0;
}
long practice::GetExtraServices()
{
    return 0;
}
void practice::output()
{
    ticket::output();
    cout << "Price: " << price() << endl;
}