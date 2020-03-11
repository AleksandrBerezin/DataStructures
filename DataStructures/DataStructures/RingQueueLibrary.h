#pragma once

#include <iostream>
#include "RingBufferQueue.h"

using namespace std;

/*
	������� ��� ������� �� ������ ���������� ������
*/

//��������, ��� ������� �� ������� ��� ����
bool IsRingQueueNotCreateOrEmpty(RingBufferQueue* ringQueue)
{
	if (ringQueue == nullptr || ringQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return true;
	}

	return false;
}

//��������, ��� ������� �� �������
bool IsRingQueueNotCreate(RingBufferQueue* ringQueue)
{
	if (ringQueue == nullptr)
	{
		cout << "������� ������.\n";
		return true;
	}

	return false;
}

// ����� �� �����
void Print(RingBufferQueue* RingQueue)
{
	if (RingQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return;
	}

	int length = RingQueue->Buffer->CurrentLength;
	int read = RingQueue->Buffer->IndexRead;
	int size = RingQueue->Buffer->Size;

	cout << "������� �������: ";
	for (int i = 0; i < length; i++)
	{
		cout << RingQueue->Buffer->Buffer[read] << " ";
		read = (read + 1) % size;
	}
	cout << "\n";
}