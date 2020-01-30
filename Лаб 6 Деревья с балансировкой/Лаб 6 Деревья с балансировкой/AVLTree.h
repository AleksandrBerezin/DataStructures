#pragma once
struct AVLTree
{
	AVLTreeNode* Root = nullptr;
	int CountRotate = 0;

	AVLTreeNode* RotateLeft(AVLTreeNode* node);
	AVLTreeNode* RotateRight(AVLTreeNode* node);
	AVLTreeNode* Balance(AVLTreeNode* node);
	AVLTreeNode* Insert(AVLTreeNode* node, int key);
	AVLTreeNode* Find(int key);
	AVLTreeNode* FindMin();
	AVLTreeNode* Remove(AVLTreeNode* node, int key);
	void Clear(AVLTreeNode* node);
	bool IsEmpty();
};

void Print(AVLTreeNode* node, int level);