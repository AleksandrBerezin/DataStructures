#pragma once

#include <iostream>
#include "../../Lab3/TwoStackQueue.h"

using namespace std;

/*
	������� ��� ������� �� ������ ���� ������
*/

//��������, ��� ������� �� ������� ��� ����
bool IsStackQueueNotCreateOrEmpty(TwoStackQueue* stackQueue)
{
	if (stackQueue == nullptr || stackQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return true;
	}

	return false;
}

//��������, ��� ������� �� �������
bool IsStackQueueNotCreate(TwoStackQueue* stackQueue)
{
	if (stackQueue == nullptr)
	{
		cout << "������� ������.\n";
		return true;
	}

	return false;
}

// ����� �� �����
void Print(TwoStackQueue* stackQueue)
{
	if (stackQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return;
	}

	int length = stackQueue->InputStack->CurrentLength + stackQueue->OutputStack->CurrentLength;
	int* tempArray = new int[length];

	if (stackQueue->InputStack->IsEmpty() == false)
	{
		StackNode* current = stackQueue->InputStack->TopElement;
		int i = 0;
		while (current != nullptr)
		{
			tempArray[i] = current->Data;
			current = current->Next;
			i++;
		}
	}

	if (stackQueue->OutputStack->IsEmpty() == false)
	{
		StackNode* current = stackQueue->OutputStack->TopElement;
		int i = length - 1;
		while (current != nullptr)
		{
			tempArray[i] = current->Data;
			current = current->Next;
			i--;
		}
	}

	cout << "������� �������: ";
	for (int j = length - 1; j >= 0; j--)
	{
		cout << tempArray[j] << " ";
	}
	cout << "\n";

	delete[] tempArray;
}