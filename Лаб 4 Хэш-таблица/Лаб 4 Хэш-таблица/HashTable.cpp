#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"

using namespace std;
using std::string;

// Инициализация элементов массива
void HashTable::Init()
{
	for (int i = 0; i < Size; i++)
	{
		Array[i] = *new Node;
		Array[i].Key = "";
		Array[i].Value = "";
		Array[i].Next = nullptr;
	}
}

// Добавление в таблицу набора key-value
void HashTable::Add(string key, string value)
{
	// Если коффициент заполнения таблицы >= 1
	// вызываем функцию перехеширования
	if (double(Length) / double(Size) >= 1)
	{
		Rehashing();
	}

	int hash = Hash(key);

	if (Array[hash].Key.empty())
	{
		Array[hash].Key = key;
		Array[hash].Value = value;
		Length++;
	}
	else
	{
		Collision(hash, key, value);
	}
}

// Удаление из таблицы набора key-value
void HashTable::Remove(string key)
{
	int hash = Hash(key);

	if (Array[hash].Key.empty())
	{
		cout << "Элемента с таким ключом нет.\n";
		return;
	}
	
	Node* current = &Array[hash];
	Node* prev = nullptr;

	while (current != nullptr)
	{
		if (current->Key == key)
		{
			if (current->Next == nullptr)
			{
				if (prev != nullptr)	// Есть только предыдущий элемент
				{
					prev->Next = nullptr;
				}
				else	// Ячейка пустая
				{
					Array[hash].Key = "";
					Array[hash].Value = "";
				}
			}
			else
			{
				if (prev != nullptr)	// Есть предыдущий и последующий
				{
					prev->Next = current->Next;
				}
				else	// Есть только последующий элемент
				{
					Array[hash] = *current->Next;
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
string HashTable::Find(string key)
{
	int hash = Hash(key);
	Node* current = &Array[hash];

	while (current != nullptr)
	{
		if (current->Key == key)
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
int HashTable::Hash(string key)
{
	int hash = 0;
	int n = 0;	// Показатель степени
	int arg = Size - 1;

	for (int i = 0; i < key.length(); i++)
	{
		int a = pow(arg, n);	// Возведение arg в степень n
		hash = (hash + int(key[i]) * a) % Size;
		n++;
	}

	return hash;
}

// Функция разрешения коллизий методом цепочек
void HashTable::Collision(int hash, string key, string value)
{
	Node* current = &Array[hash];
	Node* prev = nullptr;

	while (current != nullptr)
	{
		// Запрет на дублирование пар key-value
		if (current->Key == key && current->Value == value)
		{
			return;
		}

		prev = current;
		current = current->Next;
	}

	current = new Node;
	current->Key = key;
	current->Value = value;
	current->Next = nullptr;
	prev->Next = current;
	Length++;
}

// Перехеширование (увеличение размера таблицы)
void HashTable::Rehashing()
{
	int oldSize = Size;
	Size = Size * 1.5;
	Length = 0;

	Node* newArray = new Node[Size];
	Node* oldArray = Array;
	Array = newArray;
	Node* current;

	Init();
	
	// Все элементы старой таблицы переносятся в новую таблицу
	for (int i = 0; i < oldSize; i++)
	{
		current = &oldArray[i];

		if (current->Key.empty())
		{
			continue;
		}

		while (current != nullptr)
		{
			Add(current->Key, current->Value);
			current = current->Next;
		}
	}

	delete[] oldArray;
}

// Удаление таблицы
void HashTable::Delete()
{
	delete[] Array;
}

// Проверка: пуст словарь(true) или нет(false)
bool HashTable::IsEmpty()
{
	return Length == 0;
}

// Вывод таблицы на экран
void Print(HashTable* hashTable)
{
	Node* current;

	cout << "\n\tХеш-таблица\n\n";
	cout << "Индекс\t:\tКлюч\t:\tЗначение\n";
	for (int i = 0; i < hashTable->Size; i++)
	{
		current = &hashTable->Array[i];
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