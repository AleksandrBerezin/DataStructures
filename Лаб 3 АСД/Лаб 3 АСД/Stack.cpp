#include <iostream>
#include "Constant.h"
#include "Node.h"
#include "Stack.h"

using namespace std;

// ���������� �������� � ����
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

// ���������� �������� �� ����� (����������)
int Stack::Pop()
{
	Node* last = Top;
	Top = Top->Next;
	
	int element = last->Data;
	Length--;
	delete last;

	return element;
}

// ��������� ������� �����
void Stack::Resize()
{
	//TODO: ������� � ����������� ���������
	Size = Size * 1.5;
}

// ��������: ���� ����(true) ��� ���(false)
bool Stack::IsEmpty()
{
	return Length == 0;
}

// �������� ����� (������� ������)
void Stack::Delete()
{
	Node* current = Top;
	//TODO: ������ �����?
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

// ����� �� �����
void Print(Stack* stack)
{
	if (stack->IsEmpty())
	{
		cout << "���� ����.\n";
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

	cout << "���������� ����: ";
	for (int j = stack->Length - 1; j >= 0; j--)
	{
		cout << tempArray[j] << " ";
	}
	cout << "\n";

	delete[] tempArray;
}