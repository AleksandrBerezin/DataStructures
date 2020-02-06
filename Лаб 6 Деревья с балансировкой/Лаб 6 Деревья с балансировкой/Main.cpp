#include <iostream>
#include "AVLTreeNode.h"
#include "AVLTree.h"
#include "RBTreeNode.h"
#include "RBTree.h"
#include "MenuAVLTree.h"
#include "MenuRBTree.h"
#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	AVLTree* avlTree = new AVLTree;
	RBTree* rbTree = new RBTree;

	bool exit = false;

	while (!exit)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. АВЛ-Дерево.\n"
			<< "2. Красно-черное дерево.\n"
			<< "0. Выход.\n\n";

		int number = InputInt();
		bool isBack = false;
		switch (number)
		{
			case 1:
			{
				Menu(avlTree);
				break;
			}
			case 2:
			{
				Menu(rbTree);
				break;
			}
			case 0:
			{
				if (avlTree != nullptr)
				{
					avlTree->Clear(avlTree->Root);
					delete avlTree;
					avlTree = nullptr;
				}
				if (rbTree != nullptr)
				{
					rbTree->Clear(rbTree->Root);
					delete rbTree;
					rbTree = nullptr;
				}

				exit = true;
				break;
			}
			default:
			{
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

}