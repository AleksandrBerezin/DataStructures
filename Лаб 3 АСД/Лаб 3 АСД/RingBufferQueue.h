#pragma once
struct RingBufferQueue
{
	//TODO: Naming
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