#pragma once
#include <ctime>
struct TreapNode
{
	//TODO: Зачем эти комментарии?
	int Key;	// Ключ
	int Priority;	// Приоритет

	TreapNode* Left;	// Указатель на левое поддерево
	TreapNode* Right;	// Указатель на правое поддерево

	TreapNode(int key)
	{
		//TODO: nullptr
		srand(time(0));

		Key = key;
		//TODO: Зачем эти комментарии?
		// Приоритету присваивается случайное значение от 0 до 99
		Priority = rand() % 100;

		Left = nullptr;
		Right = nullptr;
	}

	TreapNode(int key, int priority, TreapNode* left, TreapNode* right)
	{
		Key = key;
		Priority = priority;
		Left = left;
		Right = right;
	}
};