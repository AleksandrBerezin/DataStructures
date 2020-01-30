#include <iostream>
#include "Constant.h"
#include "Stack.h"
#include "TwoStackQueue.h"

using namespace std;

// Добавление элемента в очередь
void TwoStackQueue::Enqueue(int element)
{
	if (InputStack->Length == InputStack->Size)
	{
		InputStack->Resize();
	}

	InputStack->Push(element);
}

// Извлечение элемента из очереди
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

// Проверка: пуста очередь(true) или нет(false)
bool TwoStackQueue::IsEmpty()
{
	return InputStack->IsEmpty() && OutputStack->IsEmpty();
}

// Удаление очереди
void TwoStackQueue::Delete()
{
	InputStack->Delete();
	OutputStack->Delete();

	delete InputStack;
	delete OutputStack;
}

// Вывод на экран
void Print(TwoStackQueue* stackQueue)
{
	if (stackQueue->IsEmpty())
	{
		cout << "Очередь пустая.\n";
		return;
	}

	int length = stackQueue->InputStack->Length + 
		stackQueue->OutputStack->Length;
	int* tempArray = new int[length];
	Node* current;

	if (stackQueue->InputStack->IsEmpty() == false)
	{
		current = stackQueue->InputStack->Top;
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
		current = stackQueue->OutputStack->Top;
		int i = length - 1;
		while (current != nullptr)
		{
			tempArray[i] = current->Data;
			current = current->Next;
			i--;
		}
	}

	cout << "Текущая очередь: ";
	for (int j = length - 1; j >= 0; j--)
	{
		cout << tempArray[j] << " ";
	}
	cout << "\n";

	delete[] tempArray;
}