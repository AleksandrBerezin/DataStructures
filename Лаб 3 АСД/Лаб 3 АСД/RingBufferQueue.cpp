#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

using namespace std;

// Добавление элемента в очередь
void RingBufferQueue::Enqueue(int element)
{
	if (RingBuf->Length == RingBuf->Size)
	{
		RingBuf->Resize();
	}

	RingBuf->Push(element);
}

// Извлечение элемента из очереди
int RingBufferQueue::Dequeue()
{
	return RingBuf->Pop();
}

// Проверка: пуста очередь(true) или нет(false)
bool RingBufferQueue::IsEmpty()
{
	return RingBuf->IsEmpty();
}

// Удаление очереди
void RingBufferQueue::Delete()
{
	RingBuf->Delete();
	delete RingBuf;
}

// Вывод на экран
void Print(RingBufferQueue* RingQueue)
{
	if (RingQueue->IsEmpty())
	{
		cout << "Очередь пустая.\n";
		return;
	}

	int length = RingQueue->RingBuf->Length;
	int read = RingQueue->RingBuf->Read;
	int size = RingQueue->RingBuf->Size;
	
	cout << "Текущая очередь: ";
	for (int i = 0; i < length; i++)
	{
		cout << RingQueue->RingBuf->Buffer[read] << " ";
		read = (read + 1) % size;
	}
	cout << "\n";
}