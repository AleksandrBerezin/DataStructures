#pragma once
struct RingBufferQueue
{
	RingBuffer* RingBuf;

	void Enqueue(int element);
	int Dequeue();
	bool IsEmpty();
	void Delete();

	RingBufferQueue()
	{
		RingBuf = new RingBuffer;
	}
};

void Print(RingBufferQueue* RingBuf);