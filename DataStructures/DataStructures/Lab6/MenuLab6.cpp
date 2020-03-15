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
		cout << "\n�������� ��������� ������ ��� ������:\n";
		cout << "1. ���-������.\n"
			<< "2. ������-������ ������.\n"
			<< "0. �����.\n\n";

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
				cout << "������ �������� �������, ���������� ��� ���.\n";
				break;
			}
		}
	}

	return;
}