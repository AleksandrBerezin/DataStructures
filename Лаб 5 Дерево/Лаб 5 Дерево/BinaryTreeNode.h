#pragma once
struct BinaryTreeNode
{
	//TODO: ����� ��� �����������?
	int Key;	// ����
	BinaryTreeNode* Left;	// ��������� �� ����� ���������
	BinaryTreeNode* Right;	// ��������� �� ������ ���������

	BinaryTreeNode(int key) 
	{
		Key = key;
		Left = nullptr;
		Right = nullptr;
	}
};