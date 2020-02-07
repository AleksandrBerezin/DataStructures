#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"

using namespace std;
using std::string;

const int fillFactor = 1;	// ����������� ���������� ��� �������
const double growthFactor = 1.5;

// ������������� ��������� �������
void HashTable::Init()
{
	for (int i = 0; i < Size; i++)
	{
		KeyValueArray[i] = *new Node;
	}
}

// ���������� � ������� ������ key-value
void HashTable::Add(string& key, string& value)
{
	// ���� ���������� ���������� ������� >= 1
	// �������� ������� ���������������
	if (double(CurrentLength) / double(Size) >= fillFactor)
	{
		Rehashing();
	}

	int hash = CountHash(key);

	if (KeyValueArray[hash].Key.empty())
	{
		KeyValueArray[hash].Key = key;
		KeyValueArray[hash].Value = value;
		CurrentLength++;
	}
	else
	{
		ResolveCollision(hash, key, value);
	}
}

// �������� �� ������� ������ key-value
void HashTable::Remove(string& key)
{
	int hash = CountHash(key);

	if (KeyValueArray[hash].Key.empty())
	{
		cout << "�������� � ����� ������ ���.\n";
		return;
	}
	
	Node* current = &KeyValueArray[hash];

	while (current != nullptr)
	{
		Node* prev = nullptr;

		if (current->Key == key)
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

			CurrentLength--;
			return;
		}

		prev = current;
		current = current->Next;
	}

	cout << "�������� � ����� ������ ���.\n";
}

// ����� value �� key
string HashTable::Find(string& key)
{
	int hash = CountHash(key);
	Node* current = &KeyValueArray[hash];

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
int HashTable::CountHash(string& key)
{
	int hash = 0;
	//TODO: Naming(Done)
	int exponent = 0;
	int arg = Size - 1;

	for (int i = 0; i < (key).length(); i++)
	{
		int num = pow(arg, exponent);
		hash = (hash + int(&(key[i])) * num) % Size;
		exponent++;

		if (hash < 0)
		{
			hash = 0 - hash;
		}
	}

	return hash;
}

// ������� ���������� �������� ������� �������
void HashTable::ResolveCollision(int hash, string& key, string& value)
{
	Node* current = &KeyValueArray[hash];
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
	prev->Next = current;
	CurrentLength++;
}

// ��������������� (���������� ������� �������)
void HashTable::Rehashing()
{
	int oldSize = Size;
	//TODO: ������� � ����������� ���������(Done)
	Size = Size * growthFactor;
	CurrentLength = 0;

	Node* newArray = new Node[Size];
	Node* oldArray = KeyValueArray;
	KeyValueArray = newArray;

	Init();
	
	// ��� �������� ������ ������� ����������� � ����� �������
	for (int i = 0; i < oldSize; i++)
	{
		Node* current = &oldArray[i];

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
	delete[] KeyValueArray;
}

// ��������: ���� �������(true) ��� ���(false)
bool HashTable::IsEmpty()
{
	return CurrentLength == 0;
}