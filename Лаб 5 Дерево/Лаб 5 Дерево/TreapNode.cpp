#include <iostream>
#include <ctime>
#include "TreapNode.h"

// »нициализаци€ узла декартового дерева
void TreapNode::Init(int key)
{
	srand(time(0));

	Key = key;
	// ѕриоритету присваиваетс€ случайное значение от 0 до 99
	Priority = rand() % 100;

	Left = nullptr;
	Right = nullptr;
}