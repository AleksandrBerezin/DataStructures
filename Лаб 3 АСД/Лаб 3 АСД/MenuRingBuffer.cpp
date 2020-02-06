#include <iostream>
#include "RingBuffer.h"
#include "MenuRingBuffer.h"
#include "Functions.h"

using namespace std;

bool IsRingBufferNotCreateOrEmpty(RingBuffer* ringBuffer);
bool IsRingBufferNotCreate(RingBuffer* ringBuffer);

void Menu(RingBuffer*& ringBuffer)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� �������� � �����.\n"
			<< "2. ���������� �������� �� ������.\n"
			<< "3. �������� ��������� ����� � ������.\n"
			<< "4. �������� ������� ����� � ������.\n"
			<< "5. ���������� ������� ������.\n"
			<< "6. �������� ������.\n"
			<< "7. ����� ���������� ������ �� �����.\n"
			<< "0. �����.\n\n";

		int variant = Input();
		switch (variant)
		{
			case 1:
			{
				if (ringBuffer == nullptr)
				{
					ringBuffer = new RingBuffer();
				}

				cout << "������� �������� ��������:\n";
				ringBuffer->Push(Input());
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
				cout << "�������� ������� " << element << "\n";
				Print(ringBuffer);
				break;
			}
			case 3:
			{
				if (IsRingBufferNotCreate(ringBuffer))
				{
					break;
				}

				cout << "��������� ����� � ������ ����� "
					<< ringBuffer->GetFreeSpace() << ".\n";
				break;
			}
			case 4:
			{
				if (IsRingBufferNotCreate(ringBuffer))
				{
					break;
				}

				cout << "������� ����� � ������ ����� "
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
				cout << "������ �������� �������, ���������� ��� ���.\n";
				break;
			}
		}
	}

	return;
}

//��������, ��� ���� �� ������ ��� ����
bool IsRingBufferNotCreateOrEmpty(RingBuffer* ringBuffer)
{
	if (IsRingBufferNotCreate(ringBuffer) || ringBuffer->IsEmpty())
	{
		cout << "��������� ����� ����.\n";
		return true;
	}

	return false;
}

//��������, ��� ���� �� ������
bool IsRingBufferNotCreate(RingBuffer* ringBuffer)
{
	if (ringBuffer == nullptr)
	{
		cout << "��������� ����� ����.\n";
		return true;
	}

	return false;
}