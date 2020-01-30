#pragma once
struct BinaryTreeNode
{
	int Key;	//  люч
	BinaryTreeNode* Left;	// ”казатель на левое поддерево
	BinaryTreeNode* Right;	// ”казатель на правое поддерево

	BinaryTreeNode(int key) 
	{
		Key = key;
		Left = nullptr;
		Right = nullptr;
	}
};