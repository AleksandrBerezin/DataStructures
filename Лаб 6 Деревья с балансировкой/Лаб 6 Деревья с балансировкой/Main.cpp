#include <iostream>
#include <ctime>
#include "AVLTreeNode.h"
#include "AVLTree.h"
#include "RBTreeNode.h"
#include "RBTree.h"

using namespace std;

int InputInt();

int main()
{
	setlocale(LC_ALL, "Russian");
	//TODO: Ответственность. Лучше разделить меню по файлам.
	AVLTree* avlTree = new AVLTree;
	RBTree* rbTree = new RBTree;

	bool exit = false;

	while (!exit)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. АВЛ-Дерево.\n"
			<< "2. Красно-черное дерево.\n"
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
						<< "4. Удаление дерева.\n"
						<< "5. Вывод дерева на экран.\n"
						<< "6. Измерение времени для вставки.\n"
						<< "7. Измерение времени для удаления.\n"
						<< "0. Назад.\n\n";

					int variant = InputInt();
					switch (variant)
					{
						case 1:
						{
							if (avlTree == nullptr)
							{
								avlTree = new AVLTree();
							}

							cout << "Введите значение элемента: ";
							int value = InputInt();
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
							if (avlTree == nullptr || avlTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "Введите значение элемента: ";
							int value = InputInt();
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
							if (avlTree == nullptr || avlTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "Введите ключ элемента: ";
							int key = InputInt();
							cout << "\n";

							AVLTreeNode* node =
								avlTree->Find(key);
							//TODO: Formatting
							cout << (node == nullptr ? "Такого элемента нет.\n"
								: "Элемент найден.\n");

							break;
						}
						case 4:
							if (avlTree == nullptr)
							{
								break;
							}

							avlTree->Clear(avlTree->Root);
							delete avlTree;
							avlTree = nullptr;
							break;
						case 5:
							if (avlTree == nullptr || avlTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "\n";
							Print(avlTree->Root, 0);
							break;
						case 6:
						{
							if (avlTree != nullptr)
							{
								avlTree->Clear(avlTree->Root);
								delete avlTree;
							}

							avlTree = new AVLTree();

							cout << "Введите количество элементов дерева: \n";
								//TODO: Naming
							int n = InputInt();
							//TODO: Дубль
							clock_t begin = clock();
							for (int i = 0; i < n; i++)
							{
								avlTree->Root = avlTree->Insert(avlTree->Root, i);
							}
							clock_t end = clock();

							double seconds = double(end - begin) / CLOCKS_PER_SEC;
							cout << "Время - " << seconds << " секунд;\n";
							cout << "Количество поворотов - " << avlTree->CountRotate
								<< ".\n";

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
								//TODO: Naming
							int n = InputInt();

							for (int i = 0; i < n; i++)
							{
								avlTree->Root = avlTree->Insert(avlTree->Root, i);
							}
							avlTree->CountRotate = 0;
							//TODO: Дубль
							clock_t begin = clock();
							for (int i = 0; i < n; i++)
							{
								avlTree->Root = avlTree->Remove(avlTree->Root, i);
							}
							clock_t end = clock();

							double seconds = double(end - begin) / CLOCKS_PER_SEC;
							cout << "Время - " << seconds << " секунд;\n";
							cout << "Количество поворотов - " << avlTree->CountRotate
								<< ".\n";

							avlTree->Clear(avlTree->Root);
							delete avlTree;
							avlTree = nullptr;
							break;
						}
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
					cout << "1. Добавление элемента.\n"
						<< "2. Удаление элемента.\n"
						<< "3. Поиск элемента.\n"
						<< "4. Удаление дерева.\n"
						<< "5. Вывод дерева на экран.\n"
						<< "6. Измерение времени для вставки.\n"
						<< "7. Измерение времени для удаления.\n"
						<< "0. Назад.\n\n";

					int variant = InputInt();
					switch (variant)
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
								//TODO: Дубль
							if (rbTree == nullptr || rbTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "Введите значение элемента: ";
							int value = InputInt();
							cout << "\n";

								//TODO: Почему здесь?
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
								//TODO: Дубль
							if (rbTree == nullptr || rbTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "Введите ключ элемента: ";
							int key = InputInt();
							cout << "\n";

							RBTreeNode* node =
								rbTree->Find(key);

								//TODO: Formatting
							cout << (node == rbTree->Nil ? "Такого элемента нет.\n"
								: "Элемент найден.\n");

							break;
						}
						case 4:
							if (rbTree == nullptr)
							{
								break;
							}

							rbTree->Clear(rbTree->Root);
							delete rbTree;
							rbTree = nullptr;
							break;
						case 5:
						//TODO: Дубль
							if (rbTree ==  nullptr || rbTree->IsEmpty())
							{
								cout << "Дерево пустое.\n";
								break;
							}

							cout << "\n";
							Print(rbTree, rbTree->Root, 0);
							break;
						case 6:
						{
							if (rbTree != nullptr)
							{
								rbTree->Clear(rbTree->Root);
								delete rbTree;
							}

							rbTree = new RBTree();

							cout << "Введите количество элементов дерева: \n";
								//TODO: Naming
							int n = InputInt();
							//TODO: Дубль
							clock_t begin = clock();
							for (int i = 0; i < n; i++)
							{
								rbTree->Insert(i);
							}
							clock_t end = clock();

							double seconds = double(end - begin) / CLOCKS_PER_SEC;
							cout << "Время - " << seconds << " секунд;\n";
							cout << "Количество поворотов - " << rbTree->CountRotate 
								<< ".\n";

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
								//TODO: Naming
							int n = InputInt();

							for (int i = 0; i < n; i++)
							{
								rbTree->Insert(i);
							}
							rbTree->CountRotate = 0;

							clock_t begin = clock();
							for (int i = 0; i < n; i++)
							{
								rbTree->Remove(i);
							}
							clock_t end = clock();

							double seconds = double(end - begin) / CLOCKS_PER_SEC;
							cout << "Время - " << seconds << " секунд;\n";
							cout << "Количество поворотов - " << rbTree->CountRotate
								<< ".\n";

							rbTree->Clear(rbTree->Root);
							delete rbTree;
							rbTree = nullptr;
							break;
						}
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
				if (avlTree != nullptr)
				{
					avlTree->Clear(avlTree->Root);
					delete avlTree;
					avlTree = nullptr;
				}
				if (rbTree != nullptr)
				{
					rbTree->Clear(rbTree->Root);
					delete rbTree;
					rbTree = nullptr;
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