#pragma once

#include <iostream>
#include <ctime>
#include "List.h"
#include "ListNode.h"
#include "CommonLibrary.h"

using namespace std;

/*
	������� ��� ������
*/

//��������, ��� ������ �� ������ ��� ����
bool IsListNotCreateOrEmpty(List* list)
{
	if (list == nullptr || list->IsEmpty())
	{
		cout << "������ ����.\n";
		return true;
	}

	return false;
}

//��������, ���� ������ ��� �� ������, �� ���������
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
		cout << "�������� � ����� �������� ���, "
			<< "���������� ��� ���:\n";
		*index = InputInt();
	}
}

//���������� ������� ������ �������
void ShowFunctionRunTime(clock_t begin)
{
	clock_t end = clock();
	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "The time is " << seconds << " seconds.\n";
}

//���������� count ��������� � ������
void InsertCountElement(List* list, int count)
{
	for (int i = 0; i < count; i++)
	{
		list->Add(i);
	}
}

// ����� ������ �� �����
void Print(List* list)
{
	if (list->IsEmpty())
	{
		cout << "������ ����.\n";
		return;
	}

	ListNode* current = list->Head;
	cout << "���������� ������: ";
	while (current != nullptr)
	{
		cout << current->Data << " ";
		current = current->Next;
	}
	cout << "\n";
}