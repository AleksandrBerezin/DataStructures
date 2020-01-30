#include <iostream>
#include <ctime>
#include "Node.h"
#include "List.h"

using namespace std;

int Input();

int main()
{
	setlocale(LC_ALL, "Russian");

	List* list = new List();
	bool exit = false;

	while (!exit)
	{
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента.\n"
			<< "2. Удаление элемента.\n"
			<< "3. Вставка элемента в начало.\n"
			<< "4. Вставка элемента в конец.\n"
			<< "5. Вставка после определенного элемента.\n"
			<< "6. Вставка перед определенным элементом.\n"
			<< "7. Сортировка списка.\n"
			<< "8. Линейный поиск элемента в массиве.\n"
			<< "9. Измерение времени для удаления.\n"
			<< "10. Измерение времени для вставки.\n"
			<< "0. Выход.\n\n";

		int number = Input();
		switch (number)
		{
			case 1:
			{
				if (list == nullptr)
				{
					list = new List();
				}

				cout << "Введите значение элемента:\n";
				int value = Input();
				list->Add(value);
				Print(list);
				break;
			}
			case 2:
			{
				if (list == nullptr || list->Length == 0)
				{
					cout << "Список пуст.\n";
					break;
				}

				cout << "Введите индекс элемента, который нужно удалить:\n";
				int index = Input();

				while (index < 0 || index >= list->Length)
				{
					cout << "Элемента с таким индексом нет, "
						<< "попробуйте еще раз:\n";
					index = Input();
				}

				list->Remove(index);
				Print(list);
				break;
			}
			case 3:
			{
				if (list == nullptr)
				{
					list = new List();
				}

				cout << "Введите значение элемента:\n";
				int value = Input();
				list->InsertBefore(0, value);
				Print(list);
				break;
			}
			case 4:
			{
				if (list == nullptr)
				{
					list = new List();
				}

				cout << "Введите значение элемента:\n";
				int value = Input();

				list->InsertAfter(list->Length - 1, value);
				Print(list);
				break;
			}
			case 5:
			{
				if (list == nullptr || list->Length == 0)
				{
					cout << "Список пуст.\n";
					break;
				}

				cout << "Введите индекс элемента:\n";
				int index = Input();

				while (index < 0 || index >= list->Length)
				{
					cout << "Элемента с таким индексом нет, "
						<< "попробуйте еще раз:\n";
					index = Input();
				}

				cout << "Введите значение элемента:\n";
				int value = Input();

				list->InsertAfter(index, value);
				Print(list);
				break;
			}
			case 6:
			{
				if (list == nullptr || list->Length == 0)
				{
					cout << "Список пуст.\n";
					break;
				}

				cout << "Введите индекс элемента:\n";
				int index = Input();

				while (index < 0 || index >= list->Length)
				{
					cout << "Элемента с таким индексом нет, "
						<< "попробуйте еще раз:\n";
					index = Input();
				}

				cout << "Введите значение элемента:\n";
				int value = Input();

				list->InsertBefore(index, value);
				Print(list);
				break;
			}
			case 7:
				if (list == nullptr || list->Length == 0)
				{
					cout << "Список пуст.\n";
					break;
				}

				list->Sort();
				Print(list);
				break;
			case 8:
			{
				if (list == nullptr || list->Length == 0)
				{
					cout << "Список пуст.\n";
					break;
				}

				cout << "Введите значение элемента:\n";
				int value = Input();

				int index = list->Search(value);
				if (index == -1)
				{
					cout << "Такого элемента нет.\n";
				}
				else
				{
					cout << "Элемент находится под индексом " << index << ".\n";
				}
				break;
			}
			case 9:
			{
				if (list != nullptr)
				{
					list->Delete();
					delete list;
				}

				list = new List();

				cout << "Введите количество элементов списка:\n";
				int n = Input();

				for (int i = 0; i < n; i++)
				{
					list->Add(i);
				}
				int middle = list->Length / 2;

				clock_t begin = clock();

				list->Remove(middle);

				clock_t end = clock();
				double seconds = double(end - begin) / CLOCKS_PER_SEC;
				cout << "The time is " << seconds << " seconds.\n";
				list->Delete();
				break;
			}
			case 10:
			{
				if (list != nullptr)
				{
					list->Delete();
					delete list;
				}

				list = new List();

				cout << "Введите количество элементов списка:\n";
				int n = Input();

				for (int i = 0; i < n; i++)
				{
					list->Add(i);
				}
				int middle = list->Length / 2;

				clock_t begin = clock();

				list->InsertAfter(middle, 1);

				clock_t end = clock();
				double seconds = double(end - begin) / CLOCKS_PER_SEC;
				cout << "The time is " << seconds << " seconds.\n";
				list->Delete();
				break;
			}
			case 0:
				if (list != nullptr)
				{
					list->Delete();
					delete list;
					list = nullptr;
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
int Input()
{
	int input = 0;

	while (true)
	{
		cin >> input;
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

	return input;
}