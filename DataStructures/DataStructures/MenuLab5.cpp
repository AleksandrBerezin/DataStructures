#include <iostream>
#include "BinaryTree.h"
#include "Treap.h"
#include "MenuBinaryTree.h"
#include "MenuTreap.h"
#include "CommonLibrary.h"

using namespace std;

void MenuLab5()
{
	BinaryTree* binaryTree = new BinaryTree();
	Treap* treap = new Treap();

	bool isBack = false;

	while (!isBack)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. Бинарное дерево поиска.\n"
			<< "2. Декартово дерево.\n"
			<< "0. Назад.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				Menu(binaryTree);
				break;
			}
			case 2:
			{
				Menu(treap);
				break;
			}
			case 0:
			{
				if (binaryTree != nullptr)
				{
					binaryTree->Clear(binaryTree->Root);
					delete binaryTree;
					binaryTree = nullptr;
				}
				if (treap != nullptr)
				{
					treap->Clear(treap->Root);
					delete treap;
					treap = nullptr;
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