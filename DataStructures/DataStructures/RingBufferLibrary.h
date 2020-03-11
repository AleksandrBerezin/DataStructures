#pragma once

#include <iostream>
#include "RingBuffer.h"

using namespace std;

/*
	������� ��� ���������� ������
*/

//��������, ��� ��������� ����� �� ������ ��� ����
bool IsRingBufferNotCreateOrEmpty(RingBuffer* ringBuffer)
{
	if (ringBuffer == nullptr || ringBuffer->IsEmpty())
	{
		cout << "��������� ����� ����.\n";
		return true;
	}

	return false;
}

//��������, ��� ��������� ����� �� ������
bool IsRingBufferNotCreate(RingBuffer* ringBuffer)
{
	if (ringBuffer == nullptr)
	{
		cout << "��������� ����� ����.\n";
		return true;
	}

	return false;
}

// ����� �� �����
void Print(RingBuffer* RingBuf)
{
	if (RingBuf->IsEmpty())
	{
		cout << "��������� ����� ����.\n";
		return;
	}

	int read = RingBuf->IndexRead;
	cout << "��������� �����: ";
	for (int i = 0; i < RingBuf->CurrentLength; i++)
	{
		cout << RingBuf->Buffer[read] << " ";
		read = (read + 1) % RingBuf->Size;
	}
	cout << "\n";
}