#pragma once
#include "Employees.h"
//lop nhan vien van phong
class CEmployer : public CEmployees
{
private:
	char _cOffice[100]; //nhiem vu
	int _uniAllowance; //tro cap
public:
	//doc thong tin tu file
	void readfile(ifstream &is);
	//xuat thong tin ra file
	void writefile(ofstream &os);
	void setOffice(char * _Office);
	void setAllowance(unsigned int _Allowance);
	char * getOffice();
	unsigned int getAllowance();
	//xuat thong tin
	void Export();
	//Nhap thong tin
	void Import();
	//tinh luong theo doi tuong van phong
	double payroll();
	CEmployer();
	~CEmployer();
};
