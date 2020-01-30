#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"

using namespace std;

// ���������� �������� � �����
void RingBuffer::Push(int element)
{
	Buffer[Write] = element;
	Write = (Write + 1) % Size;
	
	if (Length == Size)
	{
		Read = (Read + 1) % Size;
	}
	else
	{
		Length++;
	}
}

// ���������� �������� �� ������
int RingBuffer::Pop()
{
	int element = Buffer[Read];
	Read = (Read + 1) % Size;
	Length--;
	
	return element;
}

// ��������� ������� ������
void RingBuffer::Resize()
{
	int* newBuffer = new int[Size * 1.5];

	for (int i = 0; i < Length; i++)
	{
		newBuffer[i] = Buffer[Read];
		Read = (Read + 1) % Size;
	}

	delete[] Buffer;
	Buffer = newBuffer;
	Size = Size * 1.5;
	Read = 0;
	Write = Length;
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

// ����� �� �����
void Print(RingBuffer* RingBuf)
{
	if (RingBuf->IsEmpty())
	{
		cout << "��������� ����� ����.\n";
		return;
	}

	int read = RingBuf->Read;
	cout << "��������� �����: ";
	for (int i = 0; i < RingBuf->Length; i++)
	{
		cout << RingBuf->Buffer[read] << " ";
		read = (read + 1) % RingBuf->Size;
	}
	cout << "\n";
}