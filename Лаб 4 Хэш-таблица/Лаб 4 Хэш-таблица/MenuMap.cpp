#include <iostream>
#include "Map.h"
#include "MenuMap.h"
#include "Functions.h"

using namespace std;

bool IsMapNotCreateOrEmpty(Map* map);
bool IsMapNotCreate(Map* map);

void Menu(Map*& map)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� �������� � �������.\n"
			<< "2. �������� �������� �� �������.\n"
			<< "3. ����� �������� �� �����.\n"
			<< "4. �������� �������.\n"
			<< "5. ����� ������� �� �����.\n"
			<< "0. �����.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (map == nullptr)
				{
					map = new Map();
				}

				cout << "������� ����: ";
				string key = SubKey(InputString());
				cout << "������� ��������: ";
				string value = InputString();

				map->Add(&key, &value);
				Print(map);
				break;
			}
			case 2:
			{
				if (IsMapNotCreateOrEmpty(map))
				{
					break;
				}

				cout << "������� ����: ";
				string key = SubKey(InputString());

				map->Remove(&key);
				Print(map);
				break;
			}
			case 3:
			{
				if (IsMapNotCreateOrEmpty(map))
				{
					break;
				}

				cout << "������� ����: ";
				string key = SubKey(InputString());

				string value = map->Find(&key);
				if (value == "")
				{
					cout << "�������� � ����� ������ ���.\n";
				}
				else
				{
					cout << "�������� � ������ " << key
						<< " ������������� �������� " << value << "\n";
				}

				break;
			}
			case 4:
			{
				if (IsMapNotCreate(map))
				{
					break;
				}

				map->Delete();
				delete map;
				map = nullptr;
				break;
			}
			case 5:
			{
				if (IsMapNotCreate(map))
				{
					break;
				}

				Print(map);
				break;
			}
			case 0:
			{
				isBack = true;
				break;
			}
			default:
			{
				cout << "������ �������� �������, ���������� ��� ���.\n";
				break;
			}
		}
	}

	return;
}

//��������, ��� ���� �� ������ ��� ����
bool IsMapNotCreateOrEmpty(Map* map)
{
	if (map == nullptr || map->IsEmpty())
	{
		cout << "������� ����.\n";
		return true;
	}

	return false;
}

//��������, ��� ���� �� ������
bool IsMapNotCreate(Map* map)
{
	if (map == nullptr)
	{
		cout << "������� ����.\n";
		return true;
	}

	return false;
}