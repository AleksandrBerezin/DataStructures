#pragma once
#include "Node.h"

struct Stack
{
	//TODO: Naming
	Node* Top; // Верхний элемент стека
	int Size; // Размер стека
	int Length; // Количество элементов

	void Push(int element);
	int Pop();
	void Resize();
	bool IsEmpty();
	void Delete();

	Stack()
	{
		Size = BUFFERSIZE;
		Top = nullptr;
		Length = 0;
	}
};

void Print(Stack* stack);