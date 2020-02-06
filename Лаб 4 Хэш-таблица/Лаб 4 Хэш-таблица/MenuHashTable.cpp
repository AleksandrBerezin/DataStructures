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
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента в хэш-таблицу.\n"
			<< "2. Удаление элемента из хэш-таблицы.\n"
			<< "3. Поиск значения по ключу.\n"
			<< "4. Удаление хэш-таблицы.\n"
			<< "5. Вывод хэш-таблицы на экран.\n"
			<< "0. Назад.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (hashTable == nullptr)
				{
					hashTable = new HashTable();
				}

				cout << "Введите ключ: ";
				string key = SubKey(InputString());
				cout << "Введите значение: ";
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

				cout << "Введите ключ: ";
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

				cout << "Введите ключ: ";
				string key = SubKey(InputString());

				string value = hashTable->Find(key);
				if (value == "")
				{
					cout << "Элемента с таким ключом нет.\n";
				}
				else
				{
					cout << "Элементу с ключом " << key
						<< " соответствует значение " << value << "\n";
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
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}

//Проверка, что стек не создан или пуст
bool IsHashTableNotCreateOrEmpty(HashTable* hashTable)
{
	if (hashTable == nullptr || hashTable->IsEmpty())
	{
		cout << "Хеш-таблица пустая.\n";
		return true;
	}

	return false;
}

//Проверка, что стек не создан
bool IsHashTableNotCreate(HashTable* hashTable)
{
	if (hashTable == nullptr)
	{
		cout << "Хеш-таблица пустая.\n";
		return true;
	}

	return false;
}