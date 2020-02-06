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
				if (rbTree == nullptr)
				{
					rbTree = new RBTree();
				}

				cout << "Введите значение элемента: ";
				int value = InputInt();
				cout << "\n";

				RBTreeNode* node;

				do
				{
					node = rbTree->Find(value);

					if (node != nullptr)
					{
						cout << "Элемент с таким ключем присутствует "
							<< "в дереве, введите другой ключ: ";
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

				cout << "Введите значение элемента: ";
				int value = InputInt();
				cout << "\n";

				RBTreeNode* node;

				do
				{
					node = rbTree->Find(value);

					if (node == nullptr)
					{
						cout << "Элемента с таким ключем нет "
							<< "в дереве, введите другой ключ: ";
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

				cout << "Введите ключ элемента: ";
				int key = InputInt();
				cout << "\n";

				RBTreeNode* node =
					rbTree->Find(key);

				cout << (node == rbTree->Nil 
					? "Такого элемента нет.\n"
					: "Элемент найден.\n");

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

				cout << "Введите количество элементов дерева: \n";
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

				cout << "Введите количество элементов дерева: \n";
				int count = InputInt();

				//TODO: дубль(Done)
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
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}

//Проверка, что стек не создан или пуст
bool IsRBTreeNotCreateOrEmpty(RBTree* rbTree)
{
	if (rbTree == nullptr || rbTree->IsEmpty())
	{
		cout << "Дерево пустое.\n";
		return true;
	}

	return false;
}

//Вычисление времени работы функции
void ShowFunctionRunTimeAndCountRotate(RBTree* rbTree, clock_t begin)
{
	clock_t end = clock();

	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Время - " << seconds << " секунд;\n";
	cout << "Количество поворотов - " << rbTree->CountRotate
		<< ".\n";
}

void InsertCountElement(RBTree* rbTree, int count)
{
	for (int i = 0; i < count; i++)
	{
		rbTree->Insert(i);
	}
}