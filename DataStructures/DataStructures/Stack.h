#pragma once
#include "StackNode.h"
#include "ConstantLab3.h"

struct Stack
{
	StackNode* TopElement;
	int Size;
	int CurrentLength;

	void Push(int element);
	int Pop();
	void Resize();
	bool IsEmpty();
	void Delete();

	Stack()
	{
		Size = bufferSize;
		TopElement = nullptr;
		CurrentLength = 0;
	}
};