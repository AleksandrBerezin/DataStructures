#include <iostream>
#include "Constant.h"
#include "Stack.h"
#include "TwoStackQueue.h"

using namespace std;

// ���������� �������� � �������
void TwoStackQueue::Enqueue(int element)
{
	if (InputStack->Length == InputStack->Size)
	{
		InputStack->Resize();
	}

	InputStack->Push(element);
}

// ���������� �������� �� �������
int TwoStackQueue::Dequeue()
{
	if (OutputStack->IsEmpty())
	{
		while (InputStack->IsEmpty() == false)
		{
			int element = InputStack->Pop();
			OutputStack->Push(element);
		}
	}

	return OutputStack->Pop();
}

// ��������: ����� �������(true) ��� ���(false)
bool TwoStackQueue::IsEmpty()
{
	return InputStack->IsEmpty() && OutputStack->IsEmpty();
}

// �������� �������
void TwoStackQueue::Delete()
{
	InputStack->Delete();
	OutputStack->Delete();

	delete InputStack;
	delete OutputStack;
}

// ����� �� �����
void Print(TwoStackQueue* stackQueue)
{
	if (stackQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return;
	}

	int length = stackQueue->InputStack->Length + stackQueue->OutputStack->Length;
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