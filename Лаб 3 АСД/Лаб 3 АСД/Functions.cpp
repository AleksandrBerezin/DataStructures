#include <iostream>

using namespace std;

//��������, ��� �������� ����� int
int Input()
{
	int a = 0;

	while (true)
	{
		cin >> a;
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

	return a;
}