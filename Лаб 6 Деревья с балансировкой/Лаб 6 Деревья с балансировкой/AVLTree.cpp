#include <iostream>
#include "AVLTreeNode.h"
#include "AVLTree.h"

using namespace std;

// Левый поворот
AVLTreeNode* AVLTree::RotateLeft(AVLTreeNode* node)
{
	AVLTreeNode* newNode = node->Right;
	node->Right = newNode->Left;
	newNode->Left = node;

	node->FixHeight();
	newNode->FixHeight();
	CountRotate++;

	return newNode;
}

// Правый поворот
AVLTreeNode* AVLTree::RotateRight(AVLTreeNode* node)
{
	AVLTreeNode* newNode = node->Left;
	node->Left = newNode->Right;
	newNode->Right = node;

	node->FixHeight();
	newNode->FixHeight();
	CountRotate++;

	return newNode;
}

// Балансировка
AVLTreeNode* AVLTree::Balance(AVLTreeNode* node)
{
	node->FixHeight();

	int balanceFactor = node->CountBalanceFactor();

	if (balanceFactor == -2)
	{
		if (node->Right->CountBalanceFactor() > 0)
		{
			node->Right = RotateRight(node->Right);
		}

		return RotateLeft(node);
	}
	if (balanceFactor == 2)
	{

		if (node->Left->CountBalanceFactor() < 0)
		{
			node->Left = RotateLeft(node->Left);
		}

		return RotateRight(node);
	}
	// Балансировка не нужна
	return node;	
}

// Вставка узла по ключу
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

// Поиск узла по ключу
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

// Поиск узла с минимальным ключом
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

// Удаление узла по ключу
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
	else	// node->Key = key
	{
		// Дочерних узлов нет
		if (node->Left == nullptr && node->Right == nullptr)
		{
			delete node;
			return nullptr;
		}
		// Только правый дочерний узел
		else if (node->Left == nullptr)
		{
			AVLTreeNode* newNode = node->Right;
			delete node;
			return newNode;
		}
		// Только левый дочерний узел
		else if (node->Right == nullptr)
		{
			AVLTreeNode* newNode = node->Left;
			delete node;
			return newNode;
		}
		// Два дочерних узла
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

// Очистка памяти
void AVLTree::Clear(AVLTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	Clear(node->Left);
	Clear(node->Right);

	delete node;
}

// Проверка: пустое дерево(true) или нет(false)
bool AVLTree::IsEmpty()
{
	return Root == nullptr;
}