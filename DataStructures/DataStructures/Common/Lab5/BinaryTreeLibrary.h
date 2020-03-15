#pragma once

#include <iostream>
#include "../../Lab5/BinaryTree.h"

using namespace std;

/*
	������� ��� ��������� ������
*/

//��������, ��� �������� ������ �� ������� ��� ����
bool IsBinaryTreeNotCreateOrEmpty(BinaryTree* binaryTree)
{
	if (binaryTree == nullptr || binaryTree->IsEmpty())
	{
		cout << "������ ������.\n";
		return true;
	}

	return false;
}

// ����� ������
void Print(BinaryTreeNode* node, int level)
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