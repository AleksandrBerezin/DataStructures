#pragma once
#include <ctime>
struct TreapNode
{
	int Key;	// ����
	int Priority;	// ���������

	TreapNode* Left;	// ��������� �� ����� ���������
	TreapNode* Right;	// ��������� �� ������ ���������

	TreapNode(int key)
	{
		srand(time(0));

		Key = key;
		// ���������� ������������� ��������� �������� �� 0 �� 99
		Priority = rand() % 100;

		Left = nullptr;
		Right = nullptr;
	}

	TreapNode(int key, int priority, TreapNode* left, TreapNode* right)
	{
		Key = key;
		Priority = priority;
		Left = left;
		Right = right;
	}
};