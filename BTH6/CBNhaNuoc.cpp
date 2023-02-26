#include "CBNhaNuoc.h"
#include <iostream>

using namespace std;

void CBNhaNuoc::Nhap()
{
	CanBo::Nhap();
	cout << "\nNhap luong co ban: ";
	cin >> LuongCoBan;
	cout << "\nNhap he so luong: ";
	cin >> HeSoLuong;
	cout << "\nNhap he so phu cap";
	cin >> HeSoPhuCap;
}
double CBNhaNuoc::luong()
{
	return salary = LuongCoBan * HeSoLuong * HeSoPhuCap;
}
void CBNhaNuoc::Xuat()
{
	CanBo::Xuat();
	cout << "\n-->Kieu can bo: Bien che";
	cout << "\n-->Luong: " << salary;
}