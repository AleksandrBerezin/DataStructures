#include <iostream>
#include "ConstantLab3.h"
#include "Stack.h"
#include "TwoStackQueue.h"

using namespace std;

// ���������� �������� � �������
void TwoStackQueue::Enqueue(int element)
{
	if (InputStack->CurrentLength == InputStack->Size)
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