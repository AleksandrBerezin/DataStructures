#pragma once
#include <ctime>

struct TreapNode
{
	int Key;
	int Priority;
	TreapNode* Left;
	TreapNode* Right;

	TreapNode(int key)
	{
		srand(time(nullptr));
		TreapNode(key, rand() % 100, nullptr, nullptr);
	}

	TreapNode(int key, int priority, TreapNode* left, TreapNode* right)
	{
		Key = key;
		Priority = priority;
		Left = left;
		Right = right;
	}
};