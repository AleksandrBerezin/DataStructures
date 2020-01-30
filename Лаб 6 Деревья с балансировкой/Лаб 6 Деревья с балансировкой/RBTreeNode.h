#pragma once
struct RBTreeNode
{
	int Key;
	bool IsBlack;
	RBTreeNode* Left;
	RBTreeNode* Right;
	RBTreeNode* Parent;
};