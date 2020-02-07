#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

using namespace std;

// ���������� �������� � �������
void RingBufferQueue::Enqueue(int element)
{
	if (Buffer->CurrentLength == Buffer->Size)
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