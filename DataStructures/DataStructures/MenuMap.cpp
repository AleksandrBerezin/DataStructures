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
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента в словарь.\n"
			<< "2. Удаление элемента из словаря.\n"
			<< "3. Поиск значения по ключу.\n"
			<< "4. Удаление словаря.\n"
			<< "5. Вывод словаря на экран.\n"
			<< "0. Назад.\n\n";

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
					cout << "Элемента с таким ключом нет.\n";
				}
				else
				{
					cout << "Элементу с ключом " << key
						<< " соответствует значение " << value << "\n";
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
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}