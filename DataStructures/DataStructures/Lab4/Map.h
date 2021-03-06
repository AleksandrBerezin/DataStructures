#pragma once
#include "HashTable.h"

using std::string;

struct Map
{
	HashTable* InternalHashTable;

	void Add(string& key, string& value);
	void Remove(string& key);
	string Find(string& key);
	void Delete();
	bool Contains(string& key);
	bool IsEmpty();

	Map()
	{
		InternalHashTable = new HashTable();
	}
};