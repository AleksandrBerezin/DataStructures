#include <iostream>
#include <ctime>
#include "Node.h"
#include "List.h"

//TODO: �� ��������� ������� ��-������
using namespace std;

int Input();
bool IsListNotCreateOrEmpty(List* list);
void CheckListOnCreate(List* list);
int InputIndex();
int InputValue();
void FindCorrectIndex(List* list, int* index);
void ShowFunctionRunTime(clock_t begin);

int main()
{
	setlocale(LC_ALL, "Russian");

	List* list = new List();
	//TODO: Naming(Done)
	bool isExit = false;

	while (!isExit)
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

		switch (Input())
		{
			case 1:
			{
					//TODO: �����(Done)
				CheckListOnCreate(list);

				cout << "������� �������� ��������:\n";
				list->Add(Input());
				Print(list);
				break;
			}
			case 2:
			{
					//TODO: �����(Done)
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				cout << "������� ������ ��������, ������� ����� �������:\n";
				int index = Input();

				while (index < 0 || index >= list->Length)
				{
					cout << "�������� � ����� �������� ���, "
						<< "���������� ��� ���:\n";
					index = Input();
				}

				list->Remove(index);
				Print(list);
				break;
			}
			case 3:
			{
					//TODO: �����(Done)
				CheckListOnCreate(list);

				cout << "������� �������� ��������:\n";
				list->InsertBefore(0, Input());
				Print(list);
				break;
			}
			case 4:
			{
					//TODO: �����(Done)
				CheckListOnCreate(list);

				cout << "������� �������� ��������:\n";
				list->InsertAfter(list->Length - 1, Input());
				Print(list);
				break;
			}
			case 5:
			{
					//TODO: �����(Done)
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				int index = InputIndex();

					//TODO: �����(Done)
				FindCorrectIndex(list, &index);

				int value = InputValue();

				list->InsertAfter(index, value);
				Print(list);
				break;
			}
			case 6:
			{
					//TODO: �����(Done)
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

					//TODO: �����(Done)
				int index = InputIndex();

					//TODO: �����(Done)
				FindCorrectIndex(list, &index);
				//TODO: �����(Done)
				int value = InputValue();

				list->InsertBefore(index, value);
				Print(list);
				break;
			}
			case 7:
			{
				//TODO: �����(Done)
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
					//TODO: �����(Done)
				if (IsListNotCreateOrEmpty(list))
				{
					break;
				}

				cout << "������� �������� ��������:\n";
				int index = list->Search(Input());

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
					//TODO: Naming(Done)
				int count = Input();

				for (int i = 0; i < count; i++)
				{
					list->Add(i);
				}
				int middle = list->Length / 2;
				//TODO: �����(Done)
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
					//TODO: Naming
				int count = Input();

				for (int i = 0; i < count; i++)
				{
					list->Add(i);
				}
				int middle = list->Length / 2;
				//TODO: �����(Done)
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

				isExit = true;
				break;
			}
			default:
			{
				cout << "������ �������� �������, ���������� ��� ���.\n";
				break;
			}
		}
	}
}

//��������, ��� �������� ����� int
int Input()
{
	int input = 0;

	while (true)
	{
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR\n";
		}
		else
		{
			break;
		}
	}

	return input;
}

//��������, ��� ������ �� ������ ��� ����
bool IsListNotCreateOrEmpty(List* list)
{
	if (list == nullptr || list->IsEmpty())
	{
		cout << "������ ����.\n";
		return true;
	}

	return false;
}

//��������, ���� ������ ��� �� ������, �� ���������
void CheckListOnCreate(List* list)
{
	if (list == nullptr)
	{
		list = new List();
	}
}

int InputIndex()
{
	cout << "������� ������ ��������:\n";
	return Input();
}

int InputValue()
{
	cout << "������� �������� ��������:\n";
	return Input();
}

void FindCorrectIndex(List* list, int* index)
{
	while (*index < 0 || *index >= list->Length)
	{
		cout << "�������� � ����� �������� ���, "
			<< "���������� ��� ���:\n";
		*index = Input();
	}
}

//���������� ������� ������ �������
void ShowFunctionRunTime(clock_t begin)
{
	clock_t end = clock();
	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "The time is " << seconds << " seconds.\n";
}