#pragma once
struct List
{
	Node* Head;
	Node* Tail;
	int Length;

	void Add(int value);
	void Remove(int index);
	//TODO: Naming
	void Sort();
	void InsertAfter(int index, int value);
	void InsertBefore(int index, int value);
	int Search(int value);
	Node* SearchNode(int index);
	void Delete();

	List()
	{
		Head = nullptr;
		Tail = nullptr;
		Length = 0;
	}
};

void Print(List* list);