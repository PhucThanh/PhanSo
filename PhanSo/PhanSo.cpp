#include "PhanSo.h"



PhanSo::PhanSo():mTu(0),mMau(1)
{

}

PhanSo::PhanSo(int a,int b) : mTu(a), mMau(b)
{

}
PhanSo::~PhanSo()
{

}

int PhanSo::UCLN(int a,int b)
{
	if (a == 0 || b == 0) return 1;
	if (a < 0) a = -a;
	if (b < 0)b = -b;

	if (a == b) 
		return a;
	if (a > b)
		return UCLN(a - b,b);
	return UCLN(a,b - a);
}
void PhanSo::rutGon()
{
	int ucln = UCLN(mTu, mMau);
	mTu /= ucln;
	mMau /= ucln;
	if (mTu == 0) mMau = 1;
}
PhanSo& PhanSo::operator=(PhanSo ps)
{
	mTu = ps.mTu;
	mMau = ps.mMau;
	return *this;
}
PhanSo PhanSo::operator+(PhanSo ps)
{
	PhanSo result;
	result.mTu = mMau * ps.mTu + mTu * ps.mMau;
	result.mMau = mMau * ps.mMau;
	result.rutGon();
	return result;
}
PhanSo PhanSo::operator-(PhanSo ps)
{
	PhanSo result;
	result.mTu = mTu * ps.mMau- mMau * ps.mTu;
	result.mMau = mMau * ps.mMau;
	result.rutGon();
	return result;
}
PhanSo PhanSo::operator*(PhanSo ps)
{
	PhanSo result;
	result.mTu = mTu * ps.mTu;
	result.mMau = mMau * ps.mMau;
	result.rutGon();
	return result;
}
PhanSo PhanSo::operator/(PhanSo ps)
{
	PhanSo result;
	result.mTu = mTu * ps.mMau;
	result.mMau = mMau * ps.mTu;
	if(mMau==0)
	{
		mTu = 0;
		mMau = 1;
	}
	result.rutGon();
	return result;
}
ostream& operator<<(ostream& os,PhanSo ps)
{
	os << ps.mTu << "/" << ps.mMau;
	return os;
}
istream& operator>>(istream& is, PhanSo& ps)
{
	/*
	cout << "Nhap Tu So:";
	is >> ps.mTu;
	cout << "Nhap Mau So:";
	is >> ps.mMau;
	*/
	char c;
	do {
		is >> ps.mTu >> c >> ps.mMau;
	} while (ps.mMau == 0);
	return is;
}
PhanSo PhanSo::tinhChuoi()
{
	int n;//So luong phan so
	PhanSo ps[100];
	//cout << "Nhap so luong phan so:";
	//cin >> n;
	char op[99];
	for (int i = 0; i < 100; i++)
	{
		cin >> ps[i];
		//if (i < n - 1)
		cin >> op[i];
		if (op[i] == '=')
		{
			n = i+1;//So phan so
			break;
		}
	}
	//ps1 ps2 ps3
	//+    -
	PhanSo result = ps[0];
	for (int i = 0; i < n - 1; i++)//n-1 vi so toan tu it hon phanso
	{
		switch (op[i])
		{
		case '+':
			result = result + ps[i + 1];
			break;
		case '-':
			result = result - ps[i + 1];
			break;
		}
	}
	result.rutGon();
	//Xuat kq

	cout << ps[0];
	for (int i = 0; i < n - 1; i++)
	{
		cout << " " << op[i] << " ";
		cout << ps[i + 1];
	}
	return result;
}