#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"

using namespace std;

// ���������� �������� � �����
void RingBuffer::Push(int element)
{
	Buffer[IndexWrite] = element;
	IncreaseIndex(IndexWrite);
	
	if (CurrentLength == Size)
	{
		IncreaseIndex(IndexRead);
	}
	else
	{
		CurrentLength++;
	}
}

// ���������� �������� �� ������
int RingBuffer::Pop()
{
	int element = Buffer[IndexRead];
	IncreaseIndex(IndexRead);
	CurrentLength--;
	
	return element;
}

// ��������� ������� ������
void RingBuffer::Resize()
{
	int* newBuffer = new int[Size * growthFactor];

	for (int i = 0; i < CurrentLength; i++)
	{
		newBuffer[i] = Buffer[IndexRead];
		IncreaseIndex(IndexRead);
	}

	delete[] Buffer;
	Buffer = newBuffer;
	Size = Size * growthFactor;
	IndexRead = 0;
	IndexWrite = CurrentLength;
}

// ��������: ���� ��������� �����(true) ��� ���(false)
bool RingBuffer::IsEmpty()
{
	return CurrentLength == 0;
}

// ������� ���������� �����
int RingBuffer::GetFreeSpace()
{
	return Size - CurrentLength;
}

// ������� �������� �����
int RingBuffer::GetOccupiedSpace()
{
	return CurrentLength;
}

// �������� ������ (������� ������)
void RingBuffer::Delete()
{
	delete[] Buffer;
}

// ���������� �������
void RingBuffer::IncreaseIndex(int& index)
{
	//TODO: �����(Done)
	index = (index + 1) % Size;
}