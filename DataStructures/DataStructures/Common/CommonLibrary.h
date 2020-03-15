#pragma once

#include <iostream>
#include <string>

using namespace std;
using std::string;

/*
	Общие функции
*/

//Проверка, что вводимое число int
inline int InputInt()
{
	int number = 0;

	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR\n";
		}
		else
		{
			break;
		}
	}

	return number;
}

// Проверка, что введенная строка не пустая
inline string InputString()
{
	string str;
	getline(cin, str);

	while (str.empty())
	{
		getline(cin, str);
	}

	return str;
}

// Обрезание ключа до 6 символов
inline string SubKey(string str)
{
	return str.substr(0, 6);
}


inline string InputStringKey()
{
	cout << "Введите ключ: ";
	return SubKey(InputString());
}

inline int InputIntKey()
{
	cout << "Введите ключ элемента: ";
	return InputInt();
}

inline string InputStringValue()
{
	cout << "Введите значение: ";
	return InputString();
}

inline int InputIndex()
{
	cout << "Введите индекс элемента:\n";
	return InputInt();
}

inline int InputIntValue()
{
	cout << "Введите значение элемента:\n";
	return InputInt();
}