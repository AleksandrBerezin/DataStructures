#include <iostream>
#include "../HashTable.h"
#include "MenuHashTable.h"
#include "../../Common/CommonLibrary.h"
#include "../../Common/Lab4/HashTableLibrary.h"

using namespace std;

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

				string key = InputStringKey();
				string value = InputStringValue();

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

				string key = InputStringKey();

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

				string key = InputStringKey();

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