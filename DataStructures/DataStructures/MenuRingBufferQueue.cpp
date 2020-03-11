#include <iostream>
#include "RingBufferQueue.h"
#include "MenuRingBufferQueue.h"
#include "CommonLibrary.h"
#include "RingQueueLibrary.h"

using namespace std;

void Menu(RingBufferQueue*& ringQueue)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента в очередь.\n"
			<< "2. Извлечение элемента из очереди.\n"
			<< "3. Удаление очереди.\n"
			<< "4. Вывод очереди на экран.\n"
			<< "0. Назад.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (ringQueue == nullptr)
				{
					ringQueue = new RingBufferQueue();
				}

				int value = InputIntValue();
				ringQueue->Enqueue(value);
				Print(ringQueue);
				break;
			}
			case 2:
			{
				if (IsRingQueueNotCreateOrEmpty(ringQueue))
				{
					break;
				}

				int element = ringQueue->Dequeue();
				cout << "Извлекли элемент " << element << "\n";
				Print(ringQueue);
				break;
			}
			case 3:
			{
				if (IsRingQueueNotCreate(ringQueue))
				{
					break;
				}

				ringQueue->Delete();
				delete ringQueue;
				ringQueue = nullptr;
				break;
			}
			case 4:
			{
				if (IsRingQueueNotCreate(ringQueue))
				{
					break;
				}

				Print(ringQueue);
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