#include <iostream>
#include "Functions.h"
#include <string>

using namespace std;
using std::string;

//��������, ��� �������� ����� int
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

// ��������, ��� ��������� ������ �� ������
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

// ��������� ����� �� 6 ��������
string SubKey(string str)
{
	return str.substr(0, 6);
}