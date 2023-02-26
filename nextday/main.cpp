#include <iostream>

using namespace std;

struct Date
{
    int day, month, year;
};

Date NextDay(Date d) 
{
    int day[] = {31, (!(d.year % 400) || (!(d.year % 4) && (d.year % 100))) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    d.day++;
    if (d.day > day[d.month - 1]) 
    {
        d.day = 1;
        d.month++;
        if (d.month > 12) 
        {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

void Nhap (Date &d) 
{
    cout << "Nhap ngay: ";
    cin >> d.day;
    cout << "Nhap thang: ";
    cin >> d.month;
    cout << "Nhap nam: ";
    cin >> d.year;
}

void Xuat (Date d) 
{
    cout << d.day << "/" << d.month << "/" << d.year << endl;
}

int main() {
    Date d;
    Nhap(d);
    Xuat(NextDay(d));
    return 0;
}