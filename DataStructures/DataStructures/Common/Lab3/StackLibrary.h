#pragma once

#include <iostream>
#include "../../Lab3/Stack.h"

using namespace std;

/*
	Функции для стека
*/

//Проверка, что стек не создан или пуст
bool IsStackNotCreateOrEmpty(Stack* stack)
{
	if (stack == nullptr || stack->IsEmpty())
	{
		cout << "Стек пуст.\n";
		return true;
	}

	return false;
}

//Проверка, что стек не создан
bool IsStackNotCreate(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "Стек пуст.\n";
		return true;
	}

	return false;
}


// Вывод на экран
void Print(Stack* stack)
{
	if (stack->IsEmpty())
	{
		cout << "Стек пуст.\n";
		return;
	}

	int* tempArray = new int[stack->CurrentLength];
	StackNode* current = stack->TopElement;

	int i = 0;
	while (current != nullptr)
	{
		tempArray[i] = current->Data;
		current = current->Next;
		i++;
	}

	cout << "Полученный стек: ";
	for (int j = stack->CurrentLength - 1; j >= 0; j--)
	{
		cout << tempArray[j] << " ";
	}
	cout << "\n";

	delete[] tempArray;
}