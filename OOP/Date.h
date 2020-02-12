#pragma once
#include<iostream>
using namespace std;

//class mo ta ngay/thang/nam
class CDate
{
private:
	int _uinDay; //ngay
	int _uinMonth; //thang
	int _uinYear; //nam
public:
	friend istream & operator >>(istream & is, CDate & d);
	friend ostream & operator <<(ostream & os, const CDate & d);
	void setDay(int set_Day);
	void setMonth(int set_Month);
	void setYear(int set_Year);
	int getDay();
	int getMonth();
	int getYear();
	CDate();
	~CDate();
};