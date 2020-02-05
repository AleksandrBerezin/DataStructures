#include <iostream>
#include "TwoStackQueue.h"
#include "MenuStack.h"
#include "Functions.h"

using namespace std;

bool IsStackQueueNotCreateOrEmpty(TwoStackQueue* stackQueue);
bool IsStackQueueNotCreate(TwoStackQueue* stackQueue);

void Menu(TwoStackQueue*& stackQueue)
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
				if (stackQueue == nullptr)
				{
					stackQueue = new TwoStackQueue();
				}

				cout << "Введите значение элемента:\n";
				stackQueue->Enqueue(Input());
				Print(stackQueue);
				break;
			}
			case 2:
			{
				if (IsStackQueueNotCreateOrEmpty(stackQueue))
				{
					break;
				}

				int element = stackQueue->Dequeue();
				cout << "Извлекли элемент " << element << "\n";
				Print(stackQueue);
				break;
			}
			case 3:
			{
				if (IsStackQueueNotCreate(stackQueue))
				{
					break;
				}

				stackQueue->Delete();
				delete stackQueue;
				stackQueue = nullptr;
				break;
			}
			case 4:
			{
				if (IsStackQueueNotCreate(stackQueue))
				{
					break;
				}

				Print(stackQueue);
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
bool IsStackQueueNotCreateOrEmpty(TwoStackQueue* stackQueue)
{
	if (stackQueue == nullptr || stackQueue->IsEmpty())
	{
		cout << "Очередь пустая.\n";
		return true;
	}

	return false;
}

//Проверка, что стек не создан
bool IsStackQueueNotCreate(TwoStackQueue* stackQueue)
{
	if (stackQueue == nullptr)
	{
		cout << "Очередь пустая.\n";
		return true;
	}

	return false;
}