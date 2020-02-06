#pragma once
struct AVLTreeNode
{
	int Key;
	unsigned char Height;
	AVLTreeNode* Left;
	AVLTreeNode* Right;

	int CountBalanceFactor();
	void FixHeight();

	AVLTreeNode(int key)
	{
		Key = key;
		Height = 1;
		Left = Right = nullptr;
	}
};