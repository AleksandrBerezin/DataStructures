#include "AVLTreeNode.h"

// Вычисление balance factor(разность высот поддеревьев) заданного узла
int AVLTreeNode::CountBalanceFactor()
{
	if (Left == nullptr && Right == nullptr)
	{
		return 0;
	}
	else if (Left == nullptr)
	{
		return - (Right->Height);
	}
	else if (Right == nullptr)
	{
		return Left->Height;
	}
	else
	{
		return Left->Height - Right->Height;
	}
}

// Восстанавление корректного значение поля Height заданного узла
void AVLTreeNode::FixHeight()
{
	if (Left == nullptr && Right == nullptr)
	{
		Height = 1;
	}
	else if (Left == nullptr)
	{
		Height = Right->Height + 1;
	}
	else if (Right == nullptr)
	{
		Height = Left->Height + 1;
	}
	else
	{
		Height = Left->Height > Right->Height 
			? Left->Height + 1 
			: Right->Height + 1;
	}
}