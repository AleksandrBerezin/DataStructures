#pragma once
struct AVLTreeNode
{
	//TODO: ����� ��� �����������?
	int Key;	// ���� ����
	unsigned char Height;	// ������ ��������� � ������ � ������ ����
	AVLTreeNode* Left;	// ��������� �� ����� ���������
	AVLTreeNode* Right;	// ��������� �� ������ ���������

	int BalanceFactor();
	void FixHeight();

	AVLTreeNode(int key)
	{
		Key = key;
		Height = 1;
		Left = Right = nullptr;
	}
};