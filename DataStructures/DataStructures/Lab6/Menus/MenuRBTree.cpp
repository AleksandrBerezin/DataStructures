#include <iostream>
#include <ctime>
#include "../RBTree.h"
#include "../RBTreeNode.h"
#include "MenuRBTree.h"
#include "../../Common/CommonLibrary.h"
#include "../../Common/Lab6/RBTreeLibrary.h"

using namespace std;

void Menu(RBTree*& rbTree)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� ��������.\n"
			<< "2. �������� ��������.\n"
			<< "3. ����� ��������.\n"
			<< "4. �������� ������.\n"
			<< "5. ����� ������ �� �����.\n"
			<< "6. ��������� ������� ��� �������.\n"
			<< "7. ��������� ������� ��� ��������.\n"
			<< "0. �����.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (rbTree == nullptr)
				{
					rbTree = new RBTree();
				}

				int value = InputIntValue();
				cout << "\n";

				RBTreeNode* node;

				do
				{
					node = rbTree->Find(value);

					if (node != nullptr)
					{
						cout << "������� � ����� ������ ������������ "
							<< "� ������, ������� ������ ����: ";
						value = InputInt();
						cout << "\n";
					}
				} while (node != nullptr);

				rbTree->Insert(value);
				Print(rbTree, rbTree->Root, 0);
				break;
			}
			case 2:
			{
				if (IsRBTreeNotCreateOrEmpty(rbTree))
				{
					break;
				}

				int value = InputIntValue();
				cout << "\n";

				RBTreeNode* node;

				do
				{
					node = rbTree->Find(value);

					if (node == nullptr)
					{
						cout << "�������� � ����� ������ ��� "
							<< "� ������, ������� ������ ����: ";
						value = InputInt();
						cout << "\n";
					}
				} while (node == nullptr);

				rbTree->Remove(value);
				Print(rbTree, rbTree->Root, 0);
				break;
			}
			case 3:
			{
				if (IsRBTreeNotCreateOrEmpty(rbTree))
				{
					break;
				}

				int key = InputIntKey();
				cout << "\n";

				RBTreeNode* node = rbTree->Find(key);

				cout << (node == rbTree->Nil
					? "������ �������� ���.\n"
					: "������� ������.\n");

				break;
			}
			case 4:
			{
				if (rbTree == nullptr)
				{
					break;
				}

				rbTree->Clear(rbTree->Root);
				delete rbTree;
				rbTree = nullptr;
				break;
			}
			case 5:
			{
				if (IsRBTreeNotCreateOrEmpty(rbTree))
				{
					break;
				}

				cout << "\n";
				Print(rbTree, rbTree->Root, 0);
				break;
			}
			case 6:
			{
				if (rbTree != nullptr)
				{
					rbTree->Clear(rbTree->Root);
					delete rbTree;
				}

				rbTree = new RBTree();

				cout << "������� ���������� ��������� ������: \n";
				int count = InputInt();
				clock_t begin = clock();

				InsertCountElement(rbTree, count);

				ShowFunctionRunTimeAndCountRotate(rbTree, begin);

				rbTree->Clear(rbTree->Root);
				delete rbTree;
				rbTree = nullptr;
				break;
			}
			case 7:
			{
				if (rbTree != nullptr)
				{
					rbTree->Clear(rbTree->Root);
					delete rbTree;
				}

				rbTree = new RBTree();

				cout << "������� ���������� ��������� ������: \n";
				int count = InputInt();

				InsertCountElement(rbTree, count);
				rbTree->CountRotate = 0;

				clock_t begin = clock();
				for (int i = 0; i < count; i++)
				{
					rbTree->Remove(i);
				}

				ShowFunctionRunTimeAndCountRotate(rbTree, begin);

				rbTree->Clear(rbTree->Root);
				delete rbTree;
				rbTree = nullptr;
				break;
			}
			case 0:
			{
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