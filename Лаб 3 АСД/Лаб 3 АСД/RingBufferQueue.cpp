#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

using namespace std;

// ���������� �������� � �������
void RingBufferQueue::Enqueue(int element)
{
	if (RingBuf->Length == RingBuf->Size)
	{
		RingBuf->Resize();
	}

	RingBuf->Push(element);
}

// ���������� �������� �� �������
int RingBufferQueue::Dequeue()
{
	return RingBuf->Pop();
}

// ��������: ����� �������(true) ��� ���(false)
bool RingBufferQueue::IsEmpty()
{
	return RingBuf->IsEmpty();
}

// �������� �������
void RingBufferQueue::Delete()
{
	RingBuf->Delete();
	delete RingBuf;
}

// ����� �� �����
void Print(RingBufferQueue* RingQueue)
{
	if (RingQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return;
	}

	int length = RingQueue->RingBuf->Length;
	int read = RingQueue->RingBuf->Read;
	int size = RingQueue->RingBuf->Size;
	
	cout << "������� �������: ";
	for (int i = 0; i < length; i++)
	{
		cout << RingQueue->RingBuf->Buffer[read] << " ";
		read = (read + 1) % size;
	}
	cout << "\n";
}