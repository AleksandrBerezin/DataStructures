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

	if (IsEmpty())	// Дерево пустое
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

	RBTreeNode* parent;
	RBTreeNode* grandpa;
	RBTreeNode* uncle;

	while (node->Parent->IsBlack == false)	// Отец красный
	{
		parent = node->Parent;
		grandpa = parent->Parent;

		if (grandpa == Nil)
		{
			break;
		}

		// Отец является левым ребенком
		if (parent == grandpa->Left)
		{
			uncle = grandpa->Right;

			if (uncle->IsBlack == false)	// Дядя красный
			{
				parent->IsBlack = true;
				uncle->IsBlack = true;
				grandpa->IsBlack = false;
				node = grandpa;
			}
			else	// Дядя черный
			{
				// Узел является правым ребенком, отец и сын с разных сторон
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
		// Отец является правым ребенком
		else
		{
			uncle = grandpa->Left;

			if (uncle->IsBlack == false)	// Дядя красный
			{
				parent->IsBlack = true;
				uncle->IsBlack = true;
				grandpa->IsBlack = false;
				node = grandpa;
			}
			else	// Дядя черный
			{
				// Узел является левым ребенком, отец и сын в разных сторонах
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
	RBTreeNode* node;	// Удаляем
	RBTreeNode* newNode;	// Ставим на его место

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
	
	// node имеет ребенка Nil 
	if (current->Left == Nil || current->Right == Nil) 
	{
		node = current;
	}
	else // Ищем потомка с ребенком Nil
	{
		node = current->Right;
		while (node->Left != Nil)
		{
			node = node->Left;
		}
	}

	// newNode - единственный ребенок node
	if (node->Left != Nil)
	{
		newNode = node->Left;
	}
	else
	{
		newNode = node->Right;
	}	

	// Убираем указатели на node
	newNode->Parent = node->Parent;
	if (node->Parent != Nil)
	{
		node->Parent->Left == node ? node->Parent->Left = newNode :
			node->Parent->Right = newNode;
	}	
	else
	{
		Root = newNode;
	}
		
	if (node != current)
	{
		current->Key = node->Key;
	}

	if (node->IsBlack)
	{
		FixRemoving(newNode);
	}
	
	delete node;
}

// Балансировка для операции удаления
void RBTree::FixRemoving(RBTreeNode* node)
{
	while (node != Root && node->IsBlack == true)
	{
		RBTreeNode* brother;
		RBTreeNode* parent = node->Parent;

		if (node == parent->Left)	// Узел является левым ребенком
		{
			brother = parent->Right;
			if (brother->IsBlack == false)
			{
				brother->IsBlack = true;
				parent->IsBlack = false;
				RotateLeft(parent);
				brother = parent->Right;
			}
			// Брат с черными детьми
			if (brother->Left->IsBlack && brother->Right->IsBlack)
			{
				brother->IsBlack = false;
				node = node->Parent;
			}
			else
			{
				// Брат с черным правым ребенком
				if (brother->Right->IsBlack == true)
				{
					brother->Left->IsBlack = true;
					brother->IsBlack = false;
					RotateRight(brother);
					brother = parent->Right;
				}

				// Брат с красным правым ребенком
				brother->IsBlack = parent->IsBlack;
				parent->IsBlack = true;
				brother->Right->IsBlack = true;
				RotateLeft(parent);
				node = Root;
			}
		}
		else	// Узел является правым ребенком
		{
			brother = parent->Left;
			if (brother->IsBlack == false)
			{
				brother->IsBlack = true;
				parent->IsBlack = false;
				RotateRight(parent);
				brother = parent->Left;
			}
			// Брат с черными детьми
			if (brother->Left->IsBlack && brother->Right->IsBlack)
			{
				brother->IsBlack = false;
				node = node->Parent;
			}
			else
			{
				// Брат с черным левым ребенком
				if (brother->Left->IsBlack == true)
				{
					brother->Right->IsBlack = true;
					brother->IsBlack = false;
					RotateLeft(brother);
					brother = parent->Left;
				}

				// Брат с красным левым ребенком
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