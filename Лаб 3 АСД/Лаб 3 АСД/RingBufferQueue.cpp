#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

using namespace std;

// ���������� �������� � �������
void RingBufferQueue::Enqueue(int element)
{
	if (Buffer->Length == Buffer->Size)
	{
		Buffer->Resize();
	}

	Buffer->Push(element);
}

// ���������� �������� �� �������
int RingBufferQueue::Dequeue()
{
	return Buffer->Pop();
}

// ��������: ����� �������(true) ��� ���(false)
bool RingBufferQueue::IsEmpty()
{
	return Buffer->IsEmpty();
}

// �������� �������
void RingBufferQueue::Delete()
{
	Buffer->Delete();
	delete Buffer;
}

// ����� �� �����
void Print(RingBufferQueue* RingQueue)
{
	if (RingQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return;
	}

	int length = RingQueue->Buffer->Length;
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