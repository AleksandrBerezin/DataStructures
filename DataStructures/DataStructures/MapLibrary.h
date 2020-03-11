#pragma once

#include <iostream>
#include <cstring>
#include "Map.h"

using namespace std;
using std::string;

/*
	������� ��� �������
*/

//��������, ��� ������� �� ������ ��� ����
bool IsMapNotCreateOrEmpty(Map* map)
{
	if (map == nullptr || map->IsEmpty())
	{
		cout << "������� ����.\n";
		return true;
	}

	return false;
}

//��������, ��� ������� �� ������
bool IsMapNotCreate(Map* map)
{
	if (map == nullptr)
	{
		cout << "������� ����.\n";
		return true;
	}

	return false;
}

// ����� ������� �� �����
void Print(Map* map)
{
	cout << "\n\t�������\n\n";
	cout << "����\t:\t��������\n";
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