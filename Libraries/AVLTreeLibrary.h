#pragma once

#include <iostream>
#include "..\��� 6 ������� � �������������\��� 6 ������� � �������������\AVLTree.h"

using namespace std;

/*
	������� ��� ���-������
*/

//��������, ��� ���-������ �� ������� ��� ������
bool IsAVLTreeNotCreateOrEmpty(AVLTree* avlTree)
{
	if (avlTree == nullptr || avlTree->IsEmpty())
	{
		cout << "������ ������.\n";
		return true;
	}

	return false;
}

//���������� ������� ������ �������
void ShowFunctionRunTimeAndCountRotate(AVLTree* avlTree, clock_t begin)
{
	clock_t end = clock();

	double seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "����� - " << seconds << " ������;\n";
	cout << "���������� ��������� - " << avlTree->CountRotate
		<< ".\n";
}

//������� count ��������� � ���-������
void InsertCountElement(AVLTree* avlTree, int count)
{
	for (int i = 0; i < count; i++)
	{
		avlTree->Root = avlTree->Insert(avlTree->Root, i);
	}
}

// ����� ������
void Print(AVLTreeNode* node, int level)
{
	if (node != nullptr)
	{
		Print(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "\n";

		Print(node->Left, level + 1);
	}
}