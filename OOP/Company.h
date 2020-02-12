#pragma once
#include<vector>
#include"Employer.h"
#include"Manager.h"
#include"Programmer.h"

//lop thuc thi
template<typename T>
class Company
{
private:
	//nhap tat ca nhan vien tu file vao
	void ReadFile();
	//xuat 1 doi tuong nhan vien ra file
	void WriteFile(T * Data,char Type); 
	vector<T *>_allEmploye; //thuoc tinh luu tat ca nhan vien
public:
	//them 1 nhan vien vao
	void ImportEmploye(int option);
	//xuat tat ca nhan vien
	void ExportEmploye();
	//hien thi luong tat ca nhan vien
	void ShowAllWage();
	Company();
	~Company();
};

//nhap nhan vien tu file
template<typename T>
void Company<T>::ReadFile()
{
	ifstream _iFile;
	char Type; //Bien luu loai nhan vien
	try
	{
		_iFile.open("FILE.txt",  ios::in);
		if (!_iFile)
		{
			throw 1;//ngoai le neu file khong ton tai
		}
		int count = 0; // dem so luong nhan vien trong file co thong tin bi loi
		while (_iFile.read(reinterpret_cast<char *>(&Type), sizeof(char)))
		{
			switch (Type)
			{
				//nhap thong tin quan ly tu file
				case 'M':
				{
					T *temp = new CManager();
					try
					{
						temp->readfile(_iFile);
						_allEmploye.push_back(temp);
					}
					catch (...) //xu ly ngoai le thong tin sai tu file
					{
						count++;
					}
					break;
				}
				//nhap thong tin lap trinh vien tu file
				case 'P':
				{
					T *temp = new CProgrammer();
					try
					{
						temp->readfile(_iFile);
						_allEmploye.push_back(temp);
					}
					catch (...)//xu ly ngoai le thong tin sai tu file
					{
						count++;
					}
					break;
				}
				//nhap thong tin nhan vien tu file
				case 'E':
				{
					T *temp = new CEmployer();
					try
					{
						temp->readfile(_iFile);
						_allEmploye.push_back(temp);
					}
					catch (...)//xu ly ngoai le thong tin sai tu file
					{
						count++;
					}
					break;
				}
			}
		}
		if (count == 0)
		{
			cout << "============================================";
			cout << endl;
			cout << "Cap nhap du lieu tu file thanh cong!!!" << endl;
			cout << "Hay an phim enter de toi menu chinh" << endl;
			system("pause");
		}
		else
		{
			cout << "============================================";
			cout << endl;
			cout << "Trong File co du lieu khong hop le!!!" << endl;
			cout << "So luong du lieu khong hop le : " << count << endl;
			cout << "Nhung du lieu hop le da duoc cap nhap!!!" << endl;
			cout << "Hay an phim enter de toi menu chinh" << endl;
			system("pause");
		}
		_iFile.close();
	}
	catch (int exception)//xu li ngoai le neu file khong ton tai
	{
		if (exception == 1)
		{
			_iFile.close();
			cout << "============================================";
			cout << endl;
			cout << "File du lieu khong co , se tu tao neu them nhan vien!!!" << endl;
			cout << "Hay an phim enter de toi menu chinh" << endl;
			system("pause");
		}
	}
}

//xuat 1 nhan vien ra file
template<typename T>
void Company<T>::WriteFile(T * Data,char Type)
{
	ofstream _oFile;
	_oFile.open("FILE.txt", ios::out | ios::app); //neu file khong ton tai tu khoi tao
	_oFile.write(reinterpret_cast<char *>(&Type), sizeof(char));
	Data->writefile(_oFile);
	_oFile.close();
}

//them 1 nhan vien
template<typename T>
void Company<T>::ImportEmploye(int option)
{
	if (option == 1)
	{
		cout << "NHAP THONG TIN MANAGER" << endl;
		T *temp = new CManager();
		while (true)
		{
			try
			{
				temp->Import();
				_allEmploye.push_back(temp);
				char Type = 'M'; //kieu nhan vien se duoc luu vo file
				WriteFile(temp, Type); //them doi tuong vao file
				break;
			}
			catch (int exception) //xu ly ngoai le du lieu nhap vao sai
			{
				cout << "Du lieu khong hop le xin nhap lai tu dau!!!" << endl;
			}
		}
	}
	if (option == 2)
	{
		cout << "NHAP THONG TIN PROGRAMMER" << endl;
		T *temp = new CProgrammer();
		while (true)
		{
			try
			{
				temp->Import();
				_allEmploye.push_back(temp);
				char Type = 'P'; //kieu nhan vien se duoc luu vo file
				WriteFile(temp, Type); //them doi tuong vao file
				break;
			}
			catch (int exception) //xu ly ngoai le du lieu nhap vao sai
			{
				cout << "Du lieu khong hop le xin nhap lai tu dau!!!" << endl;
			}
		}
	}
	if (option == 3)
	{
		cout << "NHAP THONG TIN EMPLOYER" << endl;
		T *temp = new CEmployer();
		while (true)
		{
			try
			{
				temp->Import();
				_allEmploye.push_back(temp);
				char Type = 'E'; //kieu nhan vien se duoc luu vo file
				WriteFile(temp, Type); //them doi tuong vao file
				break;
			}
			catch (int exception) //xu ly ngoai le du lieu nhap vao sai
			{
				cout << "Du lieu khong hop le xin nhap lai tu dau!!!" << endl;
			}
		}
	}
}

//xuat tat ca nhan vien ra man hinh
template<typename T>
void Company<T>::ExportEmploye()
{
	int lenght = _allEmploye.size();
	if (lenght == 0)
	{
		cout << "Hien tai chua co nhan vien nao !" << endl;
	}
	else
	{
		cout << "Tong So Nhan Vien: " << lenght << endl;
		cout << endl;
		cout << endl;
		for (int i = 0; i < lenght; ++i)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN NHAN VIEN " << i + 1 << endl;
			_allEmploye[i]->Export();
		}
	}

	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

//xuat tong luong cua tat ca nhan vien ra man hinh
template<typename T>
void Company<T>::ShowAllWage()
{
	int lenght = _allEmploye.size();
	if (lenght == 0)
	{
		cout << "Hien tai chua co nhan vien nao !" << endl;
	}
	else
	{
		cout << "Tong So Nhan Vien: " << lenght << endl;
		cout << endl;
		cout << endl;
		for (int i = 0; i < lenght; ++i)
		{
			cout << "============================================" << endl;
			cout << "TONG LUONG NHAN VIEN " << endl;
			_allEmploye[i]->showwage();
		}
	}

	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

template<typename T>
Company<T>::Company()
{
	ReadFile();//doc thong tin file
}

template<typename T>
Company<T>::~Company()
{
}