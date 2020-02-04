#pragma once
using std::string;

struct Map
{
	//TODO: Naming
	HashTable* Table;

	void Add(string key, string value);
	void Remove(string key);
	string Find(string key);
	void Delete();
	bool Contains(string key);
	bool IsEmpty();

	Map()
	{
		Table = new HashTable();
	}
};

void Print(Map* map);