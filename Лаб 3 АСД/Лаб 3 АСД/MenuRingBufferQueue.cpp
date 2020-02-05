#include <iostream>
#include "RingBufferQueue.h"
#include "MenuRingBufferQueue.h"
#include "Functions.h"

using namespace std;

bool IsRingQueueNotCreateOrEmpty(RingBufferQueue* ringQueue);
bool IsRingQueueNotCreate(RingBufferQueue* ringQueue);

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

		int variant = Input();
		switch (variant)
		{
			case 1:
			{
				if (ringQueue == nullptr)
				{
					ringQueue = new RingBufferQueue();
				}

				cout << "Введите значение элемента:\n";
				ringQueue->Enqueue(Input());
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

//Проверка, что стек не создан или пуст
bool IsRingQueueNotCreateOrEmpty(RingBufferQueue* ringQueue)
{
	if (ringQueue == nullptr || ringQueue->IsEmpty())
	{
		cout << "Очередь пустая.\n";
		return true;
	}

	return false;
}

//Проверка, что стек не создан
bool IsRingQueueNotCreate(RingBufferQueue* ringQueue)
{
	if (ringQueue == nullptr)
	{
		cout << "Очередь пустая.\n";
		return true;
	}

	return false;
}