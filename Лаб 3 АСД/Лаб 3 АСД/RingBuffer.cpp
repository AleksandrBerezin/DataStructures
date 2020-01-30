#include <iostream>
#include "Constant.h"
#include "RingBuffer.h"

using namespace std;

// Добавление элемента в буфер
void RingBuffer::Push(int element)
{
	Buffer[Write] = element;
	Write = (Write + 1) % Size;
	
	if (Length == Size)
	{
		Read = (Read + 1) % Size;
	}
	else
	{
		Length++;
	}
}

// Извлечение элемента из буфера
int RingBuffer::Pop()
{
	int element = Buffer[Read];
	Read = (Read + 1) % Size;
	Length--;
	
	return element;
}

// Изменение размера буфера
void RingBuffer::Resize()
{
	int* newBuffer = new int[Size * 1.5];

	for (int i = 0; i < Length; i++)
	{
		newBuffer[i] = Buffer[Read];
		Read = (Read + 1) % Size;
	}

	delete[] Buffer;
	Buffer = newBuffer;
	Size = Size * 1.5;
	Read = 0;
	Write = Length;
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

// Вывод на экран
void Print(RingBuffer* RingBuf)
{
	if (RingBuf->IsEmpty())
	{
		cout << "Кольцевой буфер пуст.\n";
		return;
	}

	int read = RingBuf->Read;
	cout << "Кольцевой буфер: ";
	for (int i = 0; i < RingBuf->Length; i++)
	{
		cout << RingBuf->Buffer[read] << " ";
		read = (read + 1) % RingBuf->Size;
	}
	cout << "\n";
}