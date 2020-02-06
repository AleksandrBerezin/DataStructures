#include <iostream>
#include <ctime>
#include "RBTree.h"
#include "RBTreeNode.h"
#include "MenuRBTree.h"
#include "Functions.h"

using namespace std;

bool IsRBTreeNotCreateOrEmpty(RBTree* rbTree);
void ShowFunctionRunTimeAndCountRotate(RBTree* rbTree, clock_t begin);
void InsertCountElement(RBTree* rbTree, int count);

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

				cout << "������� �������� ��������: ";
				int value = InputInt();
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

				cout << "������� �������� ��������: ";
				int value = InputInt();
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

				cout << "������� ���� ��������: ";
				int key = InputInt();
				cout << "\n";

				RBTreeNode* node =
					rbTree->Find(key);

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

				//TODO: �����(Done)
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

//��������, ��� ���� �� ������ ��� ����
bool IsRBTreeNotCreateOrEmpty(RBTree* rbTree)
{
	if (rbTree == nullptr || rbTree->IsEmpty())
	{
		cout << "������ ������.\n";
		return true;
	}

	return false;
}

//���������� ������� ������ �������
void ShowFunctionRunTimeAndCountRotate(RBTree* rbTree, clock_t begin)
{
	clock_t end = clock();

	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "����� - " << seconds << " ������;\n";
	cout << "���������� ��������� - " << rbTree->CountRotate
		<< ".\n";
}

void InsertCountElement(RBTree* rbTree, int count)
{
	for (int i = 0; i < count; i++)
	{
		rbTree->Insert(i);
	}
}