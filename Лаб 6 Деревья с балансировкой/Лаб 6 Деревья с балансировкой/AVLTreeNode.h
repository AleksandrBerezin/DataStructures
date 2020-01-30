#pragma once
struct AVLTreeNode
{
	int Key;	// Ключ узла
	unsigned char Height;	// Высота поддерева с корнем в данном узле
	AVLTreeNode* Left;	// Указатель на левое поддерево
	AVLTreeNode* Right;	// Указатель на правое поддерево

	int BalanceFactor();
	void FixHeight();

	AVLTreeNode(int key)
	{
		Key = key;
		Height = 1;
		Left = Right = nullptr;
	}
};