#pragma once
#include "Employees.h"
//lop quan ly
class CManager : public CEmployees
{
private:
	char _cOffice[100];//chuc vu
	short _unsCoefficient;//he so chuc vu
	int _uniReward;//tien thuong
public:
	//doc thong tin tu file
	void readfile(ifstream &is);
	//xuat thong tin ra file
	void writefile(ofstream &os);
	void setOffice(char * _Office);
	void setCoefficient(unsigned short _Coefficient);
	void setReward(unsigned int _Reward);
	char * getOffice();
	unsigned int getReward();
	unsigned short getCoefficient();
	//xuaat thong tin
	void Export();
	//nhap thong tin
	void Import();
	//tinh luong theo doi tuong quan ly
	double payroll();
	friend istream & operator>>(istream & is, CManager & ma);
	friend ostream & operator<<(ostream & os, CManager & ma);
	CManager();
	~CManager();
};