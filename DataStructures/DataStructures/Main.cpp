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
		cout << "Выберите номер лабораторной работы:" << endl
			<< "1) Лабораторная работа 1;" << endl
			<< "2) Лабораторная работа 2;" << endl
			<< "3) Лабораторная работа 3;" << endl
			<< "4) Лабораторная работа 4;" << endl
			<< "5) Лабораторная работа 5;" << endl
			<< "6) Лабораторная работа 6;" << endl
			<< "0) Выход." << endl;
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
				cout << "Выбран неверный вариант, попробуйте еще раз." << endl;
				break;
			}
		}
	}

	return 0;
}