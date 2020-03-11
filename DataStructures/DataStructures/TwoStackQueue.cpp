#include <iostream>
#include "ConstantLab3.h"
#include "Stack.h"
#include "TwoStackQueue.h"

using namespace std;

// Добавление элемента в очередь
void TwoStackQueue::Enqueue(int element)
{
	if (InputStack->CurrentLength == InputStack->Size)
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