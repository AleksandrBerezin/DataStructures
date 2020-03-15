#include <iostream>
#include "ListNode.h"
#include "List.h"

using namespace std;

// ���������� ��������
void List::Add(int value)
{
	ListNode* node = new ListNode;
	node->Data = value;

	if (Head == nullptr)
	{
		Head = node;
		node->Prev = nullptr;
	}
	else if (Tail == nullptr)
	{
		Tail = node;
		Head->Next = node;
		node->Prev = Head;
	}
	else
	{
		node->Prev = Tail;
		Tail->Next = node;
		Tail = node;
	}

	node->Next = nullptr;
	Length++;
}

// �������� ��������
void List::Remove(int index)
{
	ListNode* node = SearchNode(index);

	if (node->Next != nullptr)
	{
		node->Next->Prev = node->Prev;
	}
	if (node->Prev != nullptr)
	{
		node->Prev->Next = node->Next;
	}

	if (node == Head)
	{
		Head = node->Next;
		if (node->Next == Tail)
		{
			Tail = nullptr;
		}
	}
	else if (node == Tail)
	{
		if (node->Prev != Head)
		{
			Tail = node->Prev;
		}
		else
		{
			Tail = nullptr;
		}
	}

	Length--;
	delete node;
}

// ���������� ������
void List::InsertionSort()
{
	List* newList = new List();
	ListNode* current = Head;

	while (current != nullptr)
	{
		ListNode* min = current;
		ListNode* node = current->Next;

		// ���� ����������� �������
		while (node != nullptr)
		{
			if (node->Data < min->Data)
			{
				min = node;
			}

			node = node->Next;
		}

		// ������� ��� �� ������� ������
		if (min->Next != nullptr)
		{
			min->Next->Prev = min->Prev;
		}
		if (min->Prev != nullptr)
		{
			min->Prev->Next = min->Next;
		}

		if (min == Head)
		{
			Head = min->Next;
		}
		else if (min == Tail)
		{
			Tail = min->Prev;
		}

		// � ��������� ��� � ����� ������
		if (newList->Head == nullptr)
		{
			newList->Head = min;
			min->Prev = nullptr;
		}
		else if (newList->Tail == nullptr)
		{
			newList->Head->Next = min;
			newList->Tail = min;
			min->Prev = newList->Head;
		}
		else
		{
			min->Prev = newList->Tail;
			newList->Tail->Next = min;
			newList->Tail = min;
		}

		min->Next = nullptr;
		current = Head;
	}

	Head = newList->Head;
	Tail = newList->Tail;
	delete newList;
}

// ������� ����� ��������
void List::InsertAfter(int index, int value)
{
	ListNode* node = SearchNode(index);
	ListNode* newNode = new ListNode;
	newNode->Data = value;
	newNode->Prev = node;

	if (node != nullptr)
	{
		newNode->Next = node->Next;
		if (node->Next != nullptr)
		{
			node->Next->Prev = newNode;
		}
		node->Next = newNode;
	}

	if (Head == nullptr)
	{
		Head = newNode;
		newNode->Next = nullptr;
	}
	else if (Tail == nullptr)
	{
		Head->Next = newNode;
		Tail = newNode;
		newNode->Next = nullptr;
	}
	else if (Tail == node)
	{
		Tail = newNode;
	}

	Length++;
}

// ������� ����� ���������
void List::InsertBefore(int index, int value)
{
	ListNode* node = SearchNode(index);
	ListNode* newNode = new ListNode;
	newNode->Data = value;
	newNode->Next = node;

	if (node != nullptr)
	{
		newNode->Prev = node->Prev;
		if (node->Prev != nullptr)
		{
			node->Prev->Next = newNode;
		}
		node->Prev = newNode;
	}

	if (Head == node)
	{
		Head = newNode;
		newNode->Prev = nullptr;

		if (Tail == nullptr)
		{
			Tail = node;
		}
	}

	Length++;
}

// �������� ����� ��������
int List::Search(int value)
{
	ListNode* current = Head;
	int number = 0;

	while (current != nullptr)
	{
		if (current->Data == value)
		{
			return number;
		}

		current = current->Next;
		number++;
	}

	return -1;
}

// ����� ���� �� �������
ListNode* List::SearchNode(int index)
{
	ListNode* current;
	int middle = (Length - 1) / 2;

	if (index <= middle)
	{
		current = Head;

		for (int i = 1; i <= index; i++)
		{
			current = current->Next;
		}
	}
	else
	{
		current = Tail;

		for (int i = Length - 2; i >= index; i--)
		{
			current = current->Prev;
		}
	}

	return current;
}

// ������� ������
void List::Delete()
{
	ListNode* current = Head;
	while (current != nullptr)
	{
		ListNode* node = current;
		current = current->Next;
		delete node;
	}

	Head = nullptr;
	Tail = nullptr;
	Length = 0;
}

// ��������: ������ ������(true) ��� ���(false)
bool List::IsEmpty()
{
	return Length == 0;
}