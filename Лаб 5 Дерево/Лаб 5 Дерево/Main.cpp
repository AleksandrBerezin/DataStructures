#include <iostream>
#include <ctime>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include "TreapNode.h"
#include "Treap.h"

using namespace std;

int InputInt();

int main()
{
	setlocale(LC_ALL, "Russian");
	BinaryTree* binaryTree = new BinaryTree();
	Treap* treap = new Treap();

	bool exit = false;

	while (!exit)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. Бинарное дерево поиска.\n"
			<< "2. Декартово дерево.\n"
			<< "0. Выход.\n\n";

		int number = InputInt();
		bool back = false;
		switch (number)
		{
			case 1:
			{
				while (!back)
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

					int variant = InputInt();
					switch (variant)
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
							if (binaryTree == nullptr || binaryTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
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
							if (binaryTree == nullptr || binaryTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "Введите ключ элемента: ";
							int key = InputInt();
							cout << "\n";

							BinaryTreeNode* node = binaryTree->Find(key);

							cout << (node == nullptr ?  "Такого элемента нет.\n"
								: "Элемент найден.\n");

							break;
						}
						case 4:
						{
							if (binaryTree == nullptr || binaryTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							BinaryTreeNode* max = binaryTree->FindMax();

							if (max == nullptr)
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "Максимальный элемент дерева равен "
								<< max->Key << ".\n";
							break;
						}
						case 5:
						{
							if (binaryTree == nullptr || binaryTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							BinaryTreeNode* min;
							min = binaryTree->FindMin();

							if (min == nullptr)
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "Минимальный элемент дерева равен "
								<< min->Key << ".\n";
							break;
						}
						case 6:
							if (binaryTree == nullptr)
							{
								break;
							}

							binaryTree->Clear(binaryTree->Root);
							delete binaryTree;
							binaryTree = nullptr;
							break;
						case 7:
							if (binaryTree == nullptr || binaryTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "\n";
							Print(binaryTree->Root, 0);
							break;
						case 0:
							back = true;
							break;
						default:
							cout << "Выбран неверный вариант, попробуйте еще раз.\n";
							break;
					}
				}
				break;
			}
		    case 2:
			{
				while (!back)
				{
					cout << "\nВыберите вариант:\n";
					cout << "1. Добавление элемента с использованием "<<
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

					int variant = InputInt();
					switch (variant)
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
							} 
							while (node != nullptr);

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
							} 
							while (node != nullptr);

							srand(time(0));
							int priority = rand() % 100;

							treap->FastInsert(treap->Root, nullptr, key, priority);
							Print(treap->Root, 0);
							break;
						}
						case 3:
						{
							if (treap == nullptr || treap->IsEmpty())
							{
								cout << "Дерево пустое.\n";
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
							if (treap == nullptr || treap->IsEmpty())
							{
								cout << "Дерево пустое.\n";
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
							if (treap == nullptr || treap->IsEmpty())
							{
								cout << "Дерево пустое.\n";
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
							if (treap == nullptr)
							{
								break;
							}

							treap->Clear(treap->Root);
							delete treap;
							treap = nullptr;
							break;
						case 7:
							if (treap == nullptr || treap->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "\n";
							Print(treap->Root, 0);
							break;
						case 0:
							back = true;
							break;
						default:
							cout << "Выбран неверный вариант, попробуйте еще раз.\n";
							break;
					}
				}
				break;
			}
		    case 0:
				if (binaryTree != nullptr)
				{
					binaryTree->Clear(binaryTree->Root);
					delete binaryTree;
					binaryTree = nullptr;
				}
				if (treap != nullptr)
				{
					treap->Clear(treap->Root);
					delete treap;
					treap = nullptr;
				}

			exit = true;
			break;
		default:
			cout << "Выбран неверный вариант, попробуйте еще раз.\n";
			break;
		}
	}

}

//Проверка, что вводимое число int
int InputInt()
{
	int number = 0;

	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR\n";
		}
		else
		{
			break;
		}
	}

	return number;
}