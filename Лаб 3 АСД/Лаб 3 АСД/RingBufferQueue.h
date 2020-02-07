#pragma once
#include "RingBuffer.h"

struct RingBufferQueue
{
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