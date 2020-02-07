#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

using namespace std;

// Добавление элемента в очередь
void RingBufferQueue::Enqueue(int element)
{
	if (Buffer->CurrentLength == Buffer->Size)
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