#pragma once

#include <iostream>
#include "DynamicArray.h"

using namespace std;

/*
	Функции для динамического массива
*/

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

//Вывод массива на экран
void Print(DynamicArray* array)
{
	cout << "\nПолученный массив: ";
	for (int i = 0; i < array->Length; i++)
	{
		cout << array->Array[i] << " ";
	}
	cout << "\n";
}