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
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента.\n"
			<< "2. Удаление элемента.\n"
			<< "3. Поиск элемента.\n"
			<< "4. Поиск максимума дерева.\n"
			<< "5. Поиск минимума дерева.\n"
			<< "6. Удаление дерева.\n"
			<< "7. Вывод дерева на экран.\n"
			<< "0. Назад.\n\n";

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
						cout << "Элемент с таким ключем присутствует "
							<< "в дереве, введите другой ключ: ";
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
						cout << "Элемента с таким ключем нет "
							<< "в дереве, введите другой ключ: ";
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
					? "Такого элемента нет.\n"
					: "Элемент найден.\n");

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
					cout << "Дерево пустое.\n";
					break;
				}

				cout << "Максимальный элемент дерева равен " << max->Key << ".\n";
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
					cout << "Дерево пустое.\n";
					break;
				}

				cout << "Минимальный элемент дерева равен " << min->Key << ".\n";
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
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}