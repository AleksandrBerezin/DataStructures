#pragma once
#include <ctime>
struct TreapNode
{
	//TODO: ����� ��� �����������?
	int Key;	// ����
	int Priority;	// ���������

	TreapNode* Left;	// ��������� �� ����� ���������
	TreapNode* Right;	// ��������� �� ������ ���������

	TreapNode(int key)
	{
		//TODO: nullptr
		srand(time(0));

		Key = key;
		//TODO: ����� ��� �����������?
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