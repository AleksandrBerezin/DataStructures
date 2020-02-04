#pragma once
struct Treap
{//TODO: Зачем эти комментарии?
	TreapNode* Root = nullptr;	// Корень дерева
	TreapNode* Find(int key);
	void Split(TreapNode* node, int key, 
		TreapNode*& left, TreapNode*& right);
	TreapNode* Merge(TreapNode* left, TreapNode* right);
	void SlowInsert(int key);
	void FastInsert(TreapNode* node, TreapNode* parent,
		int key, int priority);
	void SlowRemove(int key);
	void FastRemove(TreapNode* node, TreapNode* parent, int key);
	void Clear(TreapNode* node);
	bool IsEmpty();
};

void Print(TreapNode* node, int level);