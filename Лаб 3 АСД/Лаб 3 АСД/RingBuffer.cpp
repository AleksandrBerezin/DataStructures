#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"

using namespace std;

// ���������� �������� � �����
void RingBuffer::Push(int element)
{
	Buffer[IndexWrite] = element;
	//TODO: �����(Done)
	IncreaseIndexWrite();
	
	if (Length == Size)
	{
		//TODO: �����(Done)
		IncreaseIndexRead();
	}
	else
	{
		Length++;
	}
}

// ���������� �������� �� ������
int RingBuffer::Pop()
{
	int element = Buffer[IndexRead];
	//TODO: �����(Done)
	IncreaseIndexRead();
	Length--;
	
	return element;
}

// ��������� ������� ������
void RingBuffer::Resize()
{
	//TODO: ������� � ����������� ���������(Done)
	int* newBuffer = new int[Size * growthFactor];

	for (int i = 0; i < Length; i++)
	{
		newBuffer[i] = Buffer[IndexRead];
		//TODO: �����(Done)
		IncreaseIndexRead();
	}

	delete[] Buffer;
	Buffer = newBuffer;
	Size = Size * growthFactor;
	IndexRead = 0;
	IndexWrite = Length;
}

// ��������: ���� ��������� �����(true) ��� ���(false)
bool RingBuffer::IsEmpty()
{
	return Length == 0;
}

// ������� ���������� �����
int RingBuffer::GetFreeSpace()
{
	return Size - Length;
}

// ������� �������� �����
int RingBuffer::GetOccupiedSpace()
{
	return Length;
}

// �������� ������ (������� ������)
void RingBuffer::Delete()
{
	delete[] Buffer;
}

// ���������� �������, � �������� ���� ������
void RingBuffer::IncreaseIndexWrite()
{
	IndexWrite = (IndexWrite + 1) % Size;
}

// ���������� �������, � �������� ���� ������
void RingBuffer::IncreaseIndexRead()
{
	IndexRead = (IndexRead + 1) % Size;
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
	for (int i = 0; i < RingBuf->Length; i++)
	{
		cout << RingBuf->Buffer[read] << " ";
		read = (read + 1) % RingBuf->Size;
	}
	cout << "\n";
}