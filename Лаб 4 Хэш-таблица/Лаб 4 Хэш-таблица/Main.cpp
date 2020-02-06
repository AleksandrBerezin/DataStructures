#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "Map.h"
#include "Functions.h"
#include "MenuMap.h"
#include "MenuHashTable.h"

using namespace std;
using std::string;

int main()
{
	setlocale(LC_ALL, "Russian");
    
	Map* map = new Map();
	HashTable* hashTable = new HashTable();

	bool isExit = false;

	while (!isExit)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. Словарь.\n"
			<< "2. Хэш-таблица.\n"
			<< "0. Выход.\n\n";

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

				isExit = true;
				break;
			}
			default:
			{
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}
}