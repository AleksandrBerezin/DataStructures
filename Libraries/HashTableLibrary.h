#pragma once

#include <iostream>
#include <string>
#include "..\Лаб 4 Хэш-таблица\Лаб 4 Хэш-таблица\HashTable.h"

using namespace std;
using std::string;

/*
	Функции для хеш-таблицы
*/

//Проверка, что хеш-таблица не создана или пуст
bool IsHashTableNotCreateOrEmpty(HashTable* hashTable)
{
	if (hashTable == nullptr || hashTable->IsEmpty())
	{
		cout << "Хеш-таблица пустая.\n";
		return true;
	}

	return false;
}

//Проверка, что хеш-таблица не создана
bool IsHashTableNotCreate(HashTable* hashTable)
{
	if (hashTable == nullptr)
	{
		cout << "Хеш-таблица пустая.\n";
		return true;
	}

	return false;
}

// Вывод таблицы на экран
void Print(HashTable* hashTable)
{
	cout << "\n\tХеш-таблица\n\n";
	cout << "Индекс\t:\tКлюч\t:\tЗначение\n";
	for (int i = 0; i < hashTable->Size; i++)
	{
		Node* current = &hashTable->KeyValueArray[i];
		if (current->Key.empty())
		{
			cout << i << "\t:\tПусто\t:\tПусто\n";
		}
		else
		{
			cout << i << "\t:\t" << current->Key << "\t:\t"
				<< current->Value << "\n";
			current = current->Next;

			while (current != nullptr)
			{
				cout << "->\t:\t" << current->Key << "\t:\t"
					<< current->Value << "\n";
				current = current->Next;
			}
		}
	}
	cout << "\n";
}