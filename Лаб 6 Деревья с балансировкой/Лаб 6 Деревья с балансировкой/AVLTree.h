#pragma once
struct AVLTree
{
	AVLTreeNode* Root = nullptr;

	AVLTreeNode* RotateLeft(AVLTreeNode* node);
	AVLTreeNode* RotateRight(AVLTreeNode* node);
	AVLTreeNode* Balance(AVLTreeNode* node);
	AVLTreeNode* Insert(AVLTreeNode* node, int key);
	AVLTreeNode* Find(int key);
	AVLTreeNode* FindMin();
	AVLTreeNode* Remove(AVLTreeNode* node, int key);
	bool IsEmpty();
};

void Print(AVLTreeNode* node, int level);