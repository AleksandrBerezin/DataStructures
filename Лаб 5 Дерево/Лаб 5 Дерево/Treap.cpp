#include <iostream>
#include "TreapNode.h"
#include "Treap.h"

using namespace std;

// Поиск узла по ключу
TreapNode* Treap::Find(int key)
{
	TreapNode* node = Root;

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

// Разрезание дерева node по ключу key на два других дерева: left и right,
// причем в left находятся все ключи не больше key, а в right больше
void Treap::Split(TreapNode* node, int key, 
	TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (key >= node->Key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else if (key < node->Key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}

// Слияние двух декартовых деревьев
TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr)
	{
		return right;
	}
	if (right == nullptr)
	{
		return left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

// Неоптимизированное добавление (1 Split, 2 Merge)
void Treap::SlowInsert(int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(Root, key, left, right);

	TreapNode* node = new TreapNode(key);

	left = Merge(left, node);
	Root = Merge(left, right);
}

// Оптимизированное добавление (1 Split)
void Treap::FastInsert(TreapNode* node, TreapNode* parent,
	int key, int priority)
{
	if (node == nullptr)
	{
		node = new TreapNode(key, priority, nullptr, nullptr);

		if (Root == nullptr)
		{
			Root = node;
		}
		else if (parent != nullptr)
		{
			
			node->Key > parent->Key ? parent->Right = node : parent->Left = node;
		}

		return;
	}
	else if (node->Priority < priority)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		Split(node, key, left, right);

		TreapNode* newNode = new TreapNode(key, priority, left, right);
		
		if (parent != nullptr)
		{
			//TODO: Formatting(Done)
			parent->Left == node ? parent->Left = newNode : parent->Right = newNode;
		}
		else
		{
			Root = newNode;
		}

		return;
	}
	else if (key < node->Key)
	{
		return FastInsert(node->Left, node, key, priority);
	}
	else if (key > node->Key)
	{
		return FastInsert(node->Right, node, key, priority);
	}
}

// Неоптимизированное удаление (2 Split, 1 Merge)
void Treap::SlowRemove(int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(Root, key, left, right);

	//TODO: Naming(Done)
	TreapNode* leftTreeWithoutKey = nullptr;	// Левое дерево без key
	TreapNode* treeContainOnlyKey = nullptr;	// Только key
	Split(left, key - 1, leftTreeWithoutKey, treeContainOnlyKey);
	
	if (treeContainOnlyKey == nullptr)
	{
		cout << "Такого элемента нет.\n\n";
		return;
	}

	Root = Merge(leftTreeWithoutKey, right);

	delete treeContainOnlyKey;
}

// Оптимизированное удаление (1 Merge)
void Treap::FastRemove(TreapNode* node, TreapNode* parent, int key)
{
	//TODO: Ответственности
	if (node == nullptr)
	{
		cout << "Такого элемента нет.\n\n";
		return;
	}
	if (key < node->Key)
	{
		return FastRemove(node->Left, node, key);
	}
	else if (key > node->Key)
	{
		return FastRemove(node->Right, node, key);
	}
	else
	{
		TreapNode* newNode = Merge(node->Left, node->Right);
		
		if (parent != nullptr)
		{
			parent->Left == node ? parent->Left = newNode : 
				parent->Right = newNode;
		}
		else
		{
			Root = newNode;
		}
		
		delete node;
		return;
	}
}

// Очистка памяти
void Treap::Clear(TreapNode* node)
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
bool Treap::IsEmpty()
{
	return Root == nullptr;
}

// Вывод дерева на экран
void Print(TreapNode* node, int level)
{
	if (node != nullptr) 
	{
		Print(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "; " << node->Priority << "\n";

		Print(node->Left, level + 1);
	}
}