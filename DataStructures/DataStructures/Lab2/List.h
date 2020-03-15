#pragma once
struct List
{
	ListNode* Head;
	ListNode* Tail;
	int Length;

	void Add(int value);
	void Remove(int index);
	void InsertionSort();
	void InsertAfter(int index, int value);
	void InsertBefore(int index, int value);
	int Search(int value);
	ListNode* SearchNode(int index);
	void Delete();
	bool IsEmpty();

	List()
	{
		Head = nullptr;
		Tail = nullptr;
		Length = 0;
	}
};