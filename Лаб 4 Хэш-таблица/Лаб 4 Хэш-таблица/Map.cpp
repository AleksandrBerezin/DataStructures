#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "Map.h"

using namespace std;
using std::string;

// Добавление в словарь набора key-value
void Map::Add(string& key, string& value)
{
	if (Contains(key))
	{
		cout << "\nЭлемент уже присутствует в словаре.\n";
		return;
	}

	InternalHashTable->Add(key, value);
}

// Удаление из словаря набора key-value
void Map::Remove(string& key)
{
	InternalHashTable->Remove(key);
}

// Поиск value по key
string Map::Find(string& key)
{
	return InternalHashTable->Find(key);
}

// Удаление словаря
void Map::Delete()
{
	InternalHashTable->Delete();
}

// Проверка: содержит словарь ключ или нет
bool Map::Contains(string& key)
{
	int hash = InternalHashTable->CountHash(key);
	Node* current = &InternalHashTable->KeyValueArray[hash];

	while (current != nullptr)
	{
		// Запрет на дублирование пар key-value
		if (current->Key == key)
		{
			return true;
		}

		current = current->Next;
	}

	return false;
}

// Проверка: пуст словарь(true) или нет(false)
bool Map::IsEmpty()
{
	return InternalHashTable->CurrentLength == 0;
}