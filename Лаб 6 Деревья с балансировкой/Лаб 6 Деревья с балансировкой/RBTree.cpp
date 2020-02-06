#include <iostream>
#include "RBTreeNode.h"
#include "RBTree.h"

using namespace std;

// Создание узла
RBTreeNode* RBTree::CreateNode(int key)
{
	RBTreeNode* node = new RBTreeNode();
	node->Key = key;
	node->IsBlack = false;
	node->Left = node->Right = node->Parent = Nil;
	return node;
}

// Левый поворот
void RBTree::RotateLeft(RBTreeNode* node)
{
	RBTreeNode* newNode = node->Right;
	node->Right = newNode->Left;
	if (newNode->Left != Nil)
	{
		newNode->Left->Parent = node;
	}

	newNode->Parent = node->Parent;
	if (node->Parent == Nil)
	{
		Root = newNode;
	}
	else if (node == node->Parent->Left)
	{
		node->Parent->Left = newNode;
	}
	else
	{
		node->Parent->Right = newNode;
	}

	newNode->Left = node;
	node->Parent = newNode;

	CountRotate++;
}

// Правый поворот
void RBTree::RotateRight(RBTreeNode* node)
{
	RBTreeNode* newNode = node->Left;
	node->Left = newNode->Right;
	if (newNode->Right != Nil)
	{
		newNode->Right->Parent = node;
	}

	newNode->Parent = node->Parent;
	if (node->Parent == Nil)
	{
		Root = newNode;
	}
	else if (node == node->Parent->Left)
	{
		node->Parent->Left = newNode;
	}
	else
	{
		node->Parent->Right = newNode;
	}

	newNode->Right = node;
	node->Parent = newNode;

	CountRotate++;
}

// Вставка узла по ключу
void RBTree::Insert(int key)
{
	RBTreeNode* node = CreateNode(key);

	if (IsEmpty())
	{
		Root = node;
	}
	else
	{
		RBTreeNode* current = Root;
		RBTreeNode* parent = Nil;

		// Спускаемся вниз, пока не дойдем до подходящего листа 
		while (current != Nil)	
		{
			parent = current;
			if (node->Key > current->Key)
			{
				current = current->Right;
			}
			else if (node->Key < current->Key)
			{
				current = current->Left;
			}
			else
			{
				return;
			}
		}
		node->Parent = parent;

		node->Key < parent->Key ? parent->Left = node :
			parent->Right = node;
	}

	FixInsertion(node);
}

// Балансировка для операции вставки
void RBTree::FixInsertion(RBTreeNode* node)
{
	if (node == Root)
	{
		node->IsBlack = true;
		return;
	}

	while (node->Parent->IsBlack == false)
	{
		RBTreeNode* parent = node->Parent;
		RBTreeNode* grandpa = parent->Parent;

		if (grandpa == Nil)
		{
			break;
		}

		if (parent == grandpa->Left)
		{
			RBTreeNode* uncle = grandpa->Right;
			
			if (uncle->IsBlack == false)
			{
				parent->IsBlack = true;
				uncle->IsBlack = true;
				grandpa->IsBlack = false;
				node = grandpa;
			}
			else
			{
				if (node == parent->Right)	
				{
					node = parent;
					RotateLeft(node);
				}
				node->Parent->IsBlack = true;
				node->Parent->Parent->IsBlack = false;
				RotateRight(node->Parent->Parent);
			}
		}
		else
		{
			RBTreeNode* uncle = grandpa->Left;

			if (uncle->IsBlack == false)
			{
				parent->IsBlack = true;
				uncle->IsBlack = true;
				grandpa->IsBlack = false;
				node = grandpa;
			}
			else
			{
				if (node == parent->Left)	
				{
					node = parent;
					RotateRight(node);
				}
				node->Parent->IsBlack = true;
				node->Parent->Parent->IsBlack = false;
				RotateLeft(node->Parent->Parent);
			}
		}

		if (node == Root)
		{
			break;
		}
	}

	Root->IsBlack = true;
}

// Поиск узла по ключу
RBTreeNode* RBTree::Find(int key)
{
	RBTreeNode* node = Root;

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

// Удаление узла по ключу
void RBTree::Remove(int key)
{
	RBTreeNode* current = Root;

	while (current->Key != key)
	{
		if (key > current->Key)
		{
			current = current->Right;
		}
		else
		{
			current = current->Left;
		}

		if (current == Nil)
		{
			return;
		}
	}
	
	RBTreeNode* deletedNode;
	// node имеет ребенка Nil 
	if (current->Left == Nil || current->Right == Nil) 
	{
		deletedNode = current;
	}
	else // Ищем потомка с ребенком Nil
	{
		deletedNode = current->Right;
		while (deletedNode->Left != Nil)
		{
			deletedNode = deletedNode->Left;
		}
	}

	RBTreeNode* newNode;
	// newNode - единственный ребенок node
	if (deletedNode->Left != Nil)
	{
		newNode = deletedNode->Left;
	}
	else
	{
		newNode = deletedNode->Right;
	}	

	// Убираем указатели на node
	newNode->Parent = deletedNode->Parent;
	if (deletedNode->Parent != Nil)
	{
		deletedNode->Parent->Left == deletedNode 
			? deletedNode->Parent->Left = newNode 
			: deletedNode->Parent->Right = newNode;
	}	
	else
	{
		Root = newNode;
	}
		
	if (deletedNode != current)
	{
		current->Key = deletedNode->Key;
	}

	if (deletedNode->IsBlack)
	{
		FixRemoving(newNode);
	}
	
	delete deletedNode;
}

// Балансировка для операции удаления
void RBTree::FixRemoving(RBTreeNode* node)
{
	while (node != Root && node->IsBlack == true)
	{
		RBTreeNode* parent = node->Parent;

		if (node == parent->Left)
		{
			RBTreeNode* brother = parent->Right;

			if (brother->IsBlack == false)
			{
				brother->IsBlack = true;
				parent->IsBlack = false;
				RotateLeft(parent);
				brother = parent->Right;
			}
			if (brother->Left->IsBlack && brother->Right->IsBlack)
			{
				brother->IsBlack = false;
				node = node->Parent;
			}
			else
			{
				if (brother->Right->IsBlack == true)
				{
					brother->Left->IsBlack = true;
					brother->IsBlack = false;
					RotateRight(brother);
					brother = parent->Right;
				}

				brother->IsBlack = parent->IsBlack;
				parent->IsBlack = true;
				brother->Right->IsBlack = true;
				RotateLeft(parent);
				node = Root;
			}
		}
		else
		{
			RBTreeNode* brother = parent->Left;
			if (brother->IsBlack == false)
			{
				brother->IsBlack = true;
				parent->IsBlack = false;
				RotateRight(parent);
				brother = parent->Left;
			}
			if (brother->Left->IsBlack && brother->Right->IsBlack)
			{
				brother->IsBlack = false;
				node = node->Parent;
			}
			else
			{
				if (brother->Left->IsBlack == true)
				{
					brother->Right->IsBlack = true;
					brother->IsBlack = false;
					RotateLeft(brother);
					brother = parent->Left;
				}

				brother->IsBlack = parent->IsBlack;
				parent->IsBlack = true;
				brother->Left->IsBlack = true;
				RotateRight(parent);
				node = Root;
			}
		}
	}

	node->IsBlack = true;
}

// Очистка памяти
void RBTree::Clear(RBTreeNode* node)
{
	if (node == Nil)
	{
		return;
	}

	Clear(node->Left);
	Clear(node->Right);

	delete node;
}

// Проверка: пустое дерево(true) или нет(false)
bool RBTree::IsEmpty()
{
	return Root == Nil;
}

// Вывод дерева
void Print(RBTree* rbTree, RBTreeNode* node, int level)
{
	if (node != rbTree->Nil)
	{
		Print(rbTree, node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}

		string color = node->IsBlack ? "B" : "R";
		cout << node->Key << " : " << color <<  "\n";

		Print(rbTree, node->Left, level + 1);
	}
}