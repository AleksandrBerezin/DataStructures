#pragma once
struct TwoStackQueue
{
	Stack* InputStack;
	Stack* OutputStack;

	void Enqueue(int element);
	int Dequeue();
	bool IsEmpty();
	void Delete();

	TwoStackQueue()
	{
		InputStack = new Stack();
		OutputStack = new Stack();
	}
};

void Print(TwoStackQueue* stackQueue);