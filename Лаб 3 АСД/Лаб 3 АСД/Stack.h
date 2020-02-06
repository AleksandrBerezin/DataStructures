#pragma once
#include "StackNode.h"
#include "Constant.h"

struct Stack
{
	StackNode* TopElement; 
	//TODO: naming
	int Size;			
	int Length;			

	void Push(int element);
	int Pop();
	void Resize();
	bool IsEmpty();
	void Delete();

	Stack()
	{
		Size = bufferSize;
		TopElement = nullptr;
		Length = 0;
	}
};

void Print(Stack* stack);