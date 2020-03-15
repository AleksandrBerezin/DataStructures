#include <iostream>
#include "AVLTreeNode.h"
#include "AVLTree.h"
#include "RBTreeNode.h"
#include "RBTree.h"
#include "Menus/MenuAVLTree.h"
#include "Menus/MenuRBTree.h"
#include "../Common/CommonLibrary.h"

using namespace std;

void MenuLab6()
{
	AVLTree* avlTree = new AVLTree;
	RBTree* rbTree = new RBTree;

	bool isBack = false;

	while (!isBack)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. АВЛ-Дерево.\n"
			<< "2. Красно-черное дерево.\n"
			<< "0. Назад.\n\n";

		switch (InputInt())
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

				isBack = true;
				break;
			}
			default:
			{
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}