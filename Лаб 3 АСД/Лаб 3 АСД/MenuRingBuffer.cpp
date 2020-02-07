#include <iostream>
#include "RingBuffer.h"
#include "MenuRingBuffer.h"
#include "..\..\Libraries\CommonLibrary.h"
#include "..\..\Libraries\RingBufferLibrary.h"

using namespace std;

void Menu(RingBuffer*& ringBuffer)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента в буфер.\n"
			<< "2. Извлечение элемента из буфера.\n"
			<< "3. Показать свободное место в буфере.\n"
			<< "4. Показать занятое место в буфере.\n"
			<< "5. Увеличение размера буфера.\n"
			<< "6. Удаление буфера.\n"
			<< "7. Вывод кольцевого буфера на экран.\n"
			<< "0. Назад.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (ringBuffer == nullptr)
				{
					ringBuffer = new RingBuffer();
				}

				int value = InputIntValue();
				ringBuffer->Push(value);
				Print(ringBuffer);
				break;
			}
			case 2:
			{
				if (IsRingBufferNotCreateOrEmpty(ringBuffer))
				{
					break;
				}

				int element = ringBuffer->Pop();
				cout << "Извлекли элемент " << element << "\n";
				Print(ringBuffer);
				break;
			}
			case 3:
			{
				if (IsRingBufferNotCreate(ringBuffer))
				{
					break;
				}

				cout << "Свободное место в буфере равно "
					<< ringBuffer->GetFreeSpace() << ".\n";
				break;
			}
			case 4:
			{
				if (IsRingBufferNotCreate(ringBuffer))
				{
					break;
				}

				cout << "Занятое место в буфере равно "
					<< ringBuffer->GetOccupiedSpace() << ".\n";
				break;
			}
			case 5:
			{
				if (IsRingBufferNotCreate(ringBuffer))
				{
					break;
				}

				ringBuffer->Resize();
				break;
			}
			case 6:
			{
				if (IsRingBufferNotCreate(ringBuffer))
				{
					break;
				}

				ringBuffer->Delete();
				delete ringBuffer;
				ringBuffer = nullptr;
				break;
			}
			case 7:
			{
				if (IsRingBufferNotCreate(ringBuffer))
				{
					break;
				}

				Print(ringBuffer);
				break;
			}
			case 0:
			{
				isBack = true;
				break;
			}
			default:
			{
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}