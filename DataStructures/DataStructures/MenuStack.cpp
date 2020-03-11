#include <iostream>
#include "Stack.h"
#include "MenuStack.h"
#include "CommonLibrary.h"
#include "StackLibrary.h"

using namespace std;

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

		switch (InputInt())
		{
			case 1:
			{

				if (stack == nullptr)
				{
					stack = new Stack();
				}

				if (stack->CurrentLength == stack->Size)
				{
					cout << "���� ����������.\n";
					break;
				}

				int value = InputIntValue();
				stack->Push(value);
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