#include <iostream>
#include <ctime>
#include "TreapNode.h"

// ������������� ���� ����������� ������
void TreapNode::Init(int key)
{
	srand(time(0));

	Key = key;
	// ���������� ������������� ��������� �������� �� 0 �� 99
	Priority = rand() % 100;

	Left = nullptr;
	Right = nullptr;
}