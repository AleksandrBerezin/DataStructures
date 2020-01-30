#include "BinaryTreeNode.h"

// Инициализация узла бинарного дерева
void BinaryTreeNode::Init(int key)
{
	Key = key;
	Left = nullptr;
	Right = nullptr;
	Parent = nullptr;
}