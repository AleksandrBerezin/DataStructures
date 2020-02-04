#pragma once
struct RBTreeNode
{
	//TODO: Зачем эти комментарии?
	int Key;
	bool IsBlack;
	RBTreeNode* Left;
	RBTreeNode* Right;
	RBTreeNode* Parent;
};