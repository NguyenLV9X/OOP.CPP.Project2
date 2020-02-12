#include "Programmer.h"

//xuat thong tin lap trinh vien ra man hinh
void CProgrammer::Export()
{
	cout << "Programmer" << endl;
	CEmployees::Export();
	cout << "Thoi gian lam viec: " << _unsWtime << endl;
	cout << "Thoi gian lam them: " << _unsOtime << endl;
	cout << "Tro cap: " << _uniAllowance << endl;
}

//nhap thong tin lap trinh vien 
void CProgrammer::Import()
{
	CEmployees::Import();
	try
	{
		cout << "Nhap thoi gian lam: ";
		cin >> _unsWtime;
		if (_unsWtime < 0)
		{
			throw 3;
		}
		cout << "Nhap thoi gian lam them: ";
		cin >> _unsOtime;
		if (_unsOtime < 0)
		{
			throw 3;
		}
		cout << "Nhap tro cap: ";
		cin >> _uniAllowance;
		if (_uniAllowance < 0)
		{
			throw 3;
		}
	}
	catch (int exception)
	{
		throw exception;
	}
}

//tinh luong lap trinh vien
double CProgrammer::payroll()
{
	return _wage + (_wage / _unsWtime) * _unsOtime * 1.5 + _uniAllowance;
}


CProgrammer::CProgrammer()
{
	this->_wage = 800;
}


CProgrammer::~CProgrammer()
{
}

//doc thong tin lap trinh vien tu file
void CProgrammer::readfile(ifstream & is)
{
	CEmployees::readfile(is);
	try
	{
		is >> _unsWtime;
		if (_unsWtime < 0)
			throw 2;
		is >> _unsOtime;
		if (_unsOtime < 0)
			throw 2;
		is >> _uniAllowance;
		if (_uniAllowance < 0)
			throw 2;
	}
	catch (int exception)
	{
		throw exception;
	}
}

//xuat thong tin lap trinh vien ra file
void CProgrammer::writefile(ofstream & os)
{
	CEmployees::writefile(os);
	os << _unsWtime << endl;
	os << _unsOtime << endl;
	os << _uniAllowance << endl;
}

void CProgrammer::setWtime(unsigned short _Wtime)
{
	_unsWtime = _Wtime;
}

void CProgrammer::setOtime(unsigned short _Otime)
{
	_unsOtime = _Otime;
}

void CProgrammer::setAllowance(unsigned int _Allowance)
{
	_uniAllowance = _Allowance;
}

unsigned short CProgrammer::getWtime()
{
	return _unsWtime;
}

unsigned short CProgrammer::getOtime()
{
	return _unsOtime;
}

unsigned int CProgrammer::getAllowance()
{
	return _uniAllowance;
}