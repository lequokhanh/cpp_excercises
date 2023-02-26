#include "CBHopDong.h"

void CBHopDong::Nhap()
{
	CanBo::Nhap();
	cout << "\nNhap tien cong: ";
	cin >> TienCong;
	cout << "\nNhap so ngay cong: ";
	cin >> SoNgayCong;
	cout << "\nNhap he so vuot gio: ";
	cin >> HeSoVuotGio;
}
double CBHopDong::luong()
{
	return salary = TienCong * SoNgayCong * HeSoVuotGio;
}
void CBHopDong::Xuat()
{
	CanBo::Xuat();
	cout << "\n-->Can bo thuoc loai: Hop dong";
	cout << "\n-->Luong: " << salary;
}