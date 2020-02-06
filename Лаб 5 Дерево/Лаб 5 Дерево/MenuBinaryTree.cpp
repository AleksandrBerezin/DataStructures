#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "MenuBinaryTree.h"
#include "Functions.h"

using namespace std;

bool IsBinaryTreeNotCreateOrEmpty(BinaryTree* binaryTree);

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

				cout << "������� ���� ��������: ";
				int key = InputInt();
				cout << "\n";

				binaryTree->Insert(key);
				Print(binaryTree->Root, 0);
				break;
			}
			case 2:
			{
				//TODO: �����(Done)
				if (IsBinaryTreeNotCreateOrEmpty(binaryTree))
				{
					break;
				}

				cout << "������� ���� ��������: ";
				int key = InputInt();
				cout << "\n";

				binaryTree->Remove(key);
				Print(binaryTree->Root, 0);
				break;
			}
			case 3:
			{
				//TODO: �����(Done)
				if (IsBinaryTreeNotCreateOrEmpty(binaryTree))
				{
					break;
				}

				cout << "������� ���� ��������: ";
				int key = InputInt();
				cout << "\n";

				BinaryTreeNode* node = binaryTree->Find(key);
				//TODO: Formatting(Done)
				cout << (node == nullptr ? "������ �������� ���.\n" : "������� ������.\n");

				break;
			}
			case 4:
			{
				//TODO: �����(Done)
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
				//TODO: �����(Done)
				if (IsBinaryTreeNotCreateOrEmpty(binaryTree))
				{
					break;
				}

				//TODO: RSDN(Done)
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
				//TODO: �����(Done)
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

//��������, ��� ���� �� ������ ��� ����
bool IsBinaryTreeNotCreateOrEmpty(BinaryTree* binaryTree)
{
	if (binaryTree == nullptr || binaryTree->IsEmpty())
	{
		cout << "������ ������.\n";
		return true;
	}

	return false;
}