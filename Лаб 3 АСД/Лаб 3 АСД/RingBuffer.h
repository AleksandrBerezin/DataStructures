#pragma once
#include "RingBuffer.h"
#include "Constant.h"

struct RingBuffer
{
	int* Buffer;
	//TODO: naming(Done)
	int IndexRead; // Индекс, с которого идет чтение
	int IndexWrite; // Индекс, с которого идет запись
	int Size; // Размер буфера
	int Length; // Количество элементов в буфере

	void Push(int element);
	int Pop();
	void Resize();
	bool IsEmpty();
	int GetFreeSpace();
	int GetOccupiedSpace();
	void Delete();
	void IncreaseIndexWrite();
	void IncreaseIndexRead();

	RingBuffer()
	{
		Size = bufferSize;
		Buffer = new int[Size];
		IndexRead = 0;
		IndexWrite = 0;
		Length = 0;
	}
};

void Print(RingBuffer* ringBuffer);