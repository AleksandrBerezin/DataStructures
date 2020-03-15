#include "DynamicArray.h"
#include <iostream>
#include "../Common/CommonLibrary.h"
#include "../Common/Lab1/DynamicArrayLibrary.h"

using namespace std;

void MenuLab1()
{
	DynamicArray* array = new DynamicArray();
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� �������� � ������.\n"
			<< "2. �������� �������� �� �������.\n"
			<< "3. ������� �������� � ������.\n"
			<< "4. ������� �������� � �����.\n"
			<< "5. ������� ����� ������������� ��������.\n"
			<< "6. ���������� �������.\n"
			<< "7. �������� ����� �������� � �������.\n"
			<< "8. �������� ����� �������� � �������.\n"
			<< "0. �����.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				CheckArrayOnCreate(array);

				int value = InputIntValue();
				array->Add(value);
				Print(array);
				break;
			}
			case 2:
			{
				if (IsArrayNotCreateOrEmpty(array))
				{
					break;
				}

				if (IsArrayEmpty(array))
				{
					break;
				}

				int index = InputIndex();

				while (index < 0 || index >= array->Length)
				{
					cout << "�� ����� �������� ������, "
						<< "���������� ��� ���:\n";
					index = InputInt();
				}

				array->Delete(index);
				Print(array);
				break;
			}
			case 3:
			{
				CheckArrayOnCreate(array);

				int value = InputIntValue();
				array->Insert(value, 0);
				Print(array);
				break;
			}
			case 4:
			{
				CheckArrayOnCreate(array);

				int value = InputIntValue();
				array->Insert(value, array->Length);
				Print(array);
				break;
			}
			case 5:
			{
				CheckArrayOnCreate(array);

				if (IsArrayEmpty(array))
				{
					break;
				}

				int value = InputIntValue();
				int index = InputIndex();

				array->Insert(value, index + 1);
				Print(array);
				break;
			}
			case 6:
			{
				if (IsArrayNotCreateOrEmpty(array))
				{
					break;
				}

				array->InsertionSort();
				Print(array);
				break;
			}
			case 7:
			{
				if (IsArrayNotCreateOrEmpty(array))
				{
					break;
				}

				int value = InputIntValue();
				int index = array->LineSearch(value);

				if (index != -1)
				{
					cout << "������� ��������� ��� �������� "
						<< index << ".\n";
				}
				else
				{
					cout << "������ �������� ���.\n";
				}

				break;
			}
			case 8:
			{
				if (IsArrayNotCreateOrEmpty(array))
				{
					break;
				}
				if (!array->IsSorted)
				{
					cout << "������������ ������.\n";
					break;
				}

				int value = InputIntValue();
				int index = array->BinarySearch(value);

				if (index != -1)
				{
					cout << "������� ��������� ��� �������� "
						<< index << ".\n";
				}
				else
				{
					cout << "������ �������� ���.\n";
				}

				break;
			}
			case 0:
			{
				if (array == nullptr)
				{
					delete[] array->Array;
					delete array;
					array = nullptr;
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