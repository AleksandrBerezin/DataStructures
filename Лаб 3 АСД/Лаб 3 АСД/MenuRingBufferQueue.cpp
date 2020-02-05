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
				if (ringQueue == nullptr)
				{
					ringQueue = new RingBufferQueue();
				}

				cout << "������� �������� ��������:\n";
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

//��������, ��� ���� �� ������ ��� ����
bool IsRingQueueNotCreateOrEmpty(RingBufferQueue* ringQueue)
{
	if (ringQueue == nullptr || ringQueue->IsEmpty())
	{
		cout << "������� ������.\n";
		return true;
	}

	return false;
}

//��������, ��� ���� �� ������
bool IsRingQueueNotCreate(RingBufferQueue* ringQueue)
{
	if (ringQueue == nullptr)
	{
		cout << "������� ������.\n";
		return true;
	}

	return false;
}