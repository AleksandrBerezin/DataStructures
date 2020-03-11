#pragma once

#include <iostream>
#include "RingBuffer.h"

using namespace std;

/*
	Функции для кольцевого буфера
*/

//Проверка, что кольцевой буфер не создан или пуст
bool IsRingBufferNotCreateOrEmpty(RingBuffer* ringBuffer)
{
	if (ringBuffer == nullptr || ringBuffer->IsEmpty())
	{
		cout << "Кольцевой буфер пуст.\n";
		return true;
	}

	return false;
}

//Проверка, что кольцевой буфер не создан
bool IsRingBufferNotCreate(RingBuffer* ringBuffer)
{
	if (ringBuffer == nullptr)
	{
		cout << "Кольцевой буфер пуст.\n";
		return true;
	}

	return false;
}

// Вывод на экран
void Print(RingBuffer* RingBuf)
{
	if (RingBuf->IsEmpty())
	{
		cout << "Кольцевой буфер пуст.\n";
		return;
	}

	int read = RingBuf->IndexRead;
	cout << "Кольцевой буфер: ";
	for (int i = 0; i < RingBuf->CurrentLength; i++)
	{
		cout << RingBuf->Buffer[read] << " ";
		read = (read + 1) % RingBuf->Size;
	}
	cout << "\n";
}