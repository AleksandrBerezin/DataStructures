#pragma once
#include "Node.h"
#include "HashTable.h"

using std::string;

//TODO: Naming(Done)
const int sizeTable = 8;	// ��������� �������� ������� �������

struct HashTable
{
	//TODO: Naming(Done)
	Node* KeyValueArray;	// ������, ���������� �������� ���� ����-��������
	int Length;	// ���������� ��������� � �������
	int Size;	// ������ �������
	
	void Init();
	//TODO: ������������� ������ ��� �������� string?(Done)
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