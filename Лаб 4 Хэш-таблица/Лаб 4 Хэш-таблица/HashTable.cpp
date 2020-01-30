#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"

using namespace std;
using std::string;

// ������������� ��������� �������
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

// ���������� � ������� ������ key-value
void HashTable::Add(string key, string value)
{
	// ���� ���������� ���������� ������� >= 1
	// �������� ������� ���������������
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

// �������� �� ������� ������ key-value
void HashTable::Remove(string key)
{
	int hash = Hash(key);

	if (Array[hash].Key.empty())
	{
		cout << "�������� � ����� ������ ���.\n";
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
				if (prev != nullptr)	// ���� ������ ���������� �������
				{
					prev->Next = nullptr;
				}
				else	// ������ ������
				{
					Array[hash].Key = "";
					Array[hash].Value = "";
				}
			}
			else
			{
				if (prev != nullptr)	// ���� ���������� � �����������
				{
					prev->Next = current->Next;
				}
				else	// ���� ������ ����������� �������
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

	cout << "�������� � ����� ������ ���.\n";
}

// ����� value �� key
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

	return "";	// ������� �� ������
}

// ���-������� (����� �������) 
// h(k) = (s0 * a^0 + s1 * a^1 + ... s(n-1) * a^(n-1) +sn * a ^ n) % m
// a � m - ������� �������
// sn - ������ ��� �������� n, m - ������ �������
int HashTable::Hash(string key)
{
	int hash = 0;
	int n = 0;	// ���������� �������
	int arg = Size - 1;

	for (int i = 0; i < key.length(); i++)
	{
		int a = pow(arg, n);	// ���������� arg � ������� n
		hash = (hash + int(key[i]) * a) % Size;
		n++;
	}

	return hash;
}

// ������� ���������� �������� ������� �������
void HashTable::Collision(int hash, string key, string value)
{
	Node* current = &Array[hash];
	Node* prev = nullptr;

	while (current != nullptr)
	{
		// ������ �� ������������ ��� key-value
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

// ��������������� (���������� ������� �������)
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
	
	// ��� �������� ������ ������� ����������� � ����� �������
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

// �������� �������
void HashTable::Delete()
{
	delete[] Array;
}

// ��������: ���� �������(true) ��� ���(false)
bool HashTable::IsEmpty()
{
	return Length == 0;
}

// ����� ������� �� �����
void Print(HashTable* hashTable)
{
	Node* current;

	cout << "\n\t���-�������\n\n";
	cout << "������\t:\t����\t:\t��������\n";
	for (int i = 0; i < hashTable->Size; i++)
	{
		current = &hashTable->Array[i];
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