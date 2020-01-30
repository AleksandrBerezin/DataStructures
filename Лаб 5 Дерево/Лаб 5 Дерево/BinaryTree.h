#pragma once
struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;	// Корень дерева
	BinaryTreeNode* Find(int key);
	BinaryTreeNode* FindMax();
	BinaryTreeNode* FindMin();
	void Insert(int key);
	void Remove(int key);
	void Clear(BinaryTreeNode* node);
	bool IsEmpty();
};

void Print(BinaryTreeNode* node, int level);