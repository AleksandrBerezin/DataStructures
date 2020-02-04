#include <iostream>
#include "Constant.h"
#include "Stack.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"
#include "TwoStackQueue.h"

using namespace std;

int Input();

int main()
{
	setlocale(LC_ALL, "Russian");
	//TODO: Ответственности(есть смысл разделить меню на разные файлы)
	Stack* stack = new Stack;
	//TODO: RSDN
	RingBuffer* ringBuf = new RingBuffer;
	RingBufferQueue* ringQueue = new RingBufferQueue;
	TwoStackQueue* stackQueue = new TwoStackQueue;
	//TODO: Naming
	bool exit = false;

	while (!exit)
	{
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. Стек.\n"
			<< "2. Кольцевой буфер.\n"
			<< "3. Очередь на базе кольцевого буфера.\n"
			<< "4. Очередь на базе 2 стеков.\n"
			<< "0. Выход.\n\n";

		int number = Input();
		//TODO: Naming
		bool back = false;
		switch (number)
		{
			case 1:
			{
				while (!back)
				{
					cout << "\nВыберите вариант:\n";
					cout << "1. Добавление элемента в стек.\n"
						<< "2. Извлечение элемента из стека.\n"
						<< "3. Увеличение размера стека.\n"
						<< "4. Удаление стека.\n"
						<< "5. Вывод стека на экран.\n"
						<< "0. Назад.\n\n";

					int variant = Input();
					switch (variant)
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
							int element = Input();
							stack->Push(element);
							Print(stack);
							break;
						}
						case 2:
						{
								//TODO: Дубль
							if (stack == nullptr || stack->IsEmpty())
							{
								cout << "Стек пуст.\n";
								break;
							}

							int element = stack->Pop();
							cout << "Извлекли элемент " << element << "\n";
							Print(stack);
							break;
						}
						case 3:
							if (stack == nullptr)
							{
								cout << "Стек пуст.\n";
								break;
							}

							stack->Resize();
							break;
						case 4:
						//TODO: Дубль
							if (stack == nullptr)
							{
								break;
							}

							stack->Delete();
							delete stack;
							stack = nullptr;
							break;
						case 5:
						//TODO: Дубль
							if (stack == nullptr)
							{
								cout << "Стек пуст.\n";
								break;
							}

							Print(stack);
							break;
						case 0:
							back = true;
							break;
						default:
							cout << "Выбран неверный вариант, попробуйте еще раз.\n";
							break;
					}
				}
				break;
			}
			case 2:
			{
				while (!back)
				{
					cout << "\nВыберите вариант:\n";
					cout << "1. Добавление элемента в буфер.\n"
						<< "2. Извлечение элемента из буфера.\n"
						<< "3. Показать свободное место в буфере.\n"
						<< "4. Показать занятое место в буфере.\n"
						<< "5. Увеличение размера буфера.\n"
						<< "6. Удаление буфера.\n"
						<< "7. Вывод кольцевого буфера на экран.\n"
						<< "0. Назад.\n\n";

					int variant = Input();
					switch (variant)
					{
						case 1:
						{
							if (ringBuf == nullptr)
							{
								ringBuf = new RingBuffer();
							}

							cout << "Введите значение элемента:\n";
							int element = Input();
							ringBuf->Push(element);
							Print(ringBuf);
							break;
						}
						case 2:
						{
							if (ringBuf == nullptr || ringBuf->IsEmpty())
							{
								cout << "Кольцевой буфер пуст.\n";
								break;
							}

							int element = ringBuf->Pop();
							cout << "Извлекли элемент " << element << "\n";
							Print(ringBuf);
							break;
						}
						case 3:
							if (ringBuf == nullptr)
							{
								cout << "Кольцевой буфер пуст.\n";
								break;
							}

							cout << "Свободное место в буфере равно " 
								<< ringBuf->GetFreeSpace() << ".\n";
							break;
						case 4:
							if (ringBuf == nullptr)
							{
								cout << "Кольцевой буфер пуст.\n";
								break;
							}

							cout << "Занятое место в буфере равно "
								<< ringBuf->GetOccupiedSpace() << ".\n";
							break;
						case 5:
							if (ringBuf == nullptr)
							{
								cout << "Кольцевой буфер пуст.\n";
								break;
							}

							ringBuf->Resize();
							break;
						case 6:
							if (ringBuf == nullptr)
							{
								break;
							}

							ringBuf->Delete();
							delete ringBuf;
							ringBuf = nullptr;
							break;
						case 7:
							if (ringBuf == nullptr)
							{
								cout << "Кольцевй буфер пуст.\n";
								break;
							}

							Print(ringBuf);
							break;
						case 0:
							back = true;
							break;
						default:
							cout << "Выбран неверный вариант, попробуйте еще раз.\n";
							break;
					}
				}
				break;
			}
			case 3:
			{
				while (!back)
				{
					cout << "\nВыберите вариант:\n";
					cout << "1. Добавление элемента в очередь.\n"
						<< "2. Извлечение элемента из очереди.\n"
						<< "3. Удаление очереди.\n"
						<< "4. Вывод очереди на экран.\n"
						<< "0. Назад.\n\n";

					int variant = Input();
					switch (variant)
					{
						case 1:
						{
							if (ringQueue == nullptr)
							{
								ringQueue = new RingBufferQueue();
							}

							cout << "Введите значение элемента:\n";
							int element = Input();
							ringQueue->Enqueue(element);
							Print(ringQueue);
							break;
						}
						case 2:
						{
							if (ringQueue == nullptr || ringQueue->IsEmpty())
							{
								cout << "Очередь пустая.\n";
								break;
							}

							int element = ringQueue->Dequeue();
							cout << "Извлекли элемент " << element << "\n";
							Print(ringQueue);
							break;
						}
						case 3:
							if (ringQueue == nullptr)
							{
								break;
							}

							ringQueue->Delete();
							delete ringQueue;
							ringQueue = nullptr;
							break;
						case 4:
							if (ringQueue == nullptr)
							{
								cout << "Очередь пустая.\n";
								break;
							}

							Print(ringQueue);
							break;
						case 0:
							back = true;
							break;
						default:
							cout << "Выбран неверный вариант, попробуйте еще раз.\n";
							break;
					}
				}
				break;
			}
			case 4:
			{
				while (!back)
				{
					cout << "\nВыберите вариант:\n";
					cout << "1. Добавление элемента в очередь.\n"
						<< "2. Извлечение элемента из очереди.\n"
						<< "3. Удаление очереди.\n"
						<< "4. Вывод очереди на экран.\n"
						<< "0. Назад.\n\n";

					int variant = Input();
					switch (variant)
					{
						case 1:
						{
							if (stackQueue == nullptr)
							{
								stackQueue = new TwoStackQueue();
							}

							cout << "Введите значение элемента:\n";
							int element = Input();
							stackQueue->Enqueue(element);
							Print(stackQueue);
							break;
						}
						case 2:
						{
							if (stackQueue == nullptr || stackQueue->IsEmpty())
							{
								cout << "Очередь пустая.\n";
								break;
							}

							int element = stackQueue->Dequeue();
							cout << "Извлекли элемент " << element << "\n";
							Print(stackQueue);
							break;
						}
						case 3:
							if (stackQueue == nullptr)
							{
								break;
							}

							stackQueue->Delete();
							delete stackQueue;
							stackQueue = nullptr;
							break;
						case 4:
							if (stackQueue == nullptr)
							{
								cout << "Очередь пустая.\n";
								break;
							}
							
							Print(stackQueue);
							break;
						case 0:
							back = true;
							break;
						default:
							cout << "Выбран неверный вариант, попробуйте еще раз.\n";
							break;
					}
				}
				break;
			}
			case 0:
				exit = true;

				if (stack != nullptr)
				{
					stack->Delete();
					delete stack;
					stack = nullptr;
				}
				if (ringBuf != nullptr)
				{
					ringBuf->Delete();
					delete ringBuf;
					ringBuf = nullptr;
				}
				if (ringQueue != nullptr)
				{
					ringQueue->Delete();
					delete ringQueue;
					ringQueue = nullptr;
				}
				if (stackQueue != nullptr)
				{
					stackQueue->Delete();
					delete stackQueue;
					stackQueue = nullptr;
				}

				break;
			default:
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
		}
	}
}

//Проверка, что вводимое число int
int Input()
{
	int a = 0;

	while (true)
	{
		cin >> a;
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

	return a;
}