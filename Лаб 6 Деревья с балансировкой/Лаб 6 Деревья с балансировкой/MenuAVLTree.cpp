#include <iostream>
#include <ctime>
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include "MenuAVLTree.h"
#include "..\..\Libraries\CommonLibrary.h"
#include "..\..\Libraries\AVLTreeLibrary.h"

using namespace std;

void Menu(AVLTree*& avlTree)
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
				if (avlTree == nullptr)
				{
					avlTree = new AVLTree();
				}

				int value = InputIntValue();
				cout << "\n";

				AVLTreeNode* node;

				do
				{
					node = avlTree->Find(value);

					if (node != nullptr)
					{
						cout << "������� � ����� ������ ������������ "
							<< "� ������, ������� ������ ����: ";
						value = InputInt();
						cout << "\n";
					}
				} while (node != nullptr);

				avlTree->Root = avlTree->Insert(avlTree->Root, value);
				Print(avlTree->Root, 0);
				break;
			}
			case 2:
			{
				if (IsAVLTreeNotCreateOrEmpty(avlTree))
				{
					break;
				}

				int value = InputIntValue();
				cout << "\n";

				AVLTreeNode* node;

				do
				{
					node = avlTree->Find(value);

					if (node == nullptr)
					{
						cout << "�������� � ����� ������ ��� "
							<< "� ������, ������� ������ ����: ";
						value = InputInt();
						cout << "\n";
					}
				} while (node == nullptr);

				avlTree->Root = avlTree->Remove(avlTree->Root, value);
				Print(avlTree->Root, 0);
				break;
			}
			case 3:
			{
				if (IsAVLTreeNotCreateOrEmpty(avlTree))
				{
					break;
				}

				int key = InputIntKey();
				cout << "\n";

				AVLTreeNode* node = avlTree->Find(key);
				cout << (node == nullptr 
					? "������ �������� ���.\n"
					: "������� ������.\n");

				break;
			}
			case 4:
			{
				if (avlTree == nullptr)
				{
					break;
				}

				avlTree->Clear(avlTree->Root);
				delete avlTree;
				avlTree = nullptr;
				break;
			}
			case 5:
			{
				if (IsAVLTreeNotCreateOrEmpty(avlTree))
				{
					break;
				}

				cout << "\n";
				Print(avlTree->Root, 0);
				break;
			}
			case 6:
			{
				if (avlTree != nullptr)
				{
					avlTree->Clear(avlTree->Root);
					delete avlTree;
				}

				avlTree = new AVLTree();

				cout << "������� ���������� ��������� ������: \n";
				int count = InputInt();
				clock_t begin = clock();

				InsertCountElement(avlTree, count);
				
				ShowFunctionRunTimeAndCountRotate(avlTree, begin);

				avlTree->Clear(avlTree->Root);
				delete avlTree;
				avlTree = nullptr;
				break;
			}
			case 7:
			{
				if (avlTree != nullptr)
				{
					avlTree->Clear(avlTree->Root);
					delete avlTree;
				}

				avlTree = new AVLTree();

				cout << "������� ���������� ��������� ������: \n";
				int count = InputInt();
				//TODO: �����(Done)
				InsertCountElement(avlTree, count);
				avlTree->CountRotate = 0;

				clock_t begin = clock();
				for (int i = 0; i < count; i++)
				{
					avlTree->Root = avlTree->Remove(avlTree->Root, i);
				}
				
				ShowFunctionRunTimeAndCountRotate(avlTree, begin);

				avlTree->Clear(avlTree->Root);
				delete avlTree;
				avlTree = nullptr;
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