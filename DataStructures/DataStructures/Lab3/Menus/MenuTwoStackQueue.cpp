#include <iostream>
#include "../TwoStackQueue.h"
#include "MenuStack.h"
#include "../../Common/CommonLibrary.h"
#include "../../Common/Lab3/TwoStackQueueLibrary.h"

using namespace std;

void Menu(TwoStackQueue*& stackQueue)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� �������� � �������.\n"
			<< "2. ���������� �������� �� �������.\n"
			<< "3. �������� �������.\n"
			<< "4. ����� ������� �� �����.\n"
			<< "0. �����.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (stackQueue == nullptr)
				{
					stackQueue = new TwoStackQueue();
				}

				int value = InputIntValue();
				stackQueue->Enqueue(value);
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
				cout << "�������� ������� " << element << "\n";
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
				cout << "������ �������� �������, ���������� ��� ���.\n";
				break;
			}
		}
	}

	return;
}