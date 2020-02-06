#pragma once
#include "StackNode.h"
#include "Constant.h"

struct Stack
{
	StackNode* TopElement; 
	//TODO: naming(Done)
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

void Print(Stack* stack);