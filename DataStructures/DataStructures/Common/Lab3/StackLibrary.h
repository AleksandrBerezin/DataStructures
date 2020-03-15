#pragma once

#include <iostream>
#include "../../Lab3/Stack.h"

using namespace std;

/*
	������� ��� �����
*/

//��������, ��� ���� �� ������ ��� ����
bool IsStackNotCreateOrEmpty(Stack* stack)
{
	if (stack == nullptr || stack->IsEmpty())
	{
		cout << "���� ����.\n";
		return true;
	}

	return false;
}

//��������, ��� ���� �� ������
bool IsStackNotCreate(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "���� ����.\n";
		return true;
	}

	return false;
}


// ����� �� �����
void Print(Stack* stack)
{
	if (stack->IsEmpty())
	{
		cout << "���� ����.\n";
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

	cout << "���������� ����: ";
	for (int j = stack->CurrentLength - 1; j >= 0; j--)
	{
		cout << tempArray[j] << " ";
	}
	cout << "\n";

	delete[] tempArray;
}