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
		cout << "\nВыберите вариант:\n";
		cout << "1. Добавление элемента в стек.\n"
			<< "2. Извлечение элемента из стека.\n"
			<< "3. Увеличение размера стека.\n"
			<< "4. Удаление стека.\n"
			<< "5. Вывод стека на экран.\n"
			<< "0. Назад.\n\n";

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
					cout << "Стек переполнен.\n";
					break;
				}

				cout << "Введите значение элемента:\n";
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
				cout << "Извлекли элемент " << element << "\n";
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
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
			}
		}
	}

	return;
}

//Проверка, что стек не создан или пуст
bool IsStackNotCreateOrEmpty(Stack* stack)
{
	if (stack == nullptr || stack->IsEmpty())
	{
		cout << "Стек пуст.\n";
		return true;
	}

	return false;
}

//Проверка, что стек не создан
bool IsStackNotCreate(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "Стек пуст.\n";
		return true;
	}

	return false;
}