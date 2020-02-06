#include "DynamicArray.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int Input();
bool IsArrayNotCreateOrEmpty(DynamicArray* array);
bool IsArrayEmpty(DynamicArray* array);
void CheckArrayOnCreate(DynamicArray* array);

int main()
{
	setlocale(LC_ALL, "Russian");
	
	DynamicArray* array = new DynamicArray();
	bool isExit = false;

	while (!isExit)
	{
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента в массив.\n"
			<< "2. Удаление элемента из массива.\n"
			<< "3. Вставка элемента в начало.\n"
			<< "4. Вставка элемента в конец.\n"
			<< "5. Вставка после определенного элемента.\n"
			<< "6. Сортировка массива.\n"
			<< "7. Линейный поиск элемента в массиве.\n"
			<< "8. Бинарный поиск элемента в массиве.\n"
			<< "0. Выход.\n\n";
		
		switch (Input())
		{
			case 1:
			{
				CheckArrayOnCreate(array);

				cout << "Введите значение элемента:\n";
				array->Add(Input());
				Print(array);
				break;
			}
			case 2:
			{
				if (IsArrayNotCreateOrEmpty(array))
				{
					break;
				}

				if (IsArrayEmpty(array))
				{
					break;
				}

				cout << "Введите индекс элемента, который нужно удалить:\n";
				int index = Input();

				while (index < 0 || index >= array->Length)
				{
					cout << "Вы ввели неверный индекс, "
						<< "попробуйте еще раз:\n";
					index = Input();
				}

				array->Delete(index);
				Print(array);
				break;
			}
			case 3:
			{
				CheckArrayOnCreate(array);

				cout << "Введите значение элемента:\n";
				array->Insert(Input(), 0);
				Print(array);
				break;
			}
			case 4:
			{
				CheckArrayOnCreate(array);

				cout << "Введите значение элемента:\n";
				array->Insert(Input(), array->Length);
				Print(array);
				break;
			}
			case 5:
			{
				CheckArrayOnCreate(array);

				if (IsArrayEmpty(array))
				{
					break;
				}

				cout << "Введите значение элемента:\n";
				int element = Input();
				cout << "Введите индекс элемента:\n";
				int index = Input();

				array->Insert(element, index + 1);
				Print(array);
				break;
			}
			case 6:
			{
				if (IsArrayNotCreateOrEmpty(array))
				{
					break;
				}

				array->InsertionSort();
				Print(array);
				break;
			}
			case 7:
			{
				if (IsArrayNotCreateOrEmpty(array))
				{
					break;
				}

				cout << "Введите элемент, который нужно найти:\n";
				int index = array->LineSearch(Input());
				
				if (index != -1)
				{
					cout << "Элемент находится под индексом " 
						<< index << ".\n";
				}
				else
				{
					cout << "Такого элемента нет.\n";
				}
				
				break;
			}
			case 8:
			{
				if (IsArrayNotCreateOrEmpty(array))
				{
					break;
				}
				if (!array->IsSorted)
				{
					cout << "Отсортируйте массив.\n";
					break;
				}

				cout << "Введите элемент, который нужно найти:\n";
				int index = array->BinarySearch(Input());

				if (index != -1)
				{
					cout << "Элемент находится под индексом "
						<< index << ".\n";
				}
				else
				{
					cout << "Такого элемента нет.\n";
				}
				
				break;
			}
			case 0:
			{
				if (array == nullptr)
				{
					delete[] array->Array;
					delete array;
					array = nullptr;
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

	return 0;
}

//Проверка, что вводимое число int
int Input()
{
	//TODO: Naming()
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

//Проверка, что массив не создан или пуст
bool IsArrayNotCreateOrEmpty(DynamicArray* array)
{
	if (array == nullptr || array->IsEmpty())
	{
		cout << "Массив слишком маленький.\n";
		return true;
	}

	return false;
}

//Проверка, что массив пуст
bool IsArrayEmpty(DynamicArray* array)
{
	if (array->IsEmpty())
	{
		cout << "Массив слишком маленький.\n";
		return true;
	}

	return false;
}

//Проверка, если массив ещё не создан, то создается
void CheckArrayOnCreate(DynamicArray* array)
{
	if (array == nullptr)
	{
		array = new DynamicArray();
	}
}