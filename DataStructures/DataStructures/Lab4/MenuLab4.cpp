#include <iostream>
#include "HashTable.h"
#include "Map.h"
#include "Menus/MenuMap.h"
#include "Menus/MenuHashTable.h"
#include "../Common/CommonLibrary.h"

using namespace std;

void MenuLab4()
{
	Map* map = new Map();
	HashTable* hashTable = new HashTable();

	bool isBack = false;

	while (!isBack)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. Словарь.\n"
			<< "2. Хэш-таблица.\n"
			<< "0. Назад.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				Menu(map);
				break;
			}
			case 2:
			{
				Menu(hashTable);
				break;
			}
			case 0:
			{
				if (map != nullptr)
				{
					map->Delete();
					delete map;
					map = nullptr;
				}
				if (hashTable != nullptr)
				{
					hashTable->Delete();
					delete hashTable;
					hashTable = nullptr;
				}

				isBack = true;
				break;
			}
			default:
			{
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}