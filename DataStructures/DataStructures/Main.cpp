#include <iostream>
#include "CommonLibrary.h"
#include "Menus.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	bool isExit = false;

	while (!isExit)
	{
		cout << endl;
		cout << "�������� ����� ������������ ������:" << endl
			<< "1) ������������ ������ 1;" << endl
			<< "2) ������������ ������ 2;" << endl
			<< "3) ������������ ������ 3;" << endl
			<< "4) ������������ ������ 4;" << endl
			<< "5) ������������ ������ 5;" << endl
			<< "6) ������������ ������ 6;" << endl
			<< "0) �����." << endl;
		cout << endl;

		switch (InputInt())
		{
			case 1:
			{
				MenuLab1();
				break;
			}
			case 2:
			{
				MenuLab2();
				break;
			}
			case 3:
			{
				MenuLab3();
				break;
			}
			case 4:
			{
				MenuLab4();
				break;
			}
			case 5:
			{
				MenuLab5();
				break;
			}
			case 6:
			{
				MenuLab6();
				break;
			}
			case 0:
			{
				isExit = true;
				break;
			}
			default:
			{
				cout << "������ �������� �������, ���������� ��� ���." << endl;
				break;
			}
		}
	}

	return 0;
}