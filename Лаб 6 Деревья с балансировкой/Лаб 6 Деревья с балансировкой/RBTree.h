#pragma once
struct RBTree
{
	RBTreeNode* Root;
	RBTreeNode* Nil;

	RBTreeNode* CreateNode(int key);
	void RotateLeft(RBTreeNode* node);
	void RotateRight(RBTreeNode* node);
	void Insert(int key);
	void FixInsertion(RBTreeNode* node);
	RBTreeNode* Find(int key);
	void Remove(int key);
	void FixRemoving(RBTreeNode* node);
	bool IsEmpty();

	RBTree()
	{
		Nil = new RBTreeNode();
		Nil->IsBlack = true;
		Root = Nil;
	}
};

void Print(RBTree* rbTree, RBTreeNode* node, int level);