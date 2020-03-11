#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"
#include "TwoStackQueue.h"
#include "MenuStack.h"
#include "MenuRingBuffer.h"
#include "MenuRingBufferQueue.h"
#include "MenuTwoStackQueue.h"
#include "CommonLibrary.h"

using namespace std;

void MenuLab3()
{
	Stack* stack = new Stack;
	RingBuffer* ringBuffer = new RingBuffer;
	RingBufferQueue* ringQueue = new RingBufferQueue;
	TwoStackQueue* stackQueue = new TwoStackQueue;

	bool isBack = false;

	while (!isBack)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. Стек.\n"
			<< "2. Кольцевой буфер.\n"
			<< "3. Очередь на базе кольцевого буфера.\n"
			<< "4. Очередь на базе 2 стеков.\n"
			<< "0. Назад.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				Menu(stack);
				break;
			}
			case 2:
			{
				Menu(ringBuffer);
				break;
			}
			case 3:
			{
				Menu(ringQueue);
				break;
			}
			case 4:
			{
				Menu(stackQueue);
				break;
			}
			case 0:
			{
				isBack = true;

				if (stack != nullptr)
				{
					stack->Delete();
					delete stack;
					stack = nullptr;
				}
				if (ringBuffer != nullptr)
				{
					ringBuffer->Delete();
					delete ringBuffer;
					ringBuffer = nullptr;
				}
				if (ringQueue != nullptr)
				{
					ringQueue->Delete();
					delete ringQueue;
					ringQueue = nullptr;
				}
				if (stackQueue != nullptr)
				{
					stackQueue->Delete();
					delete stackQueue;
					stackQueue = nullptr;
				}

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