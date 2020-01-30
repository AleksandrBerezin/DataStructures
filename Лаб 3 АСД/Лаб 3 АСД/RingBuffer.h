#pragma once
struct RingBuffer
{
	int* Buffer;
	int Read; // ������, � �������� ���� ������
	int Write; // ������, � �������� ���� ������
	int Size; // ������ ������
	int Length; // ���������� ��������� � ������

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