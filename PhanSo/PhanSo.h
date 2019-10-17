#pragma once
#include <iostream>
using namespace std;
class PhanSo
{
	int mTu;
	int mMau;
public:
	static int UCLN(int,int);
	PhanSo();
	PhanSo(int,int);
	~PhanSo();
	void rutGon();
	PhanSo& operator=(PhanSo);
	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);
	PhanSo operator*(PhanSo);
	PhanSo operator/(PhanSo);
	friend ostream& operator<<(ostream&, PhanSo);
	friend istream& operator>>(istream&, PhanSo&);
	static PhanSo tinhChuoi();
};
