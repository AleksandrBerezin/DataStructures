#include <iostream>
#include "Stack.h"
#include "MenuStack.h"
#include "Functions.h"

using namespace std;

bool IsStackNotCreateOrEmpty(Stack* stack);
bool IsStackNotCreate(Stack* stack);

void Menu(Stack*& stack)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� �������� � ����.\n"
			<< "2. ���������� �������� �� �����.\n"
			<< "3. ���������� ������� �����.\n"
			<< "4. �������� �����.\n"
			<< "5. ����� ����� �� �����.\n"
			<< "0. �����.\n\n";

		switch (Input())
		{
			case 1:
			{

				if (stack == nullptr)
				{
					stack = new Stack();
				}

				if (stack->Length == stack->Size)
				{
					cout << "���� ����������.\n";
					break;
				}

				cout << "������� �������� ��������:\n";
				stack->Push(Input());
				Print(stack);
				break;
			}
			case 2:
			{
				if (IsStackNotCreateOrEmpty(stack))
				{
					break;
				}

				int element = stack->Pop();
				cout << "�������� ������� " << element << "\n";
				Print(stack);
				break;
			}
			case 3:
				if (IsStackNotCreate(stack))
				{
					break;
				}

				stack->Resize();
				break;
			case 4:
			{
				if (IsStackNotCreate(stack))
				{
					break;
				}

				stack->Delete();
				delete stack;
				stack = nullptr;
				break;
			}
			case 5:
			{
				if (IsStackNotCreate(stack))
				{
					break;
				}

				Print(stack);
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
bool IsStackNotCreateOrEmpty(Stack* stack)
{
	if (stack == nullptr || stack->IsEmpty())
	{
		cout << "���� ����.\n";
		return true;
	}

	return false;
}

//��������, ��� ���� �� ������
bool IsStackNotCreate(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "���� ����.\n";
		return true;
	}

	return false;
}