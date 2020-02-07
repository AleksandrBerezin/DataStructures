#pragma once
#include "BinaryTreeNode.h"

struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;
	BinaryTreeNode* Find(int key);
	BinaryTreeNode* FindMax();
	BinaryTreeNode* FindMin();
	void Insert(int key);
	void Remove(int key);
	void Clear(BinaryTreeNode* node);
	bool IsEmpty();
};