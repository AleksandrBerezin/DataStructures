#include <iostream>
#include <cstdlib>
#include "DynamicArray.h"

using namespace std;

const double growthFactor = 1.5;

//Добавление элемента в массив
void DynamicArray::Add(int element)
{
	Length++;

	if (Length >= Capacity)
	{
		Resize();
	}

	Array[Length - 1] = element;
	IsSorted = false;
}

//Изменение размера памяти для массива
void DynamicArray::Resize()
{
	//TODO: Числовые константы лучше поименовать(Done)
	if (Length >= Capacity)
	{
		Capacity = Length * growthFactor;
	}
	else if (Length > 4)
	{
		Capacity = Length;
	}
	else
	{
		return;
	}

	int* newArray = new int[Capacity];
	for (int i = 0; i < Length; i++)
	{
		newArray[i] = Array[i];
	}

	delete[] Array;
	Array = newArray;
}

//Сортировка методом вставок
void DynamicArray::InsertionSort()
{
	for (int i = 0; i < Length; i++)
	{
		for (int j = i + 1; j < Length; j++)
		{
			if (Array[j] < Array[i])
			{
				int temp = Array[j];
				Array[j] = Array[i];
				Array[i] = temp;
			}
		}
	}

	IsSorted = true;
}

//Вставка элемента в массив по индексу
void DynamicArray::Insert(int element, int index)
{
	Length++;

	if (Length >= Capacity)
	{
		Resize();
	}

	for (int i = Length - 1; i > index; i--)
	{
		Array[i] = Array[i - 1];
	}

	Array[index] = element;
}

//Удаление элемента из массива по индексу
void DynamicArray::Delete(int index)
{
	for (int i = index; i < Length - 1; i++)
	{
		Array[i] = Array[i + 1];
	}

	Length--;
	Resize();
}

//Линейный поиск элемента в массиве
int DynamicArray::LineSearch(int element)
{
	for (int i = 0; i < Length; i++)
	{
		if (Array[i] == element)
		{
			return i;
		}
	}

	return -1;
}

//Бинарный поиск элемента в массиве
int DynamicArray::BinarySearch(int element)
{
	int first = 0;
	int last = Length;
	//TODO: Почему здесь?(Done)

	while (first < last)
	{
		int middle = (first + last) / 2;
		if (element <= Array[middle])
		{
			last = middle;
		}
		else
		{
			first = middle + 1;
		}
	}

	if (first == Length || Array[first] != element)
	{
		return -1;
	}
	else
	{
		return first;
	}
}

// Проверка: пустой массив(true) или нет(false)
bool DynamicArray::IsEmpty()
{
	return Length == 0;
}

//Вывод массива на экран
//TODO: RSDN(Done)
void Print(DynamicArray* array) 
{
	cout << "\nПолученный массив: ";
	for (int i = 0; i < array->Length; i++)
	{
		cout << array->Array[i] << " ";
	}
	cout << "\n";
}