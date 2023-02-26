#include"CanBo.h"

void CanBo::Nhap() {
	cout << "\nMoi ban nhap ten can bo: ";
	getline(cin, name);
	cout << "\nNgay sinh can bo: ";
	cin >> birthday;
	cout << "\nMa so can bo: ";
	cin >> MSNS;
}
void CanBo::Xuat() {
	cout << "\n------------Can bo------------" << "\n-->Ho ten: " << name << "\n-->Ngay sinh: " << birthday << "\n-->Ma so nhan su: " << MSNS;
}