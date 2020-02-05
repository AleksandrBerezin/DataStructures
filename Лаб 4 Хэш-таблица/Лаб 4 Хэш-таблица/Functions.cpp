#include <iostream>
#include "Functions.h"
#include <string>

using namespace std;
using std::string;

//Проверка, что вводимое число int
int InputInt()
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
string InputString()
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
string SubKey(string str)
{
	return str.substr(0, 6);
}