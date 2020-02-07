#pragma once

#include <iostream>
#include <string>

using namespace std;
using std::string;

/*
	����� �������
*/

//��������, ��� �������� ����� int
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

// ��������, ��� ��������� ������ �� ������
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

// ��������� ����� �� 6 ��������
inline string SubKey(string str)
{
	return str.substr(0, 6);
}


inline string InputStringKey()
{
	cout << "������� ����: ";
	return SubKey(InputString());
}

inline int InputIntKey()
{
	cout << "������� ���� ��������: ";
	return InputInt();
}

inline string InputStringValue()
{
	cout << "������� ��������: ";
	return InputString();
}

inline int InputIndex()
{
	cout << "������� ������ ��������:\n";
	return InputInt();
}

inline int InputIntValue()
{
	cout << "������� �������� ��������:\n";
	return InputInt();
}