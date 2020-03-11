#pragma once
#include <string>

using std::string;

struct HashTableNode
{
	string Key = "";
	string Value = "";
	HashTableNode* Next = nullptr;
};