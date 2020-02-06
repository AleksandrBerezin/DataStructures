#include <iostream>
#include "Constant.h"
#include "StackNode.h"
#include "Stack.h"

using namespace std;

// ���������� �������� � ����
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

	Length++;
}

// ���������� �������� �� ����� (����������)
int Stack::Pop()
{
	StackNode* last = TopElement;
	TopElement = TopElement->Next;
	
	int element = last->Data;
	Length--;
	delete last;

	return element;
}

// ��������� ������� �����
void Stack::Resize()
{
	Size = Size * growthFactor;
}

// ��������: ���� ����(true) ��� ���(false)
bool Stack::IsEmpty()
{
	return Length == 0;
}

// �������� ����� (������� ������)
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
	Length = 0;
	Size = 0;
}

// ����� �� �����
void Print(Stack* stack)
{
	if (stack->IsEmpty())
	{
		cout << "���� ����.\n";
		return;
	}

	int* tempArray = new int[stack->Length];
	StackNode* current = stack->TopElement;

	int i = 0;
	while (current != nullptr)
	{
		tempArray[i] = current->Data;
		current = current->Next;
		i++;
	}

	cout << "���������� ����: ";
	for (int j = stack->Length - 1; j >= 0; j--)
	{
		cout << tempArray[j] << " ";
	}
	cout << "\n";

	delete[] tempArray;
}