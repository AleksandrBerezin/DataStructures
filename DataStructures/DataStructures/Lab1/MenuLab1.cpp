#include "DynamicArray.h"
#include <iostream>
#include "../Common/CommonLibrary.h"
#include "../Common/Lab1/DynamicArrayLibrary.h"

using namespace std;

void MenuLab1()
{
	DynamicArray* array = new DynamicArray();
	bool isBack = false;

	while (!isBack)
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
			<< "0. Назад.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				CheckArrayOnCreate(array);

				int value = InputIntValue();
				array->Add(value);
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

				int index = InputIndex();

				while (index < 0 || index >= array->Length)
				{
					cout << "Вы ввели неверный индекс, "
						<< "попробуйте еще раз:\n";
					index = InputInt();
				}

				array->Delete(index);
				Print(array);
				break;
			}
			case 3:
			{
				CheckArrayOnCreate(array);

				int value = InputIntValue();
				array->Insert(value, 0);
				Print(array);
				break;
			}
			case 4:
			{
				CheckArrayOnCreate(array);

				int value = InputIntValue();
				array->Insert(value, array->Length);
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

				int value = InputIntValue();
				int index = InputIndex();

				array->Insert(value, index + 1);
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

				int value = InputIntValue();
				int index = array->LineSearch(value);

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

				int value = InputIntValue();
				int index = array->BinarySearch(value);

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