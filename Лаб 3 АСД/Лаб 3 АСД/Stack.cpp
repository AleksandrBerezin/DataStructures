#include <iostream>
#include "Constant.h"
#include "StackNode.h"
#include "Stack.h"

using namespace std;

// Добавление элемента в стек
void Stack::Push(int element)
{
	StackNode* newNode = new StackNode;
	newNode->Data = element;

	if (TopElement == nullptr)
	{
		TopElement = newNode;
		newNode->Next = nullptr;
	}
	else
	{
		newNode->Next = TopElement;
		TopElement = newNode;
	}

	CurrentLength++;
}

// Извлечение элемента из стека (последнего)
int Stack::Pop()
{
	StackNode* last = TopElement;
	TopElement = TopElement->Next;
	
	int element = last->Data;
	CurrentLength--;
	delete last;

	return element;
}

// Изменение размера стека
void Stack::Resize()
{
	Size = Size * growthFactor;
}

// Проверка: пуст стек(true) или нет(false)
bool Stack::IsEmpty()
{
	return CurrentLength == 0;
}

// Удаление стека (очистка памяти)
void Stack::Delete()
{
	StackNode* current = TopElement;
	while (current != nullptr)
	{
		StackNode* node = current;
		current = current->Next;
		delete node;
	}

	TopElement = nullptr;
	CurrentLength = 0;
	Size = 0;
}