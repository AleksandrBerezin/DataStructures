#pragma once

#include <iostream>
#include "..\��� 6 ������� � �������������\��� 6 ������� � �������������\RBTree.h"

using namespace std;

/*
	������� ��� ������-������� ������
*/

//��������, ��� ������-������ ������ �� ������� ��� ������
bool IsRBTreeNotCreateOrEmpty(RBTree* rbTree)
{
	if (rbTree == nullptr || rbTree->IsEmpty())
	{
		cout << "������ ������.\n";
		return true;
	}

	return false;
}

//���������� ������� ������ �������
void ShowFunctionRunTimeAndCountRotate(RBTree* rbTree, clock_t begin)
{
	clock_t end = clock();

	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "����� - " << seconds << " ������;\n";
	cout << "���������� ��������� - " << rbTree->CountRotate
		<< ".\n";
}

//������� count ��������� � ������-������ ������
void InsertCountElement(RBTree* rbTree, int count)
{
	for (int i = 0; i < count; i++)
	{
		rbTree->Insert(i);
	}
}

// ����� ������
void Print(RBTree* rbTree, RBTreeNode* node, int level)
{
	if (node != rbTree->Nil)
	{
		Print(rbTree, node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}

		string color = node->IsBlack ? "B" : "R";
		cout << node->Key << " : " << color << "\n";

		Print(rbTree, node->Left, level + 1);
	}
}