#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"

using namespace std;

// Добавление элемента в буфер
void RingBuffer::Push(int element)
{
	Buffer[IndexWrite] = element;
	IncreaseIndex(IndexWrite);
	
	if (CurrentLength == Size)
	{
		IncreaseIndex(IndexRead);
	}
	else
	{
		CurrentLength++;
	}
}

// Извлечение элемента из буфера
int RingBuffer::Pop()
{
	int element = Buffer[IndexRead];
	IncreaseIndex(IndexRead);
	CurrentLength--;
	
	return element;
}

// Изменение размера буфера
void RingBuffer::Resize()
{
	int* newBuffer = new int[Size * growthFactor];

	for (int i = 0; i < CurrentLength; i++)
	{
		newBuffer[i] = Buffer[IndexRead];
		IncreaseIndex(IndexRead);
	}

	delete[] Buffer;
	Buffer = newBuffer;
	Size = Size * growthFactor;
	IndexRead = 0;
	IndexWrite = CurrentLength;
}

// Проверка: пуст кольцевой буфер(true) или нет(false)
bool RingBuffer::IsEmpty()
{
	return CurrentLength == 0;
}

// Возврат свободного места
int RingBuffer::GetFreeSpace()
{
	return Size - CurrentLength;
}

// Возврат занятого места
int RingBuffer::GetOccupiedSpace()
{
	return CurrentLength;
}

// Удаление буфера (очистка памяти)
void RingBuffer::Delete()
{
	delete[] Buffer;
}

// Увеличение индекса
void RingBuffer::IncreaseIndex(int& index)
{
	//TODO: дубль(Done)
	index = (index + 1) % Size;
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