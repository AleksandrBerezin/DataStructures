#pragma once

#include <iostream>
#include "..\Лаб 6 Деревья с балансировкой\Лаб 6 Деревья с балансировкой\RBTree.h"

using namespace std;

/*
	Функции для красно-черного дерева
*/

//Проверка, что красно-черное дерево не создано или пустое
bool IsRBTreeNotCreateOrEmpty(RBTree* rbTree)
{
	if (rbTree == nullptr || rbTree->IsEmpty())
	{
		cout << "Дерево пустое.\n";
		return true;
	}

	return false;
}

//Вычисление времени работы функции
void ShowFunctionRunTimeAndCountRotate(RBTree* rbTree, clock_t begin)
{
	clock_t end = clock();

	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Время - " << seconds << " секунд;\n";
	cout << "Количество поворотов - " << rbTree->CountRotate
		<< ".\n";
}

//Вставка count элементов в красно-черное дерево
void InsertCountElement(RBTree* rbTree, int count)
{
	for (int i = 0; i < count; i++)
	{
		rbTree->Insert(i);
	}
}

// Вывод дерева
void Print(RBTree* rbTree, RBTreeNode* node, int level)
{
	if (node != rbTree->Nil)
	{
		Print(rbTree, node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}

		string color = node->IsBlack ? "B" : "R";
		cout << node->Key << " : " << color << "\n";

		Print(rbTree, node->Left, level + 1);
	}
}