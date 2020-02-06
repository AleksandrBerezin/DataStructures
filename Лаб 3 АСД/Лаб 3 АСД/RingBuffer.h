#pragma once
#include "RingBuffer.h"
#include "Constant.h"

struct RingBuffer
{
	int* Buffer;
	int IndexRead;	
	int IndexWrite;
	//TODO: naming(Done)
	int Size;		
	int CurrentLength;		

	void Push(int element);
	int Pop();
	void Resize();
	bool IsEmpty();
	int GetFreeSpace();
	int GetOccupiedSpace();
	void Delete();
	void IncreaseIndex(int& index);

	RingBuffer()
	{
		Size = bufferSize;
		Buffer = new int[Size];
		IndexRead = 0;
		IndexWrite = 0;
		CurrentLength = 0;
	}
};

void Print(RingBuffer* ringBuffer);