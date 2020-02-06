#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"

using namespace std;

// Добавление элемента в буфер
void RingBuffer::Push(int element)
{
	Buffer[IndexWrite] = element;
	IncreaseIndexWrite();
	
	if (Length == Size)
	{
		IncreaseIndexRead();
	}
	else
	{
		Length++;
	}
}

// Извлечение элемента из буфера
int RingBuffer::Pop()
{
	int element = Buffer[IndexRead];
	IncreaseIndexRead();
	Length--;
	
	return element;
}

// Изменение размера буфера
void RingBuffer::Resize()
{
	int* newBuffer = new int[Size * growthFactor];

	for (int i = 0; i < Length; i++)
	{
		newBuffer[i] = Buffer[IndexRead];
		IncreaseIndexRead();
	}

	delete[] Buffer;
	Buffer = newBuffer;
	Size = Size * growthFactor;
	IndexRead = 0;
	IndexWrite = Length;
}

// Проверка: пуст кольцевой буфер(true) или нет(false)
bool RingBuffer::IsEmpty()
{
	return Length == 0;
}

// Возврат свободного места
int RingBuffer::GetFreeSpace()
{
	return Size - Length;
}

// Возврат занятого места
int RingBuffer::GetOccupiedSpace()
{
	return Length;
}

// Удаление буфера (очистка памяти)
void RingBuffer::Delete()
{
	delete[] Buffer;
}

// Увеличение индекса, с которого идет запись
void RingBuffer::IncreaseIndexWrite()
{
	//TODO: дубль
	IndexWrite = (IndexWrite + 1) % Size;
}

// Увеличение индекса, с которого идет чтение
void RingBuffer::IncreaseIndexRead()
{
	//TODO: дубль
	IndexRead = (IndexRead + 1) % Size;
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
	for (int i = 0; i < RingBuf->Length; i++)
	{
		cout << RingBuf->Buffer[read] << " ";
		read = (read + 1) % RingBuf->Size;
	}
	cout << "\n";
}