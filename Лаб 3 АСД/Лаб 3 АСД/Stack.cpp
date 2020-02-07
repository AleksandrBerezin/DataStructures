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

	CurrentLength++;
}

// ���������� �������� �� ����� (����������)
int Stack::Pop()
{
	StackNode* last = TopElement;
	TopElement = TopElement->Next;
	
	int element = last->Data;
	CurrentLength--;
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
	return CurrentLength == 0;
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
	CurrentLength = 0;
	Size = 0;
}