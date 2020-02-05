#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

using namespace std;

// Добавление элемента в очередь
void RingBufferQueue::Enqueue(int element)
{
	if (Buffer->Length == Buffer->Size)
	{
		Buffer->Resize();
	}

	Buffer->Push(element);
}

// Извлечение элемента из очереди
int RingBufferQueue::Dequeue()
{
	return Buffer->Pop();
}

// Проверка: пуста очередь(true) или нет(false)
bool RingBufferQueue::IsEmpty()
{
	return Buffer->IsEmpty();
}

// Удаление очереди
void RingBufferQueue::Delete()
{
	Buffer->Delete();
	delete Buffer;
}

// Вывод на экран
void Print(RingBufferQueue* RingQueue)
{
	if (RingQueue->IsEmpty())
	{
		cout << "Очередь пустая.\n";
		return;
	}

	int length = RingQueue->Buffer->Length;
	int read = RingQueue->Buffer->IndexRead;
	int size = RingQueue->Buffer->Size;
	
	cout << "Текущая очередь: ";
	for (int i = 0; i < length; i++)
	{
		cout << RingQueue->Buffer->Buffer[read] << " ";
		read = (read + 1) % size;
	}
	cout << "\n";
}