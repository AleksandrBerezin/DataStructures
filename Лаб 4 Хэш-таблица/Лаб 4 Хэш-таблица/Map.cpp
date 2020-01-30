#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "Map.h"

using namespace std;
using std::string;

// ���������� � ������� ������ key-value
void Map::Add(string key, string value)
{
	if (Contains(key))
	{
		cout << "\n������� ��� ������������ � �������.\n";
		return;
	}

	Table->Add(key, value);
}

// �������� �� ������� ������ key-value
void Map::Remove(string key)
{
	Table->Remove(key);
}

// ����� value �� key
string Map::Find(string key)
{
	return Table->Find(key);
}

// �������� �������
void Map::Delete()
{
	Table->Delete();
}

// ��������: �������� ������� ���� ��� ���
bool Map::Contains(string key)
{
	int hash = Table->Hash(key);
	Node* current = &Table->Array[hash];

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
	return Table->Length == 0;
}

// ����� ������� �� �����
void Print(Map* map)
{
	Node* current;

	cout << "\n\t�������\n\n";
	cout << "����\t:\t��������\n";
	for (int i = 0; i < map->Table->Size; i++)
	{
		current = &map->Table->Array[i];
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