#include <iostream>
#include "Map.h"
#include "MenuMap.h"
#include "CommonLibrary.h"
#include "MapLibrary.h"

using namespace std;

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

				string key = InputStringKey();
				string value = InputStringValue();

				map->Add(key, value);
				Print(map);
				break;
			}
			case 2:
			{
				if (IsMapNotCreateOrEmpty(map))
				{
					break;
				}

				string key = InputStringKey();

				map->Remove(key);
				Print(map);
				break;
			}
			case 3:
			{
				if (IsMapNotCreateOrEmpty(map))
				{
					break;
				}

				string key = InputStringKey();

				string value = map->Find(key);
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