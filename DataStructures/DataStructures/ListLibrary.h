#pragma once

#include <iostream>
#include <ctime>
#include "List.h"
#include "ListNode.h"
#include "CommonLibrary.h"

using namespace std;

/*
	Функции для списка
*/

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

void FindCorrectIndex(List* list, int* index)
{
	while (*index < 0 || *index >= list->Length)
	{
		cout << "Элемента с таким индексом нет, "
			<< "попробуйте еще раз:\n";
		*index = InputInt();
	}
}

//Вычисление времени работы функции
void ShowFunctionRunTime(clock_t begin)
{
	clock_t end = clock();
	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "The time is " << seconds << " seconds.\n";
}

//Добавление count элементов в список
void InsertCountElement(List* list, int count)
{
	for (int i = 0; i < count; i++)
	{
		list->Add(i);
	}
}

// Вывод списка на экран
void Print(List* list)
{
	if (list->IsEmpty())
	{
		cout << "Список пуст.\n";
		return;
	}

	ListNode* current = list->Head;
	cout << "Полученный список: ";
	while (current != nullptr)
	{
		cout << current->Data << " ";
		current = current->Next;
	}
	cout << "\n";
}