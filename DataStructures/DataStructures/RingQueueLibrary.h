#pragma once

#include <iostream>
#include "RingBufferQueue.h"

using namespace std;

/*
	Функции для очереди на основе кольцевого буфера
*/

//Проверка, что очередь не создана или пуст
bool IsRingQueueNotCreateOrEmpty(RingBufferQueue* ringQueue)
{
	if (ringQueue == nullptr || ringQueue->IsEmpty())
	{
		cout << "Очередь пустая.\n";
		return true;
	}

	return false;
}

//Проверка, что очередь не создана
bool IsRingQueueNotCreate(RingBufferQueue* ringQueue)
{
	if (ringQueue == nullptr)
	{
		cout << "Очередь пустая.\n";
		return true;
	}

	return false;
}

// Вывод на экран
void Print(RingBufferQueue* RingQueue)
{
	if (RingQueue->IsEmpty())
	{
		cout << "Очередь пустая.\n";
		return;
	}

	int length = RingQueue->Buffer->CurrentLength;
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