#pragma once
#include "Node.h"
#include "HashTable.h"

using std::string;

const int sizeTable = 8;

struct HashTable
{
	Node* KeyValueArray;	// ������, ���������� �������� ���� ����-��������
	int CurrentLength;		// ���������� ��������� � �������
	int Size;				// ������ �������
	
	void Init();
	//TODO: ������������� ������ ��� �������� string?(Done)
	void Add(string& key, string& value);
	void Remove(string& key);
	string Find(string& key);
	int CountHash(string& key);
	//TODO: Naming(Done)
	void ResolveCollision(int hash, string& key, string& value);
	void Rehashing();
	void Delete();
	bool IsEmpty();

	HashTable()
	{
		KeyValueArray = new Node[sizeTable];
		CurrentLength = 0;
		Size = sizeTable;

		Init();
	}
};

void Print(HashTable* hashTable);