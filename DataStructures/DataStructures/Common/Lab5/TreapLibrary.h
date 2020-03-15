#pragma once

#include <iostream>
#include "../../Lab5/Treap.h"

using namespace std;

/*
	Функции для декартового дерева
*/

//Проверка, что стек не создан или пуст
bool IsTreapNotCreateOrEmpty(Treap* treap)
{
	if (treap == nullptr || treap->IsEmpty())
	{
		cout << "Дерево пустое.\n";
		return true;
	}

	return false;
}

// Вывод дерева на экран
void Print(TreapNode* node, int level)
{
	if (node != nullptr)
	{
		Print(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "; " << node->Priority << "\n";

		Print(node->Left, level + 1);
	}
}