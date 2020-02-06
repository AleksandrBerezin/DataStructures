#include <iostream>
#include "Treap.h"
#include "TreapNode.h"
#include "MenuTreap.h"
#include "Functions.h"

using namespace std;

bool IsTreapNotCreateOrEmpty(Treap* treap);

void Menu(Treap*& treap)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента с использованием " <<
			"неоптимизированного алгоритма.\n"
			<< "2. Добавление элемента с использованием " <<
			"оптимизированного алгоритма.\n"
			<< "3. Удаление элемента с использованием " <<
			"неоптимизированного алгоритма.\n"
			<< "4. Удаление элемента с использованием " <<
			"оптимизированного алгоритма.\n"
			<< "5. Поиск элемента.\n"
			<< "6. Удаление дерева.\n"
			<< "7. Вывод дерева на экран.\n"
			<< "0. Назад.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (treap == nullptr)
				{
					treap = new Treap();
				}

				cout << "Введите ключ элемента: ";
				int key = InputInt();
				cout << "\n";

				TreapNode* node;

				do
				{
					node = treap->Find(key);

					if (node != nullptr)
					{
						cout << "Элемент с таким ключем присутствует "
							<< "в дереве, введите другой ключ: ";
						key = InputInt();
						cout << "\n";
					}
				} while (node != nullptr);

				treap->SlowInsert(key);
				Print(treap->Root, 0);
				break;
			}
			case 2:
			{
				if (treap == nullptr)
				{
					treap = new Treap();
				}

				cout << "Введите ключ элемента: ";
				int key = InputInt();
				cout << "\n";

				TreapNode* node;

				do
				{
					node = treap->Find(key);

					if (node != nullptr)
					{
						cout << "Элемент с таким ключем присутствует "
							<< "в дереве, введите другой ключ: ";
						key = InputInt();
						cout << "\n";
					}
				} while (node != nullptr);
				srand(time(nullptr));
				int priority = rand() % 100;

				treap->FastInsert(treap->Root, nullptr, key, priority);
				Print(treap->Root, 0);
				break;
			}
			case 3:
			{
				if (IsTreapNotCreateOrEmpty(treap))
				{
					break;
				}

				cout << "Введите ключ элемента: ";
				int key = InputInt();
				cout << "\n";

				treap->SlowRemove(key);
				Print(treap->Root, 0);
				break;
			}
			case 4:
			{
				if (IsTreapNotCreateOrEmpty(treap))
				{
					break;
				}

				cout << "Введите ключ элемента: ";
				int key = InputInt();
				cout << "\n";

				treap->FastRemove(treap->Root, nullptr, key);
				Print(treap->Root, 0);
				break;
			}
			case 5:
			{
				if (IsTreapNotCreateOrEmpty(treap))
				{
					break;
				}

				cout << "Введите ключ элемента: ";
				int key = InputInt();

				TreapNode* node = treap->Find(key);

				if (node == nullptr)
				{
					cout << "Такого элемента нет.\n";
				}
				else
				{
					cout << "Элемент найден, ключ = " << node->Key
						<< ", приоритет = " << node->Priority << ".\n";
				}

				break;
			}
			case 6:
			{
				if (treap == nullptr)
				{
					break;
				}

				treap->Clear(treap->Root);
				delete treap;
				treap = nullptr;
				break;
			}
			case 7:
			{
				if (IsTreapNotCreateOrEmpty(treap))
				{
					break;
				}

				cout << "\n";
				Print(treap->Root, 0);
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
bool IsTreapNotCreateOrEmpty(Treap* treap)
{
	if (treap == nullptr || treap->IsEmpty())
	{
		cout << "Дерево пустое.\n";
		return true;
	}

	return false;
}