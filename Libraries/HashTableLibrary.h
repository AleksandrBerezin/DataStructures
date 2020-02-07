#pragma once

#include <iostream>
#include <string>
#include "..\��� 4 ���-�������\��� 4 ���-�������\HashTable.h"

using namespace std;
using std::string;

/*
	������� ��� ���-�������
*/

//��������, ��� ���-������� �� ������� ��� ����
bool IsHashTableNotCreateOrEmpty(HashTable* hashTable)
{
	if (hashTable == nullptr || hashTable->IsEmpty())
	{
		cout << "���-������� ������.\n";
		return true;
	}

	return false;
}

//��������, ��� ���-������� �� �������
bool IsHashTableNotCreate(HashTable* hashTable)
{
	if (hashTable == nullptr)
	{
		cout << "���-������� ������.\n";
		return true;
	}

	return false;
}

// ����� ������� �� �����
void Print(HashTable* hashTable)
{
	cout << "\n\t���-�������\n\n";
	cout << "������\t:\t����\t:\t��������\n";
	for (int i = 0; i < hashTable->Size; i++)
	{
		Node* current = &hashTable->KeyValueArray[i];
		if (current->Key.empty())
		{
			cout << i << "\t:\t�����\t:\t�����\n";
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