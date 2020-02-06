#include <iostream>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"

using namespace std;

// Поиск узла по ключам
BinaryTreeNode* BinaryTree::Find(int key)
{
	BinaryTreeNode* node = Root;

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

// Поиск узла с максимальным ключом
BinaryTreeNode* BinaryTree::FindMax()
{
	if (Root == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode* tmpNode = Root;
	while (tmpNode->Right != nullptr)
	{
		tmpNode = tmpNode->Right;
	}

	return tmpNode;
}

// Поиск узла с минимальным ключом
BinaryTreeNode* BinaryTree::FindMin()
{
	if (Root == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode* tmpNode = Root;
	while (tmpNode->Left != nullptr)
	{
		tmpNode = tmpNode->Left;
	}

	return tmpNode;
}

// Добавление узла по ключу
void BinaryTree::Insert(int key)
{
	BinaryTreeNode* node = Root;

	while (node != nullptr)
	{
		if (key < node->Key && node->Left != nullptr)
		{
			node = node->Left;
		}
		else if (key < node->Key)
		{
			node->Left = new BinaryTreeNode(key);
			break;
		}
		else if (key > node->Key && node->Right != nullptr)
		{
			node = node->Right;
		}
		else if (key > node->Key)
		{
			node->Right = new BinaryTreeNode(key);
			break;
		}
		else
		{
			cout << "Элемент с таким ключом присутствует в дереве.\n\n";
			return;
		}
	}

	node = new BinaryTreeNode(key);

	if (Root == nullptr)
	{
		Root = node;
	}
}

// Удаление узла по ключу
void BinaryTree::Remove(int key)
{
	BinaryTreeNode* node = Root;
	BinaryTreeNode* parent = nullptr;

	while (node != nullptr)
	{
		if (key < node->Key)
		{
			parent = node;
			node = node->Left;
		}
		else if (key > node->Key)
		{
			parent = node;
			node = node->Right;
		}
		else
		{
			// Дочерних узлов нет
			if (node->Left == nullptr && node->Right == nullptr)
			{
				if (parent != nullptr)
				{
					parent->Left == node 
						? parent->Left = nullptr 
						: parent->Right = nullptr;
				}
				else
				{
					Root = nullptr;
				}

				delete node;
				return;
			}
			// Только левый дочерний узел
			else if (node->Left != nullptr && node->Right == nullptr)
			{
				BinaryTreeNode* oldNode = node;
				node = node->Left;

				if (parent != nullptr)
				{
					parent->Left == oldNode 
						? parent->Left = node 
						: parent->Right = node;
				}
				else
				{
					Root = node;
				}

				delete oldNode;
				return;
			}
			// Только правый дочерний узел
			else if (node->Right != nullptr && node->Left == nullptr)
			{
				BinaryTreeNode* oldNode = node;
				node = node->Right;

				if (parent != nullptr)
				{
					parent->Left == oldNode 
						? parent->Left = node 
						: parent->Right = node;
				}
				else
				{
					Root = node;
				}

				delete oldNode;
				return;
			}
			// Два дочерних узла
			else
			{
				BinaryTreeNode* oldNode = node;
				BinaryTree* tmpTree = new BinaryTree();
				tmpTree->Root = oldNode->Right;

				node = tmpTree->FindMin();
				int min = node->Key;

				Remove(min);

				oldNode->Key = min;
				delete tmpTree;
				return;
			}
		}
	}

	if (node == nullptr)
	{
		cout << "Такого элемента нет.";
		return;
	}
}

// Очистка памяти
void BinaryTree::Clear(BinaryTreeNode* node)
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
bool BinaryTree::IsEmpty()
{
	return Root == nullptr;
}

// Вывод дерева
void Print(BinaryTreeNode* node, int level)
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