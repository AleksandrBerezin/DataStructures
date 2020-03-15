#include <iostream>
#include <ctime>
#include "ListNode.h"
#include "List.h"
#include "../Common/CommonLibrary.h"
#include "../Common/Lab2/ListLibrary.h"

using namespace std;

void MenuLab2()
{
	List* list = new List();
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� ��������.\n"
			<< "2. �������� ��������.\n"
			<< "3. ������� �������� � ������.\n"
			<< "4. ������� �������� � �����.\n"
			<< "5. ������� ����� ������������� ��������.\n"
			<< "6. ������� ����� ������������ ���������.\n"
			<< "7. ���������� ������.\n"
			<< "8. �������� ����� �������� � �������.\n"
			<< "9. ��������� ������� ��� ��������.\n"
			<< "10. ��������� ������� ��� �������.\n"
			<< "0. �����.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				CheckListOnCreate(list);

				int value = InputIntValue();
				list->Add(value);
				Print(list);
				break;
			}
			case 2:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				cout << "������� ������ ��������, ������� ����� �������:\n";
				int index = InputInt();

				while (index < 0 || index >= list->Length)
				{
					cout << "�������� � ����� �������� ���, "
						<< "���������� ��� ���:\n";
					index = InputInt();
				}

				list->Remove(index);
				Print(list);
				break;
			}
			case 3:
			{
				CheckListOnCreate(list);

				int value = InputIntValue();
				list->InsertBefore(0, value);
				Print(list);
				break;
			}
			case 4:
			{
				CheckListOnCreate(list);

				int value = InputIntValue();
				list->InsertAfter(list->Length - 1, value);
				Print(list);
				break;
			}
			case 5:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				int index = InputIndex();

				FindCorrectIndex(list, &index);

				int value = InputIntValue();

				list->InsertAfter(index, value);
				Print(list);
				break;
			}
			case 6:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				int index = InputIndex();

				FindCorrectIndex(list, &index);
				int value = InputIntValue();

				list->InsertBefore(index, value);
				Print(list);
				break;
			}
			case 7:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				list->InsertionSort();
				Print(list);
				break;
			}
			case 8:
			{
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				int value = InputIntValue();
				int index = list->Search(value);

				if (index == -1)
				{
					cout << "������ �������� ���.\n";
				}
				else
				{
					cout << "������� ��������� ��� �������� " << index << ".\n";
				}
				break;
			}
			case 9:
			{
				if (list != nullptr)
				{
					list->Delete();
					delete list;
				}

				list = new List();

				cout << "������� ���������� ��������� ������:\n";
				int count = InputInt();

				InsertCountElement(list, count);
				int middle = list->Length / 2;

				clock_t begin = clock();

				list->Remove(middle);

				ShowFunctionRunTime(begin);
				list->Delete();
				break;
			}
			case 10:
			{
				if (list != nullptr)
				{
					list->Delete();
					delete list;
				}

				list = new List();

				cout << "������� ���������� ��������� ������:\n";
				int count = InputInt();

				InsertCountElement(list, count);
				int middle = list->Length / 2;

				clock_t begin = clock();

				list->InsertAfter(middle, 1);

				ShowFunctionRunTime(begin);
				list->Delete();
				break;
			}
			case 0:
			{
				if (list != nullptr)
				{
					list->Delete();
					delete list;
					list = nullptr;
				}

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