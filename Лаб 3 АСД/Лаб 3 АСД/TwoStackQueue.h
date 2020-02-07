#pragma once
#include "Stack.h"

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