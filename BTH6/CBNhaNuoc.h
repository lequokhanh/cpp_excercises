#pragma once
#include "CanBo.h"
class CBNhaNuoc : public CanBo
{
	double LuongCoBan;
	double HeSoLuong;
	double HeSoPhuCap;

public:
	void Nhap();
	void Xuat();
	double luong();
};