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

				cout << "Введите ключ элемента: ";
				int key = InputInt();
				cout << "\n";

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

				cout << "Введите ключ элемента: ";
				int key = InputInt();
				cout << "\n";

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

				cout << "Введите ключ элемента: ";
				int key = InputInt();
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

//Проверка, что стек не создан или пуст
bool IsBinaryTreeNotCreateOrEmpty(BinaryTree* binaryTree)
{
	if (binaryTree == nullptr || binaryTree->IsEmpty())
	{
		cout << "Дерево пустое.\n";
		return true;
	}

	return false;
}