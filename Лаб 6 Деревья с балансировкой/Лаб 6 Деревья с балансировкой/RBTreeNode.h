#pragma once
struct RBTreeNode
{
	//TODO: ����� ��� �����������?
	int Key;
	bool IsBlack;
	RBTreeNode* Left;
	RBTreeNode* Right;
	RBTreeNode* Parent;
};