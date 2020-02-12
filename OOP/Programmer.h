#pragma once
#include "Employees.h"
// lop lap trinh vien
class CProgrammer : public CEmployees
{
private:
	short _unsWtime; //thoi gian lam viec
	short _unsOtime; // thoi gian OT
	int _uniAllowance; //tro cap
public:
	//doc thong tin tu file
	void readfile(ifstream &is);
	//xuat thong tin ra file
	void writefile(ofstream &os);
	void setWtime(unsigned short _Wtime);
	void setOtime(unsigned short _Otime);
	void setAllowance(unsigned int _Allowance);
	unsigned short getWtime();
	unsigned short getOtime();
	unsigned int getAllowance();
	//xuat thong tin
	void Export();
	//nhap thong tin
	void Import();
	//tinh luong theo doi tuong lap trinh vien
	double payroll();
	CProgrammer();
	~CProgrammer();
};

