#pragma once
struct BinaryTreeNode
{
	//TODO: Зачем эти комментарии?
	int Key;	// Ключ
	BinaryTreeNode* Left;	// Указатель на левое поддерево
	BinaryTreeNode* Right;	// Указатель на правое поддерево

	BinaryTreeNode(int key) 
	{
		Key = key;
		Left = nullptr;
		Right = nullptr;
	}
};