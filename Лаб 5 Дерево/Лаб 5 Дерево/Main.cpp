#include <iostream>
#include <ctime>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include "TreapNode.h"
#include "Treap.h"
#include "MenuBinaryTree.h"
#include "MenuTreap.h"
#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	BinaryTree* binaryTree = new BinaryTree();
	Treap* treap = new Treap();

	bool isExit = false;

	while (!isExit)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. Бинарное дерево поиска.\n"
			<< "2. Декартово дерево.\n"
			<< "0. Выход.\n\n";

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

				isExit = true;
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