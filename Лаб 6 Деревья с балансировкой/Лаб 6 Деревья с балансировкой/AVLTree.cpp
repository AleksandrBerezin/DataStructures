#include <iostream>
#include "AVLTreeNode.h"
#include "AVLTree.h"

using namespace std;

AVLTreeNode* AVLTree::RotateLeft(AVLTreeNode* node)
{
	AVLTreeNode* newNode = node->Right;
	node->Right = newNode->Left;
	newNode->Left = node;

	node->FixHeight();
	newNode->FixHeight();

	return newNode;
}

AVLTreeNode* AVLTree::RotateRight(AVLTreeNode* node)
{
	AVLTreeNode* newNode = node->Left;
	node->Left = newNode->Right;
	newNode->Right = node;

	node->FixHeight();
	newNode->FixHeight();

	return newNode;
}

AVLTreeNode* AVLTree::Balance(AVLTreeNode* node)
{
	node->FixHeight();

	int balenceFactor = node->BalanceFactor();

	if (balenceFactor == -2)
	{
		if (node->Right->BalanceFactor() > 0)
		{
			node->Right = RotateRight(node->Right);
		}

		return RotateLeft(node);
	}
	if (balenceFactor == 2)
	{

		if (node->Left->BalanceFactor() < 0)
		{
			node->Left = RotateLeft(node->Left);
		}

		return RotateRight(node);
	}

	return node;
}

AVLTreeNode* AVLTree::Insert(AVLTreeNode* node, int key)
{
	if (node == nullptr)
	{
		return new AVLTreeNode(key);
	}
	if (key < node->Key)
	{
		node->Left = Insert(node->Left, key);
		return Balance(node);
	}
	else if (key > node->Key)
	{
		node->Right = Insert(node->Right, key);
		return Balance(node);
	}
}

AVLTreeNode* AVLTree::Find(int key)
{
	AVLTreeNode* node = Root;

	while (node != nullptr)
	{
		if (node->Key == key)
		{
			break;
		}
		if (key < node->Key)
		{
			node = node->Left;
		}
		else
		{
			node = node->Right;
		}
	}

	return node;
}

AVLTreeNode* AVLTree::FindMin()
{
	if (Root == nullptr)
	{
		return nullptr;
	}

	AVLTreeNode* tmpNode = Root;
	while (tmpNode->Left != nullptr)
	{
		tmpNode = tmpNode->Left;
	}

	return tmpNode;
}

AVLTreeNode* AVLTree::Remove(AVLTreeNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (key < node->Key)
	{
		node->Left = Remove(node->Left, key);
		return Balance(node);
	}
	else if (key > node->Key)
	{
		node->Right = Remove(node->Right, key);
		return Balance(node);
	}
	else
	{
		if (node->Left == nullptr && node->Right == nullptr)
		{
			delete node;
			return nullptr;
		}
		else if (node->Left == nullptr)
		{
			AVLTreeNode* newNode = node->Right;
			delete node;
			return newNode;
		}
		else if (node->Right == nullptr)
		{
			AVLTreeNode* newNode = node->Left;
			delete node;
			return newNode;
		}
		else
		{
			AVLTreeNode* oldNode = node;
			AVLTree* tmpTree = new AVLTree;
			tmpTree->Root = oldNode->Right;

			node = tmpTree->FindMin();
			int min = node->Key;

			oldNode = Remove(oldNode, min);
			oldNode->Key = min;

			delete tmpTree;
			return oldNode;
		}
	}
}

bool AVLTree::IsEmpty()
{
	return Root == nullptr;
}

void Print(AVLTreeNode* node, int level)
{
	if (node != nullptr)
	{
		Print(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "\n";

		Print(node->Left, level + 1);
	}
}