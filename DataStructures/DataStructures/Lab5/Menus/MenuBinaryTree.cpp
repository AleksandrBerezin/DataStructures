#include <iostream>
#include "../BinaryTree.h"
#include "../BinaryTreeNode.h"
#include "MenuBinaryTree.h"
#include "../../Common/CommonLibrary.h"
#include "../../Common/Lab5/BinaryTreeLibrary.h"

using namespace std;

void Menu(BinaryTree*& binaryTree)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� ��������.\n"
			<< "2. �������� ��������.\n"
			<< "3. ����� ��������.\n"
			<< "4. ����� ��������� ������.\n"
			<< "5. ����� �������� ������.\n"
			<< "6. �������� ������.\n"
			<< "7. ����� ������ �� �����.\n"
			<< "0. �����.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (binaryTree == nullptr)
				{
					binaryTree = new BinaryTree();
				}

				int key = InputIntKey();
				cout << "\n";

				BinaryTreeNode* node;

				do
				{
					node = binaryTree->Find(key);

					if (node == nullptr)
					{
						cout << "������� � ����� ������ ������������ "
							<< "� ������, ������� ������ ����: ";
						key = InputInt();
						cout << "\n";
					}
				} while (node != nullptr);

				binaryTree->Insert(key);
				Print(binaryTree->Root, 0);
				break;
			}
			case 2:
			{
				if (IsBinaryTreeNotCreateOrEmpty(binaryTree))
				{
					break;
				}

				int key = InputIntKey();
				cout << "\n";

				BinaryTreeNode* node;

				do
				{
					node = binaryTree->Find(key);

					if (node == nullptr)
					{
						cout << "�������� � ����� ������ ��� "
							<< "� ������, ������� ������ ����: ";
						key = InputInt();
						cout << "\n";
					}
				} while (node == nullptr);

				binaryTree->Remove(key);
				Print(binaryTree->Root, 0);
				break;
			}
			case 3:
			{
				if (IsBinaryTreeNotCreateOrEmpty(binaryTree))
				{
					break;
				}

				int key = InputIntKey();
				cout << "\n";

				BinaryTreeNode* node = binaryTree->Find(key);
				cout << (node == nullptr
					? "������ �������� ���.\n"
					: "������� ������.\n");

				break;
			}
			case 4:
			{
				if (IsBinaryTreeNotCreateOrEmpty(binaryTree))
				{
					break;
				}

				BinaryTreeNode* max = binaryTree->FindMax();

				if (max == nullptr)
				{
					cout << "������ ������.\n";
					break;
				}

				cout << "������������ ������� ������ ����� " << max->Key << ".\n";
				break;
			}
			case 5:
			{
				if (IsBinaryTreeNotCreateOrEmpty(binaryTree))
				{
					break;
				}

				BinaryTreeNode* min = binaryTree->FindMin();

				if (min == nullptr)
				{
					cout << "������ ������.\n";
					break;
				}

				cout << "����������� ������� ������ ����� " << min->Key << ".\n";
				break;
			}
			case 6:
			{
				if (binaryTree == nullptr)
				{
					break;
				}

				binaryTree->Clear(binaryTree->Root);
				delete binaryTree;
				binaryTree = nullptr;
				break;
			}
			case 7:
			{
				if (IsBinaryTreeNotCreateOrEmpty(binaryTree))
				{
					break;
				}

				cout << "\n";
				Print(binaryTree->Root, 0);
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