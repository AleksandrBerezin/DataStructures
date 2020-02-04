#include <iostream>
#include "Constant.h"
#include "Node.h"
#include "Stack.h"

using namespace std;

// Добавление элемента в стек
void Stack::Push(int element)
{
	Node* newNode = new Node;
	newNode->Data = element;

	if (Top == nullptr)
	{
		Top = newNode;
		newNode->Next = nullptr;
	}
	else
	{
		newNode->Next = Top;
		Top = newNode;
	}

	Length++;
}

// Извлечение элемента из стека (последнего)
int Stack::Pop()
{
	Node* last = Top;
	Top = Top->Next;
	
	int element = last->Data;
	Length--;
	delete last;

	return element;
}

// Изменение размера стека
void Stack::Resize()
{
	//TODO: Вынести в именованную константу
	Size = Size * 1.5;
}

// Проверка: пуст стек(true) или нет(false)
bool Stack::IsEmpty()
{
	return Length == 0;
}

// Удаление стека (очистка памяти)
void Stack::Delete()
{
	Node* current = Top;
	//TODO: Почему здесь?
	Node* node;
	while (current != nullptr)
	{
		node = current;
		current = current->Next;
		delete node;
	}

	Top = nullptr;
	Length = 0;
	Size = 0;
}

// Вывод на экран
void Print(Stack* stack)
{
	if (stack->IsEmpty())
	{
		cout << "Стек пуст.\n";
		return;
	}

	int* tempArray = new int[stack->Length];
	Node* current = stack->Top;

	int i = 0;
	while (current != nullptr)
	{
		tempArray[i] = current->Data;
		current = current->Next;
		i++;
	}

	cout << "Полученный стек: ";
	for (int j = stack->Length - 1; j >= 0; j--)
	{
		cout << tempArray[j] << " ";
	}
	cout << "\n";

	delete[] tempArray;
}