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
				cout << "�������� ������� " << element << "\n";
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
				cout << "������ �������� �������, ���������� ��� ���.\n";
				break;
			}
		}
	}

	return;
}