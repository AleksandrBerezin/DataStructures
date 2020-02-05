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
		cout << "\n�������� �������:\n";
		cout << "1. ���������� �������� � �������.\n"
			<< "2. ���������� �������� �� �������.\n"
			<< "3. �������� �������.\n"
			<< "4. ����� ������� �� �����.\n"
			<< "0. �����.\n\n";

		int variant = Input();
		switch (variant)
		{
			case 1:
			{
				if (stackQueue == nullptr)
				{
					stackQueue = new TwoStackQueue();
				}

				cout << "������� �������� ��������:\n";
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

//��������, ��� ���� �� ������ ��� ����
bool IsStackQueueNotCreateOrEmpty(TwoStackQueue* stackQueue)
{
	if (stackQueue == nullptr || stackQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return true;
	}

	return false;
}

//��������, ��� ���� �� ������
bool IsStackQueueNotCreate(TwoStackQueue* stackQueue)
{
	if (stackQueue == nullptr)
	{
		cout << "������� ������.\n";
		return true;
	}

	return false;
}