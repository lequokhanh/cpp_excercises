
#pragma once
#include <string>
#include <iostream>
#include "CanBo.h"
using namespace std;
class CBHopDong : public CanBo
{
	double TienCong;
	int SoNgayCong;
	double HeSoVuotGio;

public:
	void Nhap();
	void Xuat();
	double luong();
};