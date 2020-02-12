#include "Employer.h"
//xuat thong tin nhan vien van phong
void CEmployer::Export()
{
	cout << "Employer" << endl;
	CEmployees::Export();
	cout << "Nhiem Vu: " << _cOffice << endl;
	cout << "Tro cap: " << _uniAllowance << endl;
}

//nhap thong tin nhan vien van phong
void CEmployer::Import()
{
	CEmployees::Import();
	cout << "Nhap nhiem vu nhan vien: ";
	fflush(stdin);
	cin.getline(_cOffice, 100);
	try
	{
		cout << "Nhap tro cap: ";
		cin >> _uniAllowance;
		if (_uniAllowance < 0)
		{
			throw 1;
		}
	}
	catch (int exception)
	{
		throw exception;
	}
}

//tinh luong theo cong thuc cua nhan vien van phong
double CEmployer::payroll()
{
	return _wage * _uniAllowance;
}

CEmployer::CEmployer()
{
	this->_wage = 950;
}


CEmployer::~CEmployer()
{
}

//doc du lieu nhan vien van phong tu file
void CEmployer::readfile(ifstream & is)
{
	CEmployees::readfile(is);
	is >> _cOffice;
	try
	{
		is >> _uniAllowance;
		if (_uniAllowance < 0)
		{
			throw 2;
		}
	}
	catch (int exception)
	{
		throw exception;
	}
	decode(_cOffice);
}

//xuat du lieu nhan vien van phong ra file
void CEmployer::writefile(ofstream & os)
{
	CEmployees::writefile(os);
	char * temp = new char[100];
	encode(_cOffice, temp);
	os << temp << endl;
	os << _uniAllowance << endl;
	delete[] temp;
}

void CEmployer::setOffice(char * _Office)
{
	strcpy_s(_cOffice, _Office);
}
void CEmployer::setAllowance(unsigned int _Allowance)
{
	_uniAllowance = _Allowance;
}
char * CEmployer::getOffice()
{
	return _cOffice;
}
unsigned int CEmployer::getAllowance()
{
	return _uniAllowance;
}