#pragma once
#include "RingBuffer.h"
#include "RingBufferQueue.h"

struct RingBufferQueue
{
	//TODO: Naming(Done)
	RingBuffer* Buffer;

	void Enqueue(int element);
	int Dequeue();
	bool IsEmpty();
	void Delete();

	RingBufferQueue()
	{
		Buffer = new RingBuffer;
	}
};

void Print(RingBufferQueue* ringBuffer);