#include "golf.h"
#include "vip.h"
#include "standard.h"
#include "practice.h"
#include "math.h"
#include <iomanip>
golf::golf()
{
    cout << "Enter number of the ticket: ";
    cin >> n;
    a = new ticket *[n];
}
void golf::input()
{
    for (int i = 0; i < n; i++)
    {
        int j;
        cout << "Enter type of ticket(1:VIP ticket, 2:Standard ticket, 3:Practice ticket): ";
        cin >> j;
        if (j == 1)
        {
            a[i] = new vip;
            a[i]->input();
        }
        else if (j == 2)
        {
            a[i] = new standard;
            a[i]->input();
        }
        else if (j == 3)
        {
            a[i] = new practice;
            a[i]->input();
        }
        else
        {
            cout << "Wrong input!" << endl;
            exit(1);
        }
    }
}
void golf::output()
{
    long max = -9999;
    long total = 0;
    float served = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]->isStandard() == 1 && a[i]->price() > max)
        {
            max = a[i]->price();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]->isPractice())
            total += a[i]->price();
        if (a[i]->isStandard())
        {
            served += a[i]->GetExtraServices();
            count++;
        }
    }
    if (n)
    {
        cout << "Money from selling practice ticket: " << total << endl;
        cout << "People who bought standard ticket usually have " << setprecision(2) << served / count << " extra services." << endl;
        cout << "The most expensive standard ticket is :" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]->price() == max && a[i]->isStandard())
        {
            a[i]->output();
            break;
        }
    }
}