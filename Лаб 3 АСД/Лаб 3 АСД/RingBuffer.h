#pragma once
struct RingBuffer
{
	int* Buffer;
	int Read; // Индекс, с которого идет чтение
	int Write; // Индекс, с которого идет запись
	int Size; // Размер буфера
	int Length; // Количество элементов в буфере

	void Push(int element);
	int Pop();
	void Resize();
	bool IsEmpty();
	int GetFreeSpace();
	int GetOccupiedSpace();
	void Delete();

	RingBuffer()
	{
		Size = BUFFERSIZE;
		Buffer = new int[Size];
		Read = 0;
		Write = 0;
		Length = 0;
	}
};

void Print(RingBuffer* RingBuf);