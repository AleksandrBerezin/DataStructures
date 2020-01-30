#include "DynamicArray.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int Input();

int main()
{
	setlocale(LC_ALL, "Russian");
	
	DynamicArray* array = new DynamicArray();

	bool exit = false;

	while (!exit)
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
		
		int number = Input();
		switch (number)
		{
			case 1:
			{
				if (array == nullptr)
				{
					array = new DynamicArray();
				}

				cout << "Введите значение элемента:\n";
				int element = Input();
				array->Add(element);
				Print(array);
				break;
			}
			case 2:
			{
				if (array == nullptr || array->Length == 0)
				{
					cout << "Массив слишком маленький.\n";
					break;
				}

				if (array->Length == 0)
				{
					cout << "Массив слишком маленький.\n";
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
				if (array == nullptr)
				{
					array = new DynamicArray();
				}

				cout << "Введите значение элемента:\n";
				int element = Input();
				array->Insert(element, 0);
				Print(array);
				break;
			}
			case 4:
			{
				if (array == nullptr)
				{
					array = new DynamicArray();
				}

				cout << "Введите значение элемента:\n";
				int element = Input();
				array->Insert(element, array->Length);
				Print(array);
				break;
			}
			case 5:
			{
				if (array == nullptr)
				{
					array = new DynamicArray();
				}
				if (array->Length == 0)
				{
					cout << "Массив слишком маленький\n";
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
				if (array == nullptr || array->Length == 0)
				{
					cout << "Массив слишком маленький.\n";
					break;
				}
				
				array->Sort();
				Print(array);
				break;
			case 7:
			{
				if (array == nullptr || array->Length == 0)
				{
					cout << "Массив слишком маленький.\n";
					break;
				}

				cout << "Введите элемент, который нужно найти:\n";
				int element = Input();
				int index = array->LineSearch(element);
				
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
				if (array == nullptr || array->Length == 0)
				{
					cout << "Массив слишком маленький.\n";
					break;
				}
				if (!array->IsSorted)
				{
					cout << "Отсортируйте массив.\n";
					break;
				}

				cout << "Введите элемент, который нужно найти:\n";
				int element = Input();

				int index = array->BinarySearch(element);
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
				if (array == nullptr)
				{
					delete[] array->Array;
					delete array;
					array = nullptr;
				}
				exit = true;
				break;
			default:
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
		}
	}

	return 0;
}

//Проверка, что вводимое число int
int Input()
{
	int a = 0;

	while (true)
	{
		cin >> a;
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

	return a;
}