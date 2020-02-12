#pragma once
#include"Date.h"
#include<cstring>
#include<fstream>
//lop co so cua cac loai nhan vien
class CEmployees
{
protected:
	char _cAccount[100]; //ma so
	char _cName[100]; //ho ten
	CDate _cdDate; //ngay thang nam sinh
	char _cEmail[100]; // mail
	int _inPhone; // so dien thoai
	char _cAddress[100]; // dia chi
	unsigned int _wage; //luong can ban
public:
	//phuong thuc dinh dang lai du lieu tu file vao
	void decode(char * value);
	//phuong thuc dinh dang du lieu de luu vo file
	void encode(char * value, char * temp);
	//phuong thuc nhap du lieu tu file
	virtual void readfile(ifstream &is);
	//phuong thuc xuat du lieu ra file
	virtual void writefile(ofstream &os);
	//xuat thong tin doi tuong
	virtual void Export();
	//nhap thong tin doi tuong
	virtual void Import();
	//tra ve luong cua doi tuong
	virtual double payroll() = 0;
	//hien thong tin luong cua doi tuong
	void showwage();
	friend istream & operator >> (istream & is, CEmployees & em);
	friend ostream & operator << (ostream & os, const CEmployees & em);
	void setAccount(char * _Account);
	void setName(char * _Name);
	void setEmail(char * _Email);
	void setPhone(int _Phone);
	void setAddress(char * _Address);
	void setWage(unsigned int _Wage);
	void setDate(CDate _Date);
	char * getAccount();
	char * getName();
	char * getEmail();
	int getPhone();
	char * getAddress();
	unsigned int getWage();
	CDate getDate();
	CEmployees();
	~CEmployees();
};
