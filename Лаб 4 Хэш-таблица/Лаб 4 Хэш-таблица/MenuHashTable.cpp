#include <iostream>
#include "HashTable.h"
#include "MenuHashTable.h"
#include "Functions.h"

using namespace std;

bool IsHashTableNotCreateOrEmpty(HashTable* hashTable);
bool IsHashTableNotCreate(HashTable* hashTable);

void Menu(HashTable*& hashTable)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� �������� � ���-�������.\n"
			<< "2. �������� �������� �� ���-�������.\n"
			<< "3. ����� �������� �� �����.\n"
			<< "4. �������� ���-�������.\n"
			<< "5. ����� ���-������� �� �����.\n"
			<< "0. �����.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (hashTable == nullptr)
				{
					hashTable = new HashTable();
				}

				cout << "������� ����: ";
				string key = SubKey(InputString());
				cout << "������� ��������: ";
				string value = InputString();

				hashTable->Add(key, value);
				Print(hashTable);
				break;
			}
			case 2:
			{
				if (IsHashTableNotCreateOrEmpty(hashTable))
				{
					break;
				}

				cout << "������� ����: ";
				string key = SubKey(InputString());

				hashTable->Remove(key);
				Print(hashTable);
				break;
			}
			case 3:
			{
				if (IsHashTableNotCreateOrEmpty(hashTable))
				{
					break;
				}

				cout << "������� ����: ";
				string key = SubKey(InputString());

				string value = hashTable->Find(key);
				if (value == "")
				{
					cout << "�������� � ����� ������ ���.\n";
				}
				else
				{
					cout << "�������� � ������ " << key
						<< " ������������� �������� " << value << "\n";
				}

				break;
			}
			case 4:
			{
				if (IsHashTableNotCreate(hashTable))
				{
					break;
				}

				hashTable->Delete();
				delete hashTable;
				hashTable = nullptr;
				break;
			}
			case 5:
			{
				if (IsHashTableNotCreate(hashTable))
				{
					break;
				}

				Print(hashTable);
				break;
			}
			case 0:
			{
				isBack = true;
				break;
			}
			default:
			{
				cout << "������ �������� �������, ���������� ��� ���.\n";
				break;
			}
		}
	}

	return;
}

//��������, ��� ���� �� ������ ��� ����
bool IsHashTableNotCreateOrEmpty(HashTable* hashTable)
{
	if (hashTable == nullptr || hashTable->IsEmpty())
	{
		cout << "���-������� ������.\n";
		return true;
	}

	return false;
}

//��������, ��� ���� �� ������
bool IsHashTableNotCreate(HashTable* hashTable)
{
	if (hashTable == nullptr)
	{
		cout << "���-������� ������.\n";
		return true;
	}

	return false;
}