#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "Map.h"

using namespace std;
using std::string;

// ���������� � ������� ������ key-value
void Map::Add(string& key, string& value)
{
	if (Contains(key))
	{
		cout << "\n������� ��� ������������ � �������.\n";
		return;
	}

	InternalHashTable->Add(key, value);
}

// �������� �� ������� ������ key-value
void Map::Remove(string& key)
{
	InternalHashTable->Remove(key);
}

// ����� value �� key
string Map::Find(string& key)
{
	return InternalHashTable->Find(key);
}

// �������� �������
void Map::Delete()
{
	InternalHashTable->Delete();
}

// ��������: �������� ������� ���� ��� ���
bool Map::Contains(string& key)
{
	int hash = InternalHashTable->CountHash(key);
	Node* current = &InternalHashTable->KeyValueArray[hash];

	while (current != nullptr)
	{
		// ������ �� ������������ ��� key-value
		if (current->Key == key)
		{
			return true;
		}

		current = current->Next;
	}

	return false;
}

// ��������: ���� �������(true) ��� ���(false)
bool Map::IsEmpty()
{
	return InternalHashTable->CurrentLength == 0;
}