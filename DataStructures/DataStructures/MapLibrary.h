#pragma once

#include <iostream>
#include <cstring>
#include "Map.h"

using namespace std;
using std::string;

/*
	Функции для словаря
*/

//Проверка, что словарь не создан или пуст
bool IsMapNotCreateOrEmpty(Map* map)
{
	if (map == nullptr || map->IsEmpty())
	{
		cout << "Словарь пуст.\n";
		return true;
	}

	return false;
}

//Проверка, что словарь не создан
bool IsMapNotCreate(Map* map)
{
	if (map == nullptr)
	{
		cout << "Словарь пуст.\n";
		return true;
	}

	return false;
}

// Вывод словаря на экран
void Print(Map* map)
{
	cout << "\n\tСловарь\n\n";
	cout << "Ключ\t:\tЗначение\n";
	for (int i = 0; i < map->InternalHashTable->Size; i++)
	{
		HashTableNode* current = &map->InternalHashTable->KeyValueArray[i];
		while (current != nullptr)
		{
			if (!current->Key.empty())
			{
				cout << current->Key << "\t:\t" << current->Value << "\n";
			}
			current = current->Next;
		}
	}
	cout << "\n";
}