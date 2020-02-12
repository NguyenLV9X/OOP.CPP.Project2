#include"Company.h"
int main()
{
	int menu_option;
	Company<CEmployees> com;
	do
	{
		system("cls");
		cout << "========Chuong Trinh Quan Ly Nhan Vien========" << endl;
		cout << endl;
		cout << "Moi Ban chon:" << endl;
		cout << endl;
		cout << "1-Nhap thong tin nhan vien." << endl;
		cout << endl;
		cout << "2-Xem thong tin toan bo nhan vien." << endl;
		cout << endl;
		cout << "3-Xem thong tin tong luong nhan vien." << endl;
		cout << endl;
		cout << "0-Thoat." << endl;
		cout << endl;
		cout << "============================================";
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Lua chon cua ban la: ";
		cin >> menu_option;
		system("cls");
		switch (menu_option)
		{
		case 1:
			int menu2_option;
			do
			{
				system("cls");
				cout << "1-Nhap thong tin manager." << endl;
				cout << endl;
				cout << "2-Nhap thong tin programmer." << endl;
				cout << endl;
				cout << "3-Nhap thong tin employer." << endl;
				cout << endl;
				cout << "0-Thoat." << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "Lua chon cua ban la: ";
				cin >> menu2_option;
			} while (menu2_option < 0 || menu2_option>3);
			if (menu2_option == 0)
				break;
			else
			{
				system("cls");
				com.ImportEmploye(menu2_option);
				break;
			}
		case 2:
			com.ExportEmploye();
			break;
		case 3:
			com.ShowAllWage();
			break;
		}
	} while (menu_option != 0);
	return 0;
}