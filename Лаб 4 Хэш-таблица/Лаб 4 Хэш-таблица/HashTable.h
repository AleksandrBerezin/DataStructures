#pragma once
#include "Node.h"
#include "HashTable.h"

using std::string;

//TODO: Naming(Done)
const int sizeTable = 8;	// Начальное значение размера таблицы

struct HashTable
{
	//TODO: Naming(Done)
	Node* KeyValueArray;	// Массив, содержащий элементы типа ключ-значение
	int Length;	// Количество элементов в таблице
	int Size;	// Размер таблицы
	
	void Init();
	//TODO: Использование ссылок при передаче string?(Done)
	void Add(string* key, string* value);
	void Remove(string* key);
	string Find(string* key);
	//TODO: Naming(Done)
	int HashCalculate(string* key);
	//TODO: Naming(Done)
	void CollisionResolution(int hash, string* key, string* value);
	void Rehashing();
	void Delete();
	bool IsEmpty();

	HashTable()
	{
		KeyValueArray = new Node[sizeTable];
		Length = 0;
		Size = sizeTable;

		Init();
	}
};

void Print(HashTable* hashTable);