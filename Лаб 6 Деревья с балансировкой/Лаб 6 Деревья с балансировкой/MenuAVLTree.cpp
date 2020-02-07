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
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента.\n"
			<< "2. Удаление элемента.\n"
			<< "3. Поиск элемента.\n"
			<< "4. Удаление дерева.\n"
			<< "5. Вывод дерева на экран.\n"
			<< "6. Измерение времени для вставки.\n"
			<< "7. Измерение времени для удаления.\n"
			<< "0. Назад.\n\n";

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
						cout << "Элемент с таким ключем присутствует "
							<< "в дереве, введите другой ключ: ";
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
						cout << "Элемента с таким ключем нет "
							<< "в дереве, введите другой ключ: ";
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
					? "Такого элемента нет.\n"
					: "Элемент найден.\n");

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

				cout << "Введите количество элементов дерева: \n";
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

				cout << "Введите количество элементов дерева: \n";
				int count = InputInt();
				//TODO: дубль(Done)
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
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}