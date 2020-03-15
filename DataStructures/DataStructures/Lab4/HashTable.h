#pragma once
#include "HashTableNode.h"
#include "HashTable.h"

using std::string;

const int sizeTable = 8;

struct HashTable
{
	HashTableNode* KeyValueArray;	// Массив, содержащий элементы типа ключ-значение
	int CurrentLength;				// Количество элементов в таблице
	int Size;						// Размер таблицы

	void Init();
	void Add(string& key, string& value);
	void Remove(string& key);
	string Find(string& key);
	int CountHash(string& key);
	void ResolveCollision(int hash, string& key, string& value);
	void Rehashing();
	void Delete();
	bool IsEmpty();

	HashTable()
	{
		KeyValueArray = new HashTableNode[sizeTable];
		CurrentLength = 0;
		Size = sizeTable;

		Init();
	}
};