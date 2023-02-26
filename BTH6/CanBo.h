#pragma once
#include<string>
#include<iostream>
using namespace std;

class CanBo {
	string name;
	string birthday;
	string MSNS;
protected:
	double salary;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual double luong() = 0;
};