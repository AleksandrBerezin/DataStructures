#pragma once
using std::string;

const int SIZE = 8;	// Начальное значение размера таблицы

struct HashTable
{
	Node* Array;	// Массив, содержащий элементы типа ключ-значение
	int Length;	// Количество элементов в таблице
	int Size;	// Размер таблицы
	
	void Init();
	void Add(string key, string value);
	void Remove(string key);
	string Find(string key);
	int Hash(string key);
	void Collision(int hash, string key, string value);
	void Rehashing();
	void Delete();
	bool IsEmpty();

	HashTable()
	{
		Array = new Node[SIZE];
		Length = 0;
		Size = SIZE;

		Init();
	}
};

void Print(HashTable* hashTable);