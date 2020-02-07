#pragma once

#include <iostream>
#include "..\Лаб 6 Деревья с балансировкой\Лаб 6 Деревья с балансировкой\AVLTree.h"

using namespace std;

/*
	Функции для авл-дерева
*/

//Проверка, что авл-дерево не создано или пустое
bool IsAVLTreeNotCreateOrEmpty(AVLTree* avlTree)
{
	if (avlTree == nullptr || avlTree->IsEmpty())
	{
		cout << "Дерево пустое.\n";
		return true;
	}

	return false;
}

//Вычисление времени работы функции
void ShowFunctionRunTimeAndCountRotate(AVLTree* avlTree, clock_t begin)
{
	clock_t end = clock();

	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Время - " << seconds << " секунд;\n";
	cout << "Количество поворотов - " << avlTree->CountRotate
		<< ".\n";
}

//Вставка count элементов в авл-дерево
void InsertCountElement(AVLTree* avlTree, int count)
{
	for (int i = 0; i < count; i++)
	{
		avlTree->Root = avlTree->Insert(avlTree->Root, i);
	}
}

// Вывод дерева
void Print(AVLTreeNode* node, int level)
{
	if (node != nullptr)
	{
		Print(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "\n";

		Print(node->Left, level + 1);
	}
}