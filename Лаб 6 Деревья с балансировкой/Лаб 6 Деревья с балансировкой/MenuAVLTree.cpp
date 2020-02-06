#include <iostream>
#include <ctime>
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include "MenuAVLTree.h"
#include "Functions.h"

using namespace std;

bool IsAVLTreeNotCreateOrEmpty(AVLTree* avlTree);
void ShowFunctionRunTimeAndCountRotate(AVLTree* avlTree, clock_t begin);
void InsertCountElement(AVLTree* avlTree, int count);

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

				cout << "������� �������� ��������: ";
				int value = InputInt();
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

				cout << "������� �������� ��������: ";
				int value = InputInt();
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

				cout << "������� ���� ��������: ";
				int key = InputInt();
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

//��������, ��� ���� �� ������ ��� ����
bool IsAVLTreeNotCreateOrEmpty(AVLTree* avlTree)
{
	if (avlTree == nullptr || avlTree->IsEmpty())
	{
		cout << "������ ������.\n";
		return true;
	}

	return false;
}

//���������� ������� ������ �������
void ShowFunctionRunTimeAndCountRotate(AVLTree* avlTree, clock_t begin)
{
	clock_t end = clock();

	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "����� - " << seconds << " ������;\n";
	cout << "���������� ��������� - " << avlTree->CountRotate
		<< ".\n";
}

void InsertCountElement(AVLTree* avlTree, int count)
{
	for (int i = 0; i < count; i++)
	{
		avlTree->Root = avlTree->Insert(avlTree->Root, i);
	}
}