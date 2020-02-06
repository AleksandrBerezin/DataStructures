#include <iostream>
#include <ctime>
#include "Node.h"
#include "List.h"

//TODO: Не называйте решения по-русски
using namespace std;

int Input();
bool IsListNotCreateOrEmpty(List* list);
void CheckListOnCreate(List* list);
int InputIndex();
int InputValue();
void FindCorrectIndex(List* list, int* index);
void ShowFunctionRunTime(clock_t begin);

int main()
{
	setlocale(LC_ALL, "Russian");

	List* list = new List();
	bool isExit = false;

	while (!isExit)
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

		switch (Input())
		{
			case 1:
			{
				CheckListOnCreate(list);

				cout << "Введите значение элемента:\n";
				list->Add(Input());
				Print(list);
				break;
			}
			case 2:
			{
				if (IsListNotCreateOrEmpty(list))
				{
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
				CheckListOnCreate(list);

				cout << "Введите значение элемента:\n";
				list->InsertBefore(0, Input());
				Print(list);
				break;
			}
			case 4:
			{
				CheckListOnCreate(list);

				cout << "Введите значение элемента:\n";
				list->InsertAfter(list->Length - 1, Input());
				Print(list);
				break;
			}
			case 5:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				int index = InputIndex();

				FindCorrectIndex(list, &index);

				int value = InputValue();

				list->InsertAfter(index, value);
				Print(list);
				break;
			}
			case 6:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				int index = InputIndex();

				FindCorrectIndex(list, &index);
				int value = InputValue();

				list->InsertBefore(index, value);
				Print(list);
				break;
			}
			case 7:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				list->InsertionSort();
				Print(list);
				break;
			}
			case 8:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				cout << "Введите значение элемента:\n";
				int index = list->Search(Input());

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

				int count = Input();

				for (int i = 0; i < count; i++)
				{
					list->Add(i);
				}
				int middle = list->Length / 2;

				clock_t begin = clock();

				list->Remove(middle);

				ShowFunctionRunTime(begin);
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

				int count = Input();

				for (int i = 0; i < count; i++)
				{
					list->Add(i);
				}
				int middle = list->Length / 2;
				clock_t begin = clock();

				list->InsertAfter(middle, 1);

				ShowFunctionRunTime(begin);
				list->Delete();
				break;
			}
			case 0:
			{
				if (list != nullptr)
				{
					list->Delete();
					delete list;
					list = nullptr;
				}

				isExit = true;
				break;
			}
			default:
			{
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
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

//Проверка, что список не создан или пуст
bool IsListNotCreateOrEmpty(List* list)
{
	if (list == nullptr || list->IsEmpty())
	{
		cout << "Список пуст.\n";
		return true;
	}

	return false;
}

//Проверка, если список ещё не создан, то создается
void CheckListOnCreate(List* list)
{
	if (list == nullptr)
	{
		list = new List();
	}
}

int InputIndex()
{
	cout << "Введите индекс элемента:\n";
	return Input();
}

int InputValue()
{
	cout << "Введите значение элемента:\n";
	return Input();
}

void FindCorrectIndex(List* list, int* index)
{
	while (*index < 0 || *index >= list->Length)
	{
		cout << "Элемента с таким индексом нет, "
			<< "попробуйте еще раз:\n";
		*index = Input();
	}
}

//Вычисление времени работы функции
void ShowFunctionRunTime(clock_t begin)
{
	clock_t end = clock();
	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "The time is " << seconds << " seconds.\n";
}