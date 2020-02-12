#include "Manager.h"
//xuat thong tin quan ly
void CManager::Export()
{
	cout << "Manager" << endl;
	CEmployees::Export();
	cout << "Chuc vu: " << _cOffice << endl;
	cout << "He so chuc vu: " << _unsCoefficient << endl;
}

//nhap thong tin quan ly
void CManager::Import()
{
	CEmployees::Import();
	cout << "Nhap chuc vu: ";
	fflush(stdin);
	cin.getline(_cOffice, 100);
	do
	{
		cout << "Nhap he so chuc vu (0 or 1) : ";
		cin >> _unsCoefficient;
	} while (_unsCoefficient != 0 && _unsCoefficient != 1);
	try
	{
		cout << "Nhap tien thuong: ";
		cin >> _uniReward;
		if (_uniReward < 0)
		{
			throw 2;
		}
	}
	catch (int exception)
	{
		throw exception;
	}
}

//tinh tong luong cua quan ly
double CManager::payroll()
{
	return _wage + _wage * _unsCoefficient + _uniReward;
}


CManager::CManager()
{
	this->_wage = 1000;
}


CManager::~CManager()
{
}

istream & operator>>(istream & is, CManager & ma)
{
	/*is >> static_cast<CEmployees &>(ma);*/
	CEmployees &Temp = ma;
	is >> Temp;
	cout << "Nhap chuc vu: ";
	is.ignore();
	is.getline(ma._cOffice, 100);
	cout << "Nhap he so chuc vu: ";
	is >> ma._unsCoefficient;
	cout << "Nhap tien thuong: ";
	is >> ma._uniReward;
	return is;
}

ostream & operator<<(ostream & os, CManager & ma)
{
	CEmployees &Temp = ma;
	os << Temp;
	os << "Chuc vu: " << ma._cOffice << endl;
	os << "He so chuc vu: " << ma._unsCoefficient << endl;
	return os;
}

//doc thong tin quan ly tu file
void CManager::readfile(ifstream & is)
{
	CEmployees::readfile(is);
	is >> _cOffice;
	try
	{
		is >> _unsCoefficient;
		if (_unsCoefficient != 0 && _unsCoefficient != 1)
			throw 2;
		is >> _uniReward;
		if (_uniReward < 0)
			throw 2;
	}
	catch (int exception)
	{
		throw exception;
	}
	decode(_cOffice);
}

//ghi thong tin quan ly ra file
void CManager::writefile(ofstream & os)
{
	CEmployees::writefile(os);
	char * temp = new char[100];
	encode(_cOffice, temp);
	os << temp << endl;
	os << _unsCoefficient << endl;
	os << _uniReward << endl;
	delete[] temp;
}

void CManager::setOffice(char * _Office)
{
	strcpy_s(_cOffice, _Office);
}

void CManager::setCoefficient(unsigned short _Coefficient)
{
	_unsCoefficient = _Coefficient;
}

void CManager::setReward(unsigned int _Reward)
{
	_unsCoefficient = _Reward;
}

char * CManager::getOffice()
{
	return _cOffice;
}

unsigned int CManager::getReward()
{
	return _uniReward;
}

unsigned short CManager::getCoefficient()
{
	return _unsCoefficient;
}