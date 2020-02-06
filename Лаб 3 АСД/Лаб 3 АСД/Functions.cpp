#include <iostream>
#include "Functions.h"

using namespace std;

//Проверка, что вводимое число int
int Input()
{
	//TODO: naming
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