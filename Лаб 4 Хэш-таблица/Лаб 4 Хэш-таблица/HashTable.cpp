#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"

using namespace std;
using std::string;

const int fillFactor = 1;	// Коэффициент заполнения хеш таблицы
const double growthFactor = 1.5;

// Инициализация элементов массива
void HashTable::Init()
{
	for (int i = 0; i < Size; i++)
	{
		KeyValueArray[i] = *new Node;
	}
}

// Добавление в таблицу набора key-value
void HashTable::Add(string* key, string* value)
{
	// Если коффициент заполнения таблицы >= 1
	// вызываем функцию перехеширования
	if (double(Length) / double(Size) >= fillFactor)
	{
		Rehashing();
	}

	int hash = HashCalculate(key);

	if (KeyValueArray[hash].Key.empty())
	{
		KeyValueArray[hash].Key = *key;
		KeyValueArray[hash].Value = *value;
		Length++;
	}
	else
	{
		CollisionResolution(hash, key, value);
	}
}

// Удаление из таблицы набора key-value
void HashTable::Remove(string* key)
{
	int hash = HashCalculate(key);

	if (KeyValueArray[hash].Key.empty())
	{
		cout << "Элемента с таким ключом нет.\n";
		return;
	}
	
	Node* current = &KeyValueArray[hash];

	while (current != nullptr)
	{
		Node* prev = nullptr;

		if (current->Key == *key)
		{
			if (current->Next == nullptr)
			{
				if (prev != nullptr)
				{
					prev->Next = nullptr;
				}
				else
				{
					KeyValueArray[hash].Key = "";
					KeyValueArray[hash].Value = "";
				}
			}
			else
			{
				if (prev != nullptr)
				{
					prev->Next = current->Next;
				}
				else
				{
					KeyValueArray[hash] = *current->Next;
				}
			}

			Length--;
			return;
		}

		prev = current;
		current = current->Next;
	}

	cout << "Элемента с таким ключом нет.\n";
}

// Поиск value по key
string HashTable::Find(string* key)
{
	int hash = HashCalculate(key);
	Node* current = &KeyValueArray[hash];

	while (current != nullptr)
	{
		if (current->Key == *key)
		{
			return current->Value;
		}
		current = current->Next;
	}

	return "";	// Элемент не найден
}

// Хеш-функция (Метод Пирсона) 
// h(k) = (s0 * a^0 + s1 * a^1 + ... s(n-1) * a^(n-1) +sn * a ^ n) % m
// a и m - взаимно простые
// sn - символ под индексом n, m - размер таблицы
int HashTable::HashCalculate(string* key)
{
	int hash = 0;
	//TODO: Naming(Done)
	int exponent = 0;
	int arg = Size - 1;

	for (int i = 0; i < (*key).length(); i++)
	{
		int num = pow(arg, exponent);
		hash = (hash + int(&(key[i])) * num) % Size;
		exponent++;
	}

	return hash;
}

// Функция разрешения коллизий методом цепочек
void HashTable::CollisionResolution(int hash, string* key, string* value)
{
	Node* current = &KeyValueArray[hash];
	Node* prev = nullptr;

	while (current != nullptr)
	{
		// Запрет на дублирование пар key-value
		if (current->Key == *key && current->Value == *value)
		{
			return;
		}

		prev = current;
		current = current->Next;
	}

	current = new Node;
	current->Key = *key;
	current->Value = *value;
	current->Next = nullptr;
	prev->Next = current;
	Length++;
}

// Перехеширование (увеличение размера таблицы)
void HashTable::Rehashing()
{
	int oldSize = Size;
	//TODO: Вынести в именованную константу(Done)
	Size = Size * growthFactor;
	Length = 0;

	Node* newArray = new Node[Size];
	Node* oldArray = KeyValueArray;
	KeyValueArray = newArray;

	Init();
	
	// Все элементы старой таблицы переносятся в новую таблицу
	for (int i = 0; i < oldSize; i++)
	{
		Node* current = &oldArray[i];

		if (current->Key.empty())
		{
			continue;
		}

		while (current != nullptr)
		{
			Add(&current->Key, &current->Value);
			current = current->Next;
		}
	}

	delete[] oldArray;
}

// Удаление таблицы
void HashTable::Delete()
{
	delete[] KeyValueArray;
}

// Проверка: пуст словарь(true) или нет(false)
bool HashTable::IsEmpty()
{
	return Length == 0;
}

// Вывод таблицы на экран
void Print(HashTable* hashTable)
{
	cout << "\n\tХеш-таблица\n\n";
	cout << "Индекс\t:\tКлюч\t:\tЗначение\n";
	for (int i = 0; i < hashTable->Size; i++)
	{
		Node* current = &hashTable->KeyValueArray[i];
		if (current->Key.empty())
		{
			cout << i << "\t:\tПусто\t:\tПусто\n";
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