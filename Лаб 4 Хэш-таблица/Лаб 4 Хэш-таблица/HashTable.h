#pragma once
using std::string;

//TODO: Naming
const int SIZE = 8;	// ��������� �������� ������� �������

struct HashTable
{
	//TODO: Naming
	Node* Array;	// ������, ���������� �������� ���� ����-��������
	int Length;	// ���������� ��������� � �������
	int Size;	// ������ �������
	
	void Init();
	//TODO: ������������� ������ ��� �������� string?
	void Add(string key, string value);
	void Remove(string key);
	string Find(string key);
	//TODO: Naming
	int Hash(string key);
	//TODO: Naming
	void Collision(int hash, string key, string value);
	void Rehashing();
	void Delete();
	bool IsEmpty();

	HashTable()
	{
		Array = new Node[SIZE];
		Length = 0;
		Size = SIZE;

		Init();
	}
};

void Print(HashTable* hashTable);