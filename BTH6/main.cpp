#include "CanBo.h"
#include "CBHopDong.h"
#include "CBNhaNuoc.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap so can bo: ";
	cin >> n;
	CanBo **DSCanBo = new CanBo *[n];
	for (size_t i = 0; i < n; i++)
	{
		int loai;
		cout << "\nChon loai can bo:\n1.Can bo bien che.\n2.Can bo hop dong";
		cin >> loai;
		while (loai != 1 && loai != 2)
		{
			cout << "Chon lai loai nhan su: ";
			cin >> loai;
		}
		cin.ignore();
		if (loai == 1)
		{
			DSCanBo[i] = new CBNhaNuoc;
			DSCanBo[i]->Nhap();
		}
		else if (loai == 2)
		{
			DSCanBo[i] = new CBHopDong;
			DSCanBo[i]->Nhap();
		}
		cout << "\n*******Danh sach can bo*******";
		for (size_t i = 0; i < n; i++)
			DSCanBo[i]->Xuat();
	}
	return 0;
}